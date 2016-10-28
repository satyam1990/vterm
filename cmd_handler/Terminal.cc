/******************************************************************************
 *
 * Terminal.cc
 *
 * Author: mSatyam
 *
 * 2016, September
 *
 * Represents our virtual terminal which accepts user input in non-canonical 
 * mode , processes it and displays desired output to the user.
 *
 * ***************************************************************************/

#include "Terminal.hh"

// initializes required stuff for our terminal
Terminal::Terminal(string mo_xml_file)
{
	
	// set xml file name
	xmlFile = mo_xml_file;

	// store the initial terminal settings
	tcgetattr(fileno(stdin), &initial_settings);

	// make empty strings
	command = "";

	//config mode off by default
	aplocMode = false;

	// exit command false by default
	isExitCommand = false;

	// init APLOCProcessor
	aplocProcessor = new APLOCProcessor(xmlFile);

	// init MMLProcessor
	mmlProcessor = new MMLProcessor();

}

Terminal::~Terminal()
{
	// free up the aploc and mml processor objects
	delete aplocProcessor;
	delete mmlProcessor;
}

// logins the user to the NODE
bool Terminal::login()
{
	string usercode, password;

	// Ask for USERCODE
	cout << "USERCODE: ";
	getline(cin, usercode);

	// clean up the string
	Helper::stripSpace(usercode);

	// Ask for password
	cout << "Password: ";
	getline(cin, password);
	
	// clean up the string
	Helper::stripSpace(password);

	// validate and send header plus MML prompt
	// also set the prompt value
	if (usercode.compare("abc") == 0 &&
		password.compare("abc") == 0)
	{
		cout << mmlProcessor->getDefaultPrompt();
	}
	// exit if invalid login
	else
	{
		cerr << "Invalid Login" << endl;
		return false;
	}

	// set terminal to non-canonical mode
	setTerminalAttributes();

	return true;
}

// main loop of our terminal which keeps on accepting user input
// processes it and displays desired results
void Terminal::main()
{
	char ch = '\0';

	// main loop
	while (isExitCommand != true)
	{
		// read character
		ch = getchar();

		// ignore characters below BACKSPACE
		if (ch < BACKSPACE)
		{
			continue;
		}

		// process user input
		processInput(ch);
	}

	// reset terminal attributes before exiting
	resetTerminalAttributes();
}

// each input character is forwarded here for processing
// then this function further decides what other input
// processing functions to call
void Terminal::processInput(char c)
{
	// switch on character
	switch(c)
	{
		// backspace pressed
		case BACKSPACE:
		case DELETE:
			processBackspace();
			break;
		
		// tab pressed
		case TAB:
			if (aplocMode)
			{
				command += c;
				processCommand();
			}
			break;

		// enter  pressed
		case ENTER:
			processCommand();
			
			// clean up the command
			setCommand("");
			break;

		// default
		default:
			// append character to command string
			command += c;
			// we need to manually display characters
			// to the user as we have made echo off in terminal
			// attributes.
			cout << c << flush;
	}
}

// sends command for processing to respective processor
// and gets the output
void Terminal::processCommand()
{
	if (aplocMode)
	{
		APLOCResponse resp = aplocProcessor->getResponse(getCommand());
		
		// process and display response
		processAndDisplay(resp);
	}
	else
	{
		MMLResponse resp = mmlProcessor->getResponse(getCommand());

		// process and display response
		processAndDisplay(resp);
	}
}

// processes response and displays output if any for MML commands
void Terminal::processAndDisplay(MMLResponse resp)
{
	if (resp.doExit() && aplocMode == false)
		isExitCommand = true;

	// shift from MML to APLOC mode
	if (resp.isModeChanged())
	{
		aplocMode = true;
		cout << endl << aplocProcessor->getDefaultPrompt();
		return;
	}

	// print output if available
	if (resp.getOutput() != "")
		cout << endl << resp.getOutput();

	// print the prompt
	cout << endl << resp.getPrompt();
}

// processes response and displays output if any for APLOC commands
void Terminal::processAndDisplay(APLOCResponse resp)
{
	// exit from APLOC mode and shift to MML mode
	if (resp.doExit())
	{
		aplocMode = false;
		cout << endl << mmlProcessor->getDefaultPrompt();
		return;
	}

	// update the terminal command with autocompleted command (if any)
	setCommand(resp.getAutoCompletedCommand());

	if (resp.isAutoCompleted())
	{
		cout << CR << resp.getPrompt() << getCommand();
		return;
	}

	// print output if available
	if (resp.getOutput() != "")
	{
		cout << endl << resp.getOutput();
	}

	// print the prompt
	cout << endl << resp.getPrompt() << resp.getAutoCompletedCommand();
}

// removes one character from the end from our command when backspace 
// key is pressed
void Terminal::processBackspace()
{
	// remove one character from the prompt if typed
	// and update the command accordingly
	if (command.length() > 0)
	{
		command = command.substr(0, command.length() - 1);
	
		// update the terminal
		cout << '\b' << ' ' << '\b' << flush;
	}
}

// sets the terminal in non-canonical mode
void Terminal::setTerminalAttributes()
{
	// get the initial attributes
	struct termios new_settings = initial_settings;

	// set the new attributes for non-canonical mode
	new_settings.c_lflag &= ~(ICANON | ECHO);
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;

	// set it
	if (tcsetattr(fileno(stdin), TCSAFLUSH, &new_settings))
	{
		cerr << "Error Setting Terminal Attributes:" << endl;

		if (errno == ENOTTY)
		{
			cerr << "Not a terminal." << endl;
		}
	}
}

// resets the terminal to its original state
void Terminal::resetTerminalAttributes()
{
	// set the terminal settings back to canonical mode
	 tcsetattr(fileno(stdin), TCSAFLUSH, &initial_settings);
}

// gets the command entered by user
string Terminal::getCommand()
{
    return command;
}

// set the command programatically if required
void Terminal::setCommand(string cmd)
{
	command = cmd;
}

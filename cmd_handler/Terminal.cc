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
				processCommand();
			break;

		// enter  pressed
		case ENTER:
			processCommand();
			// display newline character
			cout << endl;
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
    Response resp;

	if (aplocMode)
	{
		resp = aplocProcessor->getResponse(getCommand());
	}
	else
	{
		resp = mmlProcessor->getResponse(getCommand());
	}

	// process and display response
	processAndDisplay(resp);
}

// processes response and displays output if any
void Terminal::processAndDisplay(Response resp)
{
	if (resp.doExit() && aplocMode == false)
		isExitCommand = true;
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

string Terminal::getCommand()
{
    return command;
}

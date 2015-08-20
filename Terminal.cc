/******************************************************************************
 *
 * Terminal.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * Represents our virtual terminal which accepts user input in non-canonical 
 * mode , processes it and displays desired output to the user.
 *
 * ***************************************************************************/

#include "Terminal.hh"

// initializes required stuff for our terminal
Terminal::Terminal(string mo_xml_file)
{
	
	try
	{	// init xerces XML Parser library
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch)
	{
		cout << toCatch.getMessage() << endl;
		exit(1);
	}

	// set xml file name
	xmlFile = mo_xml_file;

	// store the initial terminal settings
	tcgetattr(fileno(stdin), &initial_settings);

	// make empty strings
	prompt = "";
	command = "";
	output = "";

	//config mode off by default
	configMode = false;

	// exit command false by default
	isExitCommand = false;

	// init MoTree
	currentMoTree = new MoTree(xmlFile);

	// init Mo
	currentMo = currentMoTree->getRootMo();

}

Terminal::~Terminal()
{
	// de-allocate xerces XML library resources
	XMLPlatformUtils::Terminate();
}

// logins the user to the NODE
bool Terminal::login()
{
	string usercode, password;

	// Ask for USERCODE
	cout << "USERCODE: ";
	getline(cin, usercode);

	// clean up the string
	Helper::strip(usercode);

	// Ask for password
	cout << "Password: ";
	getline(cin, password);
	
	// clean up the string
	Helper::strip(password);

	// validate and send header plus MML prompt
	// also set the prompt value
	if (usercode.compare("abc") == 0 &&
		password.compare("abc") == 0)
	{
		prompt = MML_PROMPT;
		cout << HEADER_AND_MML_PROMPT;
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

		// processInput
		processInput(ch);

		// if char is not TAB char then
		if (ch == ENTER)
		{
			// display output and prompt
			cout << output << endl;
			cout << prompt << flush;

			// clean up the output buffer
			output = "";
		}
		// else processTab function will update 
		// autocompleted command inline on the terminal
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
			processTab();
			break;

		// enter  pressed
		case ENTER:
			processEnter();
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

// handles tab autocomplete functionality
void Terminal::processTab()
{
	// strip spaces and semi-colon from the command (if any)
	command = Helper::strip(command);

	// get all child Mo's starting with text in command
	MoList* list = currentMo->getChildMoNameStartsWith(command);

	// if only one match is found then
	if (list->getLength() == 1)
	{ 
		// update the command with this only Mo Name in list
		command = list->getMoAtIndex(0)->getName();

		// complete the command inline
		// by printing <CR(carriage return)> prompt updated command
		cout << CR << prompt << command;
	}
	// else many Mo's are begining with text in command then
	else
	{
		// then list each Mo in a newline
		for (int i = 0; i < list->getLength(); i++)
		{
			cout << endl << list->getMoAtIndex(i)->getName();
		}
		// also print the prompt and typed command by user in newline
		cout << endl << prompt << command;
	}
}

// checks if a valid MO name is typed at the terminal,
// if it is a valid MO then update the prompt to that MO and
// sets respective command output if MO also has a output associated with it
void Terminal::processEnter()
{
	// strip spaces and semi-colon from the command (if any)
	command = Helper::strip(command);
	
	// empty command then return right away
	if (command.empty())
	{
		return;
	}

	// if a special command has came then
	if (isSpecialCommand())
	{
        	// call processSpecialCommand
		processSpecialCommand();
		
		// make command as empty string and return
		command = "";
		return;
	}

	// if at root Mo then
	if (currentMo->getName() == "MML")
	{
		// processNonMoCommand
		processMMLCommand();
		
		// make command as empty string and return
		command = "";
		return;
	}

	// get child Mo of currentMo which has name as user 
	// typed in command
	Mo* newMo = currentMo->getChildMoByName(command);

    
	// if Mo not found then
	if (newMo == NULL)
	{
		// make command as empty string
		command = "";

		// and set output as "ERROR: command not found."
		output = "ERROR: command not found.";

		// and return.
		return;
	}

	// when found make currentMo as new Mo
	currentMo = newMo;

	// if Mo is "configure" then
	if (currentMo->getName() == "configure")
	{
		// set config mode as true
		configMode = true;
	}
	
    	// if Mo is a variable then
	if (currentMo->isVariable())
	{
		// call processVariable to update variable value
		processVariable();
		
		// switch back to parentMo i.e. make
		// currentMo as currentMo->getParentMo
		currentMo = currentMo->getParentMo();
	}
	// else Mo not a variable then
	else
	{
		// call update prompt with Mo name as argument
		// which will updates the prompt according to the Mo
		updatePrompt(currentMo->getName());
	}

	// make command string as empty
	command = "";
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

// checks whether it is a special commmand 
// special commands for now are as below:
// (up, top, end, abort -s, abort, commit -s, commit, show, mml, exit;).
// Special commands are those commands which are not defined in XML
bool Terminal::isSpecialCommand()
{
	// special command list
	string list[10] = {"up", "top", "end", "abort -s", "abort", "commit", "commit -s", "show" , "mml", "quit"};

	// check if user typed command is one of the special command
	for (int i = 0; i < 10; i++)
	{
		if (list[i] == command)
		{
			return true;
		}
	}

return false;
}

// handle special commands
void Terminal::processSpecialCommand()
{
	// otherwise call respective special command handler
	if (Helper::equalsIgnoreCase(command, "quit"))
	{
		isExitCommand = true;
		
		// empty the prompt
		prompt = "";
	}
	else if (command == "up")
	{
		processUp();
	}
	else if (command == "top")
	{
		processTop();
	}
	else if (command == "end")
	{
		processEnd();
	}
	else if (command == "show")
	{
		processShow();
	}
	else if (command == "mml")
	{
		processMml();
	}
	else
	{
		// special command handler not found
		command = "";
		output = "Special Command Handler not found :(";
	}
}

// handles mml command
void Terminal::processMMLCommand()
{
	// get child Mo having name as user gave in command
	Mo* mo = currentMo->getChildMoByName(command);

	// if match found then
	if (mo != NULL)
	{
		// make currentMo as the matched Mo
		currentMo = mo;
	}
	else
	{
		// set error message and return
		output = "Invalid Command.";
		return;
	}

	// if Mo is APLOC Mo then
	if (currentMo->getName() == "APLOC")
	{
		// make prompt as APLOC prompt
		prompt = APLOC_PROMPT;

		return;
	}

	// else if it is an interactive command then
	// TODO
		// call processInteractive command
		// TODO
	
	// else do below
	// TODO
  
		// see if this node hastext containing filename
		// then read the text which is a file name
		// read the file content and set it in the output string
		// then make currentMo back as parentMo
		// TODO
}

// handles Interactive commands which requires further user input
void Terminal::processInteractive()
{
	// get command name and call respective method
	// TODO
}


// handles variables processing
void Terminal::processVariable()
{
	// TODO
}

// updates prompt of the terminal
void Terminal::updatePrompt(string str)
{
	// set config prompt for configure command
	if (str == "configure")
	{
		prompt = string("(config)") + APLOC_PROMPT;
	}

	// mml mode
	else if (currentMo->getName() == "MML")
	{
		prompt = str;
	}

	// APLOC mode
	else if (currentMo->getName() == "APLOC")
	{
		prompt = str;
	}

	// got some other Mo name
	else
	{
		// see if config mode is set then
		if (configMode == true)
		{
			// append Mo name to config prompt
			prompt = string("(config-") + str + string(")") + APLOC_PROMPT;
		}
		// else just set the Mo name as prompt
		else
		{
			prompt = string("(") + str + string(")") + APLOC_PROMPT;
		}
	}
}

// special command handlers
void Terminal::processUp()
{
	// if already at APLOC Mo or configure Mo set error message
	// and return
	if (currentMo->getName() == "configure" ||
		currentMo->getName() == "APLOC")
	{
		output = "Already at the root.";
		return;
	}

	// also 'up' command can't run in MML mode
	// thus set separate error and return
	if (currentMo->getName() == "MML")
	{
		output = "Invalid Command.";
		return;
	}
	
	// set error and return
	// get the parent Mo and shift to it
	Mo *parent = currentMo->getParentMo();
	currentMo = parent;

	// update the prompt accordingly
	updatePrompt(currentMo->getName());
}

void Terminal::processTop()
{
	// TODO
}

void Terminal::processEnd()
{
	// show error if at MML Mo and return
	if (currentMo->getName() == "MML")
	{
		output = "Error: Invalid Command.";
		return;
	}
	
	// get the APLOC Mo and set it as current Mo
	currentMo = currentMoTree->getMoByName("APLOC");

	// disable config mode
	configMode = false;

	// update the prompt
	updatePrompt(APLOC_PROMPT);
}

void Terminal::processShow()
{
	// TODO
}

void Terminal::processMml()
{
	// set error message if not at APLOC Mo and return
	if (currentMo->getName() != "APLOC")
	{
		output = "Error: Invalid command";
		return;
	}

	// shift the Mo to MML
	currentMo = currentMo->getParentMo();

	// update the prompt
	updatePrompt(MML_PROMPT);
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

string Terminal::getPrompt()
{
    return prompt;
}

string Terminal::getCommand()
{
    return command;
}

string Terminal::getOutput()
{
    return output;
}

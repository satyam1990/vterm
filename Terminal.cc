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
Terminal::Terminal()
{
	// set xml file name
	xmlFile = DEFAULT_XML_FILE_NAME;

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
	ourMoTree = new MoTree(xmlFile);

	// init Mo
	currentMo = ourMoTree->getRootMo();
}

// logins the user to the NODE
bool Terminal::login()
{
	string usercode, password;

	// Ask for USERCODE
	cout << "USERCODE: ";
	cin >> usercode;

	// Ask for password
	cout << "Password: ";
	cin >> password;

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
		exit(1);
	}
}

// main loop of our terminal which keeps on accepting user input
// processes it and displays desired results
void Terminal::main()
{
	char ch;

	// main loop
	while (isExitCommand != true)
	{

		// if at root Mo i.e. MML mode then
		if (currentMo->getName() == "MML")
		{ 
			// read line
			cin >> command;

			// processEnter
			processEnter();
		}
        
		// else if in local mode then
		else
		{
			// read character
			ch = getchar();

			// processInput
			processInput(ch);
		}

		// if char is not TAB char then
		if (ch != TAB && ch != BACKSPACE)
		{
			// display output and prompt
			cout << output;
			cout << prompt;
		}
		// else processTab function will update 
		// autocompleted command inline on the terminal
	}
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
			processBackspace();
			break;
		
		// tab pressed
		case TAB:
			processTab();
			break;

		// enter  pressed
		case ENTER:
			processEnter();
			break;

		// default
		default:
			// append character to command string
			command += c;
	}
}

// handles tab autocomplete functionality
void Terminal::processTab()
{
    // get all child Mo's starting with text in command

    // if only one match is found then
        
        // update the command with this Mo Name
        // complete the command inline
        // by printing <CR> prompt <MoName>
    // else many Mo's are begining with text in command then

        // then list each Mo in a newline
}

// checks if a valid MO name is typed at the terminal,
// if it is a valid MO then update the prompt to that MO and
// sets respective command output if MO also has a output associated with it
void Terminal::processEnter()
{
    // if at root Mo then
        
        // processNonMoCommand 
        // make command as empty string and return

    // if a special command has came then

        // call processSpecialCommand

    // get child Mo of currentMo which has name as user 
    // typed in command
    
    // if Mo not found then 
        // make command as empty string
        // and set output as "ERROR: command not found."
        // and return.

    // if found make currentMo as new Mo 

    // if Mo is "configure" then
    
        // set config mode as true
        // call update prompt with MoName as an argument
    
    // if Mo is a variable then

        // call processVariable to update variable value
        // switch back to parentMo i.e. make
        // currentMo as currentMo->getParentMo

    // else Mo not a variable then

        // shift currentMo to this new Mo
        // call update prompt with Mo name as argument
        // which will updates the prompt according to the Mo

    // make command string as empty
}

// removes one character from the end from our command when backspace 
// key is pressed
void Terminal::processBackspace()
{
}

// checks whether it is a special commmand 
// special commands for now are as below:
// (up, top, end, abort -s, abort, commit -s, commit, show).
// Special commands are those commands which are not defined in XML
bool Terminal::isSpecialCommand()
{
}

// handle special commands
void processSpecialCommand()
{
    // we at root Mo then

        // make command as empty and
        // set output as "ERRONEOUS command"

    // call respective special command handler
}

// handles non-MO commands
void Terminal::processNonMoCommand()
{
    // if is a special command then

        // process special command

    // handle MML command
}
        
// handles mml command
void processMMLCommand()
{
    // get all child Mo's and check with user typed Mo
    // if match found then

        // make currentMo as the matched Mo
    // else 

        // set error message and return

    // if command is APLOC then

        // make prompt as APLOC prompt
        // return

    // else if it is an interactive command then

        // call processInteractive command
        // then make currentMo back as parentMo

    // else do below
  
        // see if this node hastext containing filename
        // then read the text which is a file name
        // read the file content and set it in the output string
        // then make currentMo back as parentMo
}

// handles Interactive commands which requires further user input
void Terminal::processInteractive()
{
    // get command name and call respective method
}

// sets the terminal in non-canonical mode
void Terminal::setTerminalAttributes()
{
}

// resets the terminal to its original state
void Terminal::resetTerminalAttributes()
{
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

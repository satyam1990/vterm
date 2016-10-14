/**********************************************************************
 *
 * APLOCProcessor.cc
 *
 * Author: mSatyam
 *
 * 2016, August
 *
 * Processes APLOC mode commands
 *
 * ********************************************************************/

#include "APLOCProcessor.hh"

// intialize the APLOCProcessor
APLOCProcessor::APLOCProcessor(string mo_xml_file)
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
    if (mo_xml_file.empty())
    {
        xmlFile = DEFAULT_MO_XML_FILE_PATH;
    }
    else
    {
        xmlFile = mo_xml_file;
    }

    // init MoTree
    currentMoTree = new MoTree(xmlFile);

    // init Mo
    currentMo = currentMoTree->getRootMo();

    // set config mode as false initially
    configMode = false;

    // set the default APLOC prompt
    prompt = APLOC_PROMPT;
}

APLOCProcessor::~APLOCProcessor()
{
    // de-allocate xerces XML library resources
    XMLPlatformUtils::Terminate();
}

// returns response for an APLOC command
APLOCResponse APLOCProcessor::getResponse(string command)
{
    APLOCResponse resp;

    // return immediately with only prompt as a response if command is empty
    if (Helper::stripSpace(command) == "")
    {
        resp.setPrompt(getPrompt());

        return resp;
    }

    // do autocompletion if it's a TAB appended command
    if (command[command.length() - 1] == TAB)
    {
        command = Helper::stripSpace(command);
        resp = processTab(command);
    }
    // process complete command
    else
    {
        command = Helper::stripSpace(command);
        resp = processEnter(command);
    }

    return resp;
}

// handles TAB character autocompletion functionality
APLOCResponse APLOCProcessor::processTab(string command)
{
    APLOCResponse resp;

    // get all child Mo's starting with text in command
    MoList* list = currentMo->getChildMoNameStartsWith(command);

    // if only one match is found then
    if (list->getLength() == 1)
    { 
        // get the complete command
        command = list->getMoAtIndex(0)->getName();
        
        // set the complete command in response
        resp.setAutoCompletedCommand(command);

        // set the prompt
        resp.setPrompt(prompt);
    }
    // else many Mo's are begining with text in command then
    else
    {
        stringstream out;
        // then list each Mo in a newline
        for (int i = 0; i < list->getLength(); i++)
        {
            out << endl << list->getMoAtIndex(i)->getName();
        }

        // set the prompt and output
        resp.setPrompt(prompt);
        resp.setOutput(out.str());
    }

    return resp;
}

// handles complete commands i.e. commands ending with ENTER key
APLOCResponse APLOCProcessor::processEnter(string command)
{
    if (isNonMoCommand(command))
        return handleNonMoCommand(command);

    APLOCResponse resp;

    // get child Mo of currentMo which has name as user 
    // typed in command
    Mo* newMo = currentMo->getChildMoByName(command);
    
    // if Mo not found then
    if (newMo == NULL)
    {
        // keep the old prompt intact no need to change
        resp.setPrompt(prompt);

        // set error message as invalid MO entered
        resp.setOutput("ERROR: MO not found.");

        // and return.
        return resp;
    }

    // when found make currentMo as new Mo
    currentMo = newMo;

    // update the prompt
    updatePrompt();

    // make respose and return
    resp.setPrompt(prompt);

    return resp;
}

// checks whether the command is a non-MO command or not
// from non-MO command list
bool APLOCProcessor::isNonMoCommand(string command)
{
    // non-MO command list
    string list[10] = {"up", "top", "end", "abort -s", "abort", "commit", "commit -s", "show" , "mml", "quit"};

    // check if user typed command is one of the non-MO command
    for (int i = 0; i < 10; i++)
    {
        if (list[i] == command)
        {
            return true;
        }
    }

	return false;
}

// handles non-MO commands
APLOCResponse APLOCProcessor::handleNonMoCommand(string command)
{
    if (command == "mml")
    {
        return processMml();
    }
    else
    {
        APLOCResponse resp;
        return resp;    
    }
	
}

// updates the APLOC commandline prompt w.r.t. MO name
void APLOCProcessor::updatePrompt()
{
    // if Mo is "configure" then
    if (currentMo->getName() == "configure")
    {
        // set config mode as true
        configMode = true;

        // update the prompt
        prompt = string("(config)") + APLOC_PROMPT;

        return;
    }
    else if (currentMo->getName() == "APLOC")
    {
        prompt = APLOC_PROMPT;
    }
    // got som other MO name
    else
    {
        // config mode is set then
        if (configMode)
        {
            // append MO name to config prompt
            prompt = string("(config-") + currentMo->getName() + string(")") + APLOC_PROMPT;
        }
        else
        {
            // just set MO name as prompt
            prompt = string("(") + currentMo->getName() + string(")") + APLOC_PROMPT;
        }
    }
}

// handles switching from APLOC to MML mode
APLOCResponse APLOCProcessor::processMml()
{
    APLOCResponse resp;

    if (currentMo->getName() != "APLOC")
    {
        resp.setPrompt(getDefaultPrompt());
        resp.setOutput("Error: Invalid command");

        return resp;
    }

    resp.setExit(true);
    return resp;
}

// returns the current prompt
string APLOCProcessor::getPrompt()
{
    return prompt;
}

// returns the default prompt
string APLOCProcessor::getDefaultPrompt()
{
    return APLOC_PROMPT;
}
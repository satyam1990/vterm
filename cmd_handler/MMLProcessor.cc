/********************************************************************
 *
 * MMLProcessor.cc
 *
 * Author: mSatyam
 *
 * 2016, September
 *
 * Processes MML mode commands
 *
 * ******************************************************************/

#include "MMLProcessor.hh"

// initialize the required stuff
MMLProcessor::MMLProcessor(string mmlDir)
{
	// store mml directory path
	mmlRespDir = mmlDir;
}

// returns response of MML command
MMLResponse MMLProcessor::getResponse(string command)
{
	// clean up the command string
	command = Helper::stripSpace(command);

	// return immediately with only prompt as a response if command is empty
    if (command.length() == 0)
    {
    	MMLResponse resp;
        resp.setPrompt(getDefaultPrompt());

        return resp;
    }

	// in case of invalid commands
	if (validateCommand(command) == false)
	{
		// send error response
		MMLResponse resp;
		resp.setDelayed(false);
		resp.setModeChanged(false);
		resp.setOutput("Error: Invalid command");
		resp.setPrompt(MML_PROMPT);

		return resp;
	}

	// remove the semi-colon from the end of command now
	command = Helper::stripSemicolon(command);

	if (command == "APLOC")
		return handleAPLOC();
	if (command == "EXIT")
		return handleExit();

	return processMML(command);

}

// handles MML to APLOC mode change
MMLResponse MMLProcessor::handleAPLOC()
{
	MMLResponse resp;

	// shift to aploc mode
	resp.setModeChanged(true);

	return resp;
}

// handles exit command
MMLResponse MMLProcessor::handleExit()
{
	MMLResponse resp;
	resp.setExit(true);

	return resp;
}

// validate command syntax
bool MMLProcessor::validateCommand(string command)
{
	// commands ending with semi-colon are valid
	if (command[command.length() - 1] == ';')
		return true;
	return false;
}

// reads the MML response from file and embeds into response object
MMLResponse MMLProcessor::processMML(string command)
{
	MMLResponse resp;

	// make path to mml command response file
	string path = mmlRespDir + "/" + command;

	// get command response from file
	string response = Helper::getFileContents(path);

	// create delayed respose for delayed command
	if (isDelayed(response))
	{
		resp.setDelayed(true);
		resp.setDelayedOutput(response);

		// create immediate part of delayed command
		resp.setOutput("ORDERED");
		resp.setPrompt(MML_PROMPT);
	}
	else
	{
		// else create immediate response
		resp.setOutput(response);
		resp.setPrompt(MML_PROMPT);
	}
	return resp;
} 

// check if response is delayed or not
bool MMLProcessor::isDelayed(string & response)
{
	if (response.find("DELAYED") != string::npos)
	{
		response = response.substr(8);
		return true;
	}
	
	return false;
}

// gets the default MML prompt
string MMLProcessor::getDefaultPrompt()
{
	return MML_PROMPT;
}

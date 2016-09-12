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

// returns response of MML command
Response MMLProcessor::getResponse(string command)
{
	// clean up the command string
	command = Helper::stripSpace(command);

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
	command = stripSemicolon(command);

	if (command == "APLOC")
		return handleAPLOC();
	if (command == "EXIT")
		return handleExit();

	return processMML();

}

// handles MML to APLOC mode change
Response MMLProcessor::handleAPLOC()
{
}

// handles exit command
Response MMLProcessor::handleExit()
{
	MMLResponse resp;
	resp.setExit(true);

	return resp;
}

// validate command syntax
bool MMLProcessor::validateCommand(String command)
{

}

// reads the MML response from file and embeds into response object
Response MMLProcessor::processMML(string command)
{

}

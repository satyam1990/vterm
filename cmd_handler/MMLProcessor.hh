/********************************************************************
 *
 * MMLProcessor.hh
 *
 * Author: mSatyam
 *
 * 2016, September
 *
 * Processes MML mode commands
 *
 * ******************************************************************/

#if !defined(MMLPROCESSOR_HH)
#define MMLPROCESSOR_HH

#define MML_PROMPT "\03< "

#include <string>

using namespace std;

#include "MMLResponse.hh"
#include "Helper.hh"

class MMLProcessor {

	private:
		string mmlRespDir;
    
    public:
		// initialize the required stuff
		MMLProcessor(string mmlDir);

        // returns response of MML command
        MMLResponse getResponse(string command);

        // handles MML to APLOC mode change
        MMLResponse handleAPLOC();

        // handles exit command
        MMLResponse handleExit();

        // validate command syntax
        bool validateCommand(string command);

        // reads the MML response from file and embeds into response object
        MMLResponse processMML(string command);

		// check if response is delayed or not
		bool isDelayed(string & response);

		// gets the default MML prompt
		string getDefaultPrompt();
};
#endif


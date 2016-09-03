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

#define MML_PROMPT "\03<"

class MMLProcessor {
    
    public:
        // returns response of MML command
        Response getResponse(string command);

        // handles MML to APLOC mode change
        Response changeMode();

        // handles exit command
        Response handleExit();
};

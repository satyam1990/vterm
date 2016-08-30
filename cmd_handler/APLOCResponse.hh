/******************************************************************************
 *
 * APLOCResponse.hh
 *
 * Author: msatyam
 *
 * August, 2016
 *
 * Stores responses for the APLOC commands after they are processed.
 *
 * ***************************************************************************/

#if !defined(APLOCRESPONSE_HH)
#define APLOCRESPONSE_HH

#include "Response.hh"

class APLOCResponse : public Response {

    private:
        // stores the autocompleted command
        string autoCompletedCommand;

        // states whether autocompletion has been done or not
        bool autoCompleted;

    public:
        // intialize data members
        APLOCResponse();

        // sets the autocompleted command
        void setAutoCompletedCommand(string a);

        // true if command autocompletion has been done, false otherwise
        void setAutoCompleted(bool b);

        // gets the autocompleted command
        string getAutoCompletedCommand();

        // gets the autocompletion flag
        bool isAutoCompleted();
};
#endif

/******************************************************************************
 *
 * MMLResponse.hh
 *
 * Author: msatyam
 *
 * August, 2016
 *
 * Stores responses for the MML commands after they are processed.
 *
 * ***************************************************************************/

#if !defined(MMLRESPONSE_HH)
#define MMLRESPONSE_HH

#include "Response.hh"

class MMLResponse : public Response {

    private:
        // stores the autocompleted command
        string delayedOutput;

        // states whether autocompletion has been done or not
        bool isDelayed;

    public:
        // intialize data members
        MMLResponse();

        // sets the autocompleted command
        void setDelayedOutput(string a);

        // true if command has a delayed output too, false otherwise
        void setDelayed(bool b);

        // gets the delayed command
        string getDelayedOutput();

        // gets the delayed flag
        bool isDelayed();
};
#endif

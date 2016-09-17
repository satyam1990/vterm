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
        bool delayed;

        // states whether the user has requested to shift to APLOC mode
        bool modeChanged;

    public:
        // intialize data members
        MMLResponse();

        // sets the delayed output
        void setDelayedOutput(string a);

        // sets the delayed flag
        void setDelayed(bool b);

        // sets the modeChanged flag
        void setModeChanged(bool b);

        // gets the delayed output
        string getDelayedOutput();

        // true if command has a delayed output too, false otherwise
        bool isDelayed();

        // true if user wants to shift to APLOC mode, false otherwise
        bool isModeChanged();
};
#endif

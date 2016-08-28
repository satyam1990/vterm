/******************************************************************************
 *
 * Response.hh
 *
 * Author: msatyam
 *
 * August, 2016
 *
 * Stores responses for the command after they are processed.
 *
 * ***************************************************************************/

#if !defined(RESPONSE_HH)
#define RESPONSE_HH

class Response {

    private:
        // stores the output of the command
        string output;

        // prompt of the terminal
        string prompt;

        // states whether the command was a exit command
        bool isExit;

    public:
        // intialize data members
        Response();

        // sets the output
        void setOutput(string o);

        // sets the promt
        void setPrompt(string p);

        // gets the output
        string getOutput();

        // gets the prompt
        string getPrompt();
};
#endif

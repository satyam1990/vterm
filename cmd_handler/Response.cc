/******************************************************************************
 *
 * Response.cc
 *
 * Author: msatyam
 *
 * August, 2016
 *
 * Stores responses for the command after they are processed.
 *
 * ***************************************************************************/

#include "Response.hh"

// intialize data members
Response::Response()
{
    output = "";
    prompt = "";
    isExit = false;
}

// sets the output
void Response::setOutput(string o)
{
    output = o;
}

// sets the promt
void Response::setPrompt(string p)
{
    prompt = p;
}

// true if exit command found, false otherwise
void Response::setExit(bool b)
{
    isExit = b;
}

// gets the output
string Response::getOutput()
{
    return output;
}

// gets the prompt
string Response::getPrompt()
{
    return prompt;
}

// should terminal exit or not
bool Response::doExit()
{
    return isExit;
}

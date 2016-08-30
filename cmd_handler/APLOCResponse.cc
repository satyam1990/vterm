/******************************************************************************
 *
 * APLOCResponse.cc
 *
 * Author: msatyam
 *
 * August, 2016
 *
 * Stores responses for the APLOC commands after they are processed.
 *
 * ***************************************************************************/

#include "APLOCResponse.hh"

// intialize data members
APLOCResponse::APLOCResponse()
{
    autoCompletedCommand = "";
    autoCompleted = false;
}

// sets the autocompleted command
void APLOCResponse::setAutoCompletedCommand(string a)
{
    autoCompletedCommand = a;
}

// true if command autocompletion has been done, false otherwise
void APLOCResponse::setAutoCompleted(bool b)
{
    autoCompleted = b;
}

// gets the autocompleted command
string APLOCResponse::getAutoCompletedCommand()
{
    return autoCompletedCommand;
}

// gets the autocompletion flag
bool APLOCResponse::isAutoCompleted()
{
    return autoCompleted;
}

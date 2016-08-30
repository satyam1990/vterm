/******************************************************************************
 *
 * MMLResponse.cc
 *
 * Author: mSatyam
 *
 * August, 2016
 *
 * Stores responses for the MML commands after they are processed.
 *
 * ***************************************************************************/

#include "MMLResponse.hh"

// intialize data members
MMLResponse::MMLResponse()
{
    delayedOutput = "";
}

// sets the autocompleted command
void MMLResponse::setDelayedOutput(string a)
{
    delayedOutput = a;
}

// true if command has a delayed output too, false otherwise
void MMLResponse::setDelayed(bool b)
{
    isDelayed = b;
}

// gets the delayed command
string MMLResponse::getDelayedOutput()
{
    return delayedOutput;
}

// gets the delayed flag
bool MMLResponse::isDelayed()
{
    return isDelayed;
}

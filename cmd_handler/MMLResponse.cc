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
    isDelayed = false;
    modeChanged = false;
}

// sets the delayed output
void MMLResponse::setDelayedOutput(string a)
{
    delayedOutput = a;
}

// sets the delayed flag
void MMLResponse::setDelayed(bool b)
{
    isDelayed = b;
}

// sets the modeChanged flag
void MMLResponse::setModeChanged(bool b)
{
    modeChanged = b;
}

// gets the delayed output
string MMLResponse::getDelayedOutput()
{
    return delayedOutput;
}

// true if command has a delayed output too, false otherwise
bool MMLResponse::isDelayed()
{
    return isDelayed;
}

// true if user wants to shift to APLOC mode, false otherwise
bool MMLResponse::isModeChanged()
{
    return modeChanged;
}

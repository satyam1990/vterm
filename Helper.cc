/******************************************************************************
 *
 * Helper.cc
 *
 * Author: mSatyam
 *
 * August, 2015
 *
 * Some Utility functions.
 *
 * ***************************************************************************/

#include "Helper.hh"

// compares two strings ignoring case
bool Helper::equalsIgnoreCase(string str1, string str2)
{
	bool equal = true;
	if (str1.length() != str2.length())
	{
		return false;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		if (tolower(str1.at(i)) != tolower(str2.at(i)))
		{
			equal = false;
			break;
		}
	}

	return equal;
}

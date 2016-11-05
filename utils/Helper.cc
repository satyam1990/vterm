/******************************************************************************
 *
 * Helper.cc
 *
 * Author: mSatyam
 *
 * August, 2016
 *
 * Some Utility functions.
 *
 * ***************************************************************************/

#include "Helper.hh"

// compares two strings ignoring case
bool Helper::equalsIgnoreCase(string str1, string str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		if (tolower(str1.at(i)) != tolower(str2.at(i)))
		{
			return false;
		}
	}

	return true;
}

// checks if string str2 has a substring str1 at index 0
// ignoring case
bool Helper::isStartingWith(string str1, string str2)
{
	if (str2.length() < str1.length())
	{
		return false;
	}
	
	for (int i = 0; i < str1.length(); i++)
	{
		if (tolower(str1.at(i)) != tolower(str2.at(i)))
		{
			return false;
		}
	}

	return true;
}

// strip spaces from begining and end of the string (if any)
string Helper::stripSpace(string& str)
{
	string temp = str;

	// remove space from begining
	for (int i = 0; (i < str.length()) && isspace(str[i]); i++)
	{
		temp = str.substr(i + 1 , string::npos);
	}

	// update the str
	str = temp;

	// remove space from end
	for (int i = str.length() - 1; (i >= 0) && isspace(str[i]); i--)
	{
		temp = str.substr(0, str.length() - (str.length() - i));
	}

	// update the str
	str = temp;

	return str;
}

string Helper::stripSemicolon(string& str)
{
	// see if last character is ';'
	if ( str[str.length() - 1] == ';')
	{
		// remove it
		str = str.substr(0, str.length() - 1);
	}

	return str;
}

// reads contents of a flat file
string Helper::getFileContents(string filename)
{
	string contents = "";
	int length = 0;

	ifstream inFile(filename.c_str(), ifstream::in);

	if (inFile)
	{
		// get the length of file
		inFile.seekg(0, inFile.end);
		length = inFile.tellg();

		// move back to file begining
		inFile.seekg(0, inFile.beg);

		// allocate memory to hold file contents
		char* buffer = new char[length + 1];

		// read data as a block
		inFile.read(buffer, length);
		inFile.close();

		contents = buffer;

		delete[] buffer;
	}

	return contents;
}

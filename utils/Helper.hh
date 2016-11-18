/******************************************************************************
 *
 * Helper.hh
 *
 * Author: mSatyam
 *
 * August, 2016
 *
 * Some Utility functions.
 *
 * ***************************************************************************/

#if !defined(HELPER_HH)
#define HELPER_HH

#define DELIMITER "="

#include <cctype>
#include <string>
#include <fstream>

using namespace std;

class Helper {

	public:
		// compares two strings ignoring case
		static bool equalsIgnoreCase(string str1, string str2);
		
		// checks if string str2 has a substring str1 at index 0
		// ignoring case
		static bool isStartingWith(string str1, string str2);

		// strip spaces from the string
		static string stripSpace(string& str);

		// strip semi-colon from the end of the command
		static string stripSemicolon(string& str);

		// reads contents of a flat file
		static string getFileContents(string filename);

		// reads the variable value from wans config file
		static string getVar(string configFile, string var);
};
#endif

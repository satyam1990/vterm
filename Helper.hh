/******************************************************************************
 *
 * Helper.hh
 *
 * Author: mSatyam
 *
 * August, 2015
 *
 * Some Utility functions.
 *
 * ***************************************************************************/

#include <cctype>
#include "headers.hh"

class Helper {

	public:
		// compares two strings ignoring case
		static bool equalsIgnoreCase(string str1, string str2);
		
		// checks if string str2 has a substring str1 at index 0
		// ignoring case
		static bool isStartingWith(string str1, string str2);

		// strip spaces and semi-colon from the command (if any)
		static string strip(string& str);
};

/******************************************************************************
 *
 * main.cc
 *
 * Author: mSatyam
 *
 * August, 2015
 *
 * Starting point of the vterm application.
 *
 * ***************************************************************************/

#include "Terminal.hh"

int main()
{
	// our terminal
	Terminal term;

	// login the user
	if (term.login() == true)
	{
		// listen for user requests
		term.main();
	}

return 0;
}

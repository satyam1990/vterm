/******************************************************************************
 *
 * main.cc
 *
 * Author: mSatyam
 *
 * September, 2016
 *
 * Starting point of the vterm application.
 *
 * ***************************************************************************/

#include "Terminal.hh"

int main(int argc, char* argv[])
{
	// validate proper usage
	if ( argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <NE Simulator root dir>" << endl;
		exit(0);
	}

	// store the root dir path
	string root_dir = argv[1];

	// our terminal
	Terminal term(root_dir);

	// login the user
	if (term.login() == true)
	{
		// listen for user requests
		term.main();
	}

return 0;
}

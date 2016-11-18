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
		cerr << "Usage: " << argv[0] << " <NE Simulator wans.conf file path>" << endl;
		exit(0);
	}

	// store the wans config file path
	string configFile = argv[1];

	// our terminal
	Terminal term(configFile);

	// login the user
	if (term.login() == true)
	{
		// listen for user requests
		term.main();
	}

return 0;
}

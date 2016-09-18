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
		cerr << "Usage: " << argv[0] << " <xml_file_name>" << endl;
		exit(0);
	}

	// store the xml file name
	string mo_xml_file = argv[1];

	// our terminal
	Terminal term(mo_xml_file);

	// login the user
	if (term.login() == true)
	{
		// listen for user requests
		term.main();
	}

return 0;
}

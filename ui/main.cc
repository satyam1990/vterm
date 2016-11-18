/******************************************************************************
 *
 * main.cc
 *
 * Author: mSatyam
 *
 * October, 2016
 *
 * Initializes GTKMM toolkit and launches the NE simulator's main window
 *
 * ***************************************************************************/

#include <gtk/gtk.h>

#include "MainWindow.hh"

int main(int argc, char* argv[])
{
	// validate proper usage
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <WANS_CONFIG_FILE_PATH>" << endl;
		exit(-1);
	}

    // initialize the GTKMM toolkit
    gtk_init(&argc, &argv);

    // create the main window instance
    MainWindow win(argv[1]);

    // launch the window and start the main loop
    gtk_main();

    return 0;
}

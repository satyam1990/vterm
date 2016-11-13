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
    // initialize the GTKMM toolkit
    gtk_init(&argc, &argv);

    // create the main window instance
    MainWindow win;

    // launch the window and start the main loop
    gtk_main();

    return 0;
}

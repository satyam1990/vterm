/******************************************************************************
 *
 * MainWindow.cc
 *
 * Author: msatyam
 *
 * October, 2016
 *
 * Main window of the Network Simulator GUI
 *
 * ***************************************************************************/

#include "MainWindow.hh"

// sets up GUI main window
MainWindow::MainWindow()
{
    // add vbox which will contain all hboxes to the main window
    add(vbox);

    // add all the hboxes into the vbox
    vbox.pack_start(hbox1);
    vbox.pack_start(hbox2);
    vbox.pack_start(hbox3);
    vbox.pack_start(hbox4);
    vbox.pack_start(hbox5);

    // add label to start stop button
    startButton.set_label("Start NODE");
    stopButton.set_label("Stop NODE");

    // add the start stop button to the hbox2 container
    hbox2.pack_start(startButton);
    hbox2.pack_start(stopButton);

    // display all the widgets
    show_all_children();
}

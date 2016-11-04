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

    // create menubar and menu items
    actionGroup = Gtk::ActionGroup::create();

    // File Menu
    actionGroup->add(Gtk::Action::create("FileMenu", "File"));

    uiManager = Gtk::UIManager::create();
    uiManager->insert_action_group(actionGroup);

    menubarLayout = getMenubarLayout();

    try
    {
        uiManager->add_ui_from_string(menubarLayout);
    }
    catch (const Glib::Error& ex)
    {
        cerr << "Building Menu Failed" << ex.what();
    }

    Gtk::Widget* menubar = uiManager->get_widget("/Menubar");

    // add menubar to hbox1
    hbox1.pack_start(*menubar, true, true, 10);

    // add label to start stop button
    startButton.set_label("Start NODE");
    stopButton.set_label("Stop NODE");
    sendAlarmButton.set_label("Send Alarm");

    // add the start stop button to the hbox2 container
    hbox2.pack_start(startButton, true, true, 10);
    hbox2.pack_start(stopButton, true, true, 10);
    hbox2.pack_start(sendAlarmButton, true, true, 10);

    nodeStatusFrame.set_label("NODE Status");
    hbox3.pack_start(nodeStatusFrame, true, true, 10);

    // display all the widgets
    show_all_children();
}

Glib::ustring MainWindow::getMenubarLayout()
{
    Glib::ustring menuLayout = 
        "<ui>"
            "<menubar name='Menubar'>"
                "<menu action='FileMenu'>"
                "</menu>"
            "</menubar>"
        "</ui>";

    return menuLayout;
}
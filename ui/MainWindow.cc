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
    set_title("NE Simulator");
    set_default_size(400, 200);
    set_position(Gtk::WIN_POS_CENTER);

    // add vbox which will contain all hboxes to the main window
    add(vbox);

    // add all the hboxes into the vbox
    vbox.pack_start(hbox1);
    vbox.pack_start(hbox2);
    vbox.pack_start(hbox3);
    vbox.pack_start(hbox5);

    // create menubar and menu items
    actionGroup = Gtk::ActionGroup::create();

    // File Menu
    actionGroup->add(Gtk::Action::create("FileMenu", "File"));
    // menu items under File
    actionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT));

    // Edit Menu
    actionGroup->add(Gtk::Action::create("EditMenu", "Edit"));
    // menu items under Edit
    actionGroup->add(Gtk::Action::create("MOPath", "MO File Path"));
    actionGroup->add(Gtk::Action::create("MMLPath", "MML Response File Path"));
    actionGroup->add(Gtk::Action::create("DefaultDestination", "Default Destination"));

    // Option Menu
    actionGroup->add(Gtk::Action::create("OptionMenu", "Options"));
    // menu items under option
    actionGroup->add(Gtk::Action::create("CustomAlarm", "Send Custom Alarms"));

    // Help Menu
    actionGroup->add(Gtk::Action::create("HelpMenu", "Help"));
    // menu items under help
    actionGroup->add(Gtk::Action::create("HelpAbout", Gtk::Stock::HELP));

    uiManager = Gtk::UIManager::create();
    uiManager->insert_action_group(actionGroup);

    add_accel_group(uiManager->get_accel_group());

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
    // diable stop button by default
    stopButton.set_sensitive(false);

    sendAlarmButton.set_label("Send Alarm");

    // add the start stop and send alarm button to the hbox2 container
    hbox2.pack_start(startButton, true, true, 10);
    hbox2.pack_start(stopButton, true, true, 10);
    hbox2.pack_start(sendAlarmButton, true, true, 10);

    nodeStatusFrame.set_label("NODE Status");
    hbox3.pack_start(nodeStatusFrame, true, true, 10);

    // set the default NODE status icon and label as stopped
    nodeStatusIcon.set(Gtk::Stock::NO, Gtk::IconSize(1));
    nodeStatusLabel.set_text("STOPPED");

    // add NODE status icon and label to hbox4
    hbox4.pack_start(nodeStatusIcon, false, false, 10);
    hbox4.pack_start(nodeStatusLabel, false, false, 10);

    // add NODE staus in node status frame
    nodeStatusFrame.add(hbox4);

    // display all the widgets
    show_all_children();
}

Glib::ustring MainWindow::getMenubarLayout()
{
    Glib::ustring menuLayout = 
        "<ui>"
            "<menubar name='Menubar'>"
                "<menu action='FileMenu'>"
                    "<menuitem action='FileQuit'/>"
                "</menu>"
                "<menu action='EditMenu'>"
                    "<menuitem action='MOPath'/>"
                    "<menuitem action='MMLPath'/>"
                    "<separator />"
                    "<menuitem action='DefaultDestination'/>"
                "</menu>"
                "<menu action='OptionMenu'>"
                    "<menuitem action='CustomAlarm'/>"
                "</menu>"
                "<menu action='HelpMenu'>"
                    "<menuitem action='HelpAbout'/>"
                "</menu>"
            "</menubar>"
        "</ui>";

    return menuLayout;
}
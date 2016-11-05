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

    // add main scrolled window to toplevel window
    add(mainScrolledWindow);

    // scrolled window only visible when required
    mainScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    // add vbox which will contain all hboxes to the main scrolled window
    mainScrolledWindow.add(vbox);

    // add all the hboxes into the vbox
    vbox.pack_start(hbox1);
    vbox.pack_start(hbox2);
    vbox.pack_start(hbox3);

    // create menubar and menu items
    actionGroup = Gtk::ActionGroup::create();

    // File Menu
    actionGroup->add(Gtk::Action::create("FileMenu", "File"));
    // menu items under File
    actionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
                sigc::ptr_fun(&Gtk::Main::quit));

    // Edit Menu
    actionGroup->add(Gtk::Action::create("EditMenu", "Edit"));
    // menu items under Edit
    actionGroup->add(Gtk::Action::create("MOPath", "MO File Path"),
                sigc::ptr_fun(&EventHandler::editMOPath));
    actionGroup->add(Gtk::Action::create("MMLPath", "MML Response File Path"),
                sigc::ptr_fun(&EventHandler::editMMLPath));
    actionGroup->add(Gtk::Action::create("DefaultDestination", "Default Destination"),
                sigc::ptr_fun(&EventHandler::editDefaultDestination));

    // Option Menu
    actionGroup->add(Gtk::Action::create("OptionMenu", "Options"));
    // menu items under option
    actionGroup->add(Gtk::Action::create("CustomAlarm", "Send Custom Alarms"),
                sigc::ptr_fun(&EventHandler::customAlarmHandler));

    // Help Menu
    actionGroup->add(Gtk::Action::create("HelpMenu", "Help"));
    // menu items under help
    actionGroup->add(Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
                sigc::ptr_fun(&EventHandler::helpHandler));

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
    startButton.signal_clicked().connect(sigc::ptr_fun(&EventHandler::startNE));
    
    stopButton.set_label("Stop NODE");
    stopButton.signal_clicked().connect(sigc::ptr_fun(&EventHandler::stopNE));

    sendAlarmButton.set_label("Send Alarm");
    sendAlarmButton.signal_clicked().connect(sigc::ptr_fun(&EventHandler::sendAlarmHandler));

    // add the start stop and send alarm button to the hbox2 container
    hbox2.pack_start(startButton, true, true, 10);
    hbox2.pack_start(stopButton, true, true, 10);
    hbox2.pack_start(sendAlarmButton, true, true, 10);

    nodeStatusFrame.set_label("NODE Status");
    hbox3.pack_start(nodeStatusFrame, true, true, 10);

    // add NODE status icon and label to hbox4
    hbox4.pack_start(nodeStatusIcon, false, false, 10);
    hbox4.pack_start(nodeStatusLabel, false, false, 10);

    // add NODE staus in node status frame
    nodeStatusFrame.add(hbox4);

    // check NODE status
    checkNodeStatus();

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

// return true when simulator running else false
bool MainWindow::checkNodeStatus()
{
    string contents = Helper::getFileContents(ETC_SERVICES);
    
    // see if NE simulator settings already installed in inetd conf
    if (contents.find(NE_MAGIC_TEXT) == string::npos)
    {
        // Simulator not started yet

        // set the NODE status icon and label as stopped
        nodeStatusIcon.set(Gtk::Stock::NO, Gtk::IconSize(1));
        nodeStatusLabel.set_text("STOPPED");

        // disable stop button
        stopButton.set_sensitive(false);

        return false;
    }

    // Simulator already running

    // change NODE status label and icon
    nodeStatusIcon.set(Gtk::Stock::YES, Gtk::IconSize(1));
    nodeStatusLabel.set_text("RUNNING");

    // disable the start button
    startButton.set_sensitive(false);
    
    return true;
}
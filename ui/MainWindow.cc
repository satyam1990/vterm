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
    // create toplevel window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_window_set_title(GTK_WINDOW(window), "NE Simulator");

    // create scrolled window
    mainScrolledWindow = gtk_scrolled_window_new(NULL,NULL);

    // add main scrolled window to toplevel window
    gtk_container_add(GTK_CONTAINER(window), mainScrolledWindow);

    // scrolled window only visible when required
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(mainScrolledWindow), 
        GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // create vbox which  contains all hboxes
    vbox = gtk_vbox_new(FALSE, 5);

    // create all the hboxes
    hbox1 = gtk_hbox_new(FALSE, 0);
    hbox2 = gtk_hbox_new(FALSE, 0);
    hbox3 = gtk_hbox_new(FALSE, 0);
    hbox4 = gtk_hbox_new(FALSE, 0);

    // add vbox to the main scrolled window
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(mainScrolledWindow), vbox);

    // add all the hboxes into the vbox
    gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 0);

    // create menubar and different menus in it with menu items
    menubar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();
    editMenu = gtk_menu_new();
    optionsMenu = gtk_menu_new();
    helpMenu = gtk_menu_new();

    fileMenuItem = gtk_menu_item_new_with_label("File");
    quitMenuItem = gtk_menu_item_new_with_label("Quit");

    editMenuItem = gtk_menu_item_new_with_label("Edit");
    moPathMenuItem = gtk_menu_item_new_with_label("MO File Path");
    mmlPathMenuItem = gtk_menu_item_new_with_label("MML Response File Path");
    defaultDestinationMenuItem = gtk_menu_item_new_with_label("Default Destination");

    optionsMenuItem = gtk_menu_item_new_with_label("Options");
    customAlarmMenuItem = gtk_menu_item_new_with_label("Send Custom Alarms");

    helpMenuItem = gtk_menu_item_new_with_label("Help");
    helpContentsMenuItem = gtk_menu_item_new_with_label("Contents");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMenuItem), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMenuItem);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(editMenuItem), editMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), moPathMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), mmlPathMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), defaultDestinationMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), editMenuItem);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(optionsMenuItem), optionsMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(optionsMenu), customAlarmMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), optionsMenuItem);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpMenuItem), helpMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu), helpContentsMenuItem);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), helpMenuItem);

    // add menubar to first  hbox
    gtk_box_pack_start(GTK_BOX(hbox1), menubar, FALSE, FALSE, 10);

    // create start and stop button
    startButton = gtk_button_new_with_label("Start NODE");
    stopButton = gtk_button_new_with_label("Stop NODE");

    // send default alarm button
    sendAlarmButton = gtk_button_new_with_label("Send Alarm");

    // add the start stop and send alarm button to the hbox2 container
    gtk_box_pack_start(GTK_BOX(hbox2), startButton, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox2), stopButton, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox2), sendAlarmButton, TRUE, TRUE, 10);
    
    // create NODE status frame
    nodeStatusFrame = gtk_frame_new("NODE Status");
    gtk_widget_set_size_request(nodeStatusFrame, -1, 100);

    // add frame to hbox3
    gtk_box_pack_start(GTK_BOX(hbox3), nodeStatusFrame, TRUE, TRUE, 10);

    // check NODE status should be called before adding icon and label to hbox
    checkNodeStatus();

    // add NODE status icon and label to hbox4
    gtk_box_pack_start(GTK_BOX(hbox4), nodeStatusIcon, FALSE, FALSE, 10);
    gtk_box_pack_start(GTK_BOX(hbox4), nodeStatusLabel, FALSE, FALSE, 10);

    // add NODE staus in node status frame
    gtk_container_add(GTK_CONTAINER(nodeStatusFrame), hbox4);

    // setup signal handlers for widgets
    setEventHandlers();

    // display all the widgets
    gtk_widget_show_all(window);
}

// sets up signal handlers for widgets
void MainWindow::setEventHandlers()
{
    // set close button signal handler for main window
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // set menu items signal handers
    g_signal_connect(G_OBJECT(quitMenuItem), "activate", 
        G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(moPathMenuItem), "activate", 
        G_CALLBACK(EventHandler::editMOPath), NULL);
    g_signal_connect(G_OBJECT(mmlPathMenuItem), "activate", 
        G_CALLBACK(EventHandler::editMMLPath), NULL);
    g_signal_connect(G_OBJECT(defaultDestinationMenuItem), "activate", 
        G_CALLBACK(EventHandler::editDefaultDestination), NULL);
    g_signal_connect(G_OBJECT(customAlarmMenuItem), "activate", 
        G_CALLBACK(EventHandler::customAlarmHandler), NULL);
    g_signal_connect(G_OBJECT(helpContentsMenuItem), "activate", 
        G_CALLBACK(EventHandler::helpHandler), NULL);

    // buttons signal handler
    g_signal_connect(G_OBJECT(startButton), "clicked", 
        G_CALLBACK(EventHandler::startNE), this);
    g_signal_connect(G_OBJECT(stopButton), "clicked", 
        G_CALLBACK(EventHandler::stopNE), this);
    g_signal_connect(G_OBJECT(sendAlarmButton), "clicked", 
        G_CALLBACK(EventHandler::sendAlarmHandler), NULL);
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
        nodeStatusIcon = gtk_image_new_from_stock(GTK_STOCK_NO, GTK_ICON_SIZE_BUTTON);
        nodeStatusLabel = gtk_label_new("STOPPED");
       
        // disable stop button
		disableStopButton();

        return false;
    }

    // Simulator already running

    // change NODE status label and icon
    nodeStatusIcon = gtk_image_new_from_stock(GTK_STOCK_YES, GTK_ICON_SIZE_BUTTON);
    nodeStatusLabel = gtk_label_new("RUNNING");

    // disable the start button
	disableStartButton();

    return true;
}

// enable start button
void MainWindow::enableStartButton()
{
	gtk_widget_set_sensitive(startButton, TRUE);
}

// disable start button
void MainWindow::disableStartButton()
{
	gtk_widget_set_sensitive(startButton, FALSE);
}

// enable stop button
void MainWindow::enableStopButton()
{
	gtk_widget_set_sensitive(stopButton, TRUE);
}

// disable stop button
void MainWindow::disableStopButton()
{
	gtk_widget_set_sensitive(stopButton, FALSE);
}

// toggle node status
void MainWindow::toggleNodeStatus()
{
	string status = gtk_label_get_text((GtkLabel*) nodeStatusLabel);

	if (status == "RUNNING")
	{
		gtk_label_set_text((GtkLabel*) nodeStatusLabel, "STOPPED");
		gtk_image_set_from_stock((GtkImage*) nodeStatusIcon, GTK_STOCK_NO, GTK_ICON_SIZE_BUTTON);
	}
	else
	{
		gtk_label_set_text((GtkLabel*) nodeStatusLabel, "RUNNING");
		gtk_image_set_from_stock((GtkImage*) nodeStatusIcon, GTK_STOCK_YES, GTK_ICON_SIZE_BUTTON);
	}
}

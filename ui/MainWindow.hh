/******************************************************************************
 *
 * MainWindow.hh
 *
 * Author: msatyam
 *
 * October, 2016
 *
 * Main window of the Network Simulator GUI
 *
 * ***************************************************************************/

#if !defined(MAIN_WINDOW_HH)
#define MAIN_WINDOW_HH

#define ETC_SERVICES "/etc/inet/services"
#define NE_MAGIC_TEXT "wans_5000"

#include <gtk/gtk.h>
#include <iostream>

#include <Helper.hh>
#include "EventHandler.hh"

using namespace std;

class MainWindow {

    private:

		// wans conf file
		string wansConfFile;

        // main window toplevel
        GtkWidget* window;

        // scrolled window
        GtkWidget* mainScrolledWindow;

        // holds all the hboxex
        GtkWidget* vbox;

        // holds the menu bar
        GtkWidget* hbox1;

        // holds the start stop button
        GtkWidget* hbox2;

        // holds the NE status label
        GtkWidget* hbox3;

        // holds the actual NE status
        GtkWidget* hbox4;

        // menubar, menus and all menu items
        GtkWidget* menubar;

        // menus
        GtkWidget* fileMenu;
        GtkWidget* editMenu;
        GtkWidget* optionsMenu;
        GtkWidget* helpMenu;

        // menu items
        GtkWidget* fileMenuItem;
        GtkWidget* quitMenuItem;

        GtkWidget* editMenuItem;
        GtkWidget* moPathMenuItem;
        GtkWidget* mmlPathMenuItem;
        GtkWidget* defaultDestinationMenuItem;

        GtkWidget* optionsMenuItem;
        GtkWidget* customAlarmMenuItem;

        GtkWidget* helpMenuItem;
        GtkWidget* helpContentsMenuItem;

        // NODE start button
        GtkWidget* startButton;

        // NODE stop  button
        GtkWidget* stopButton;

        // Send alarm button
        GtkWidget* sendAlarmButton;

        // holds the NODE status icon and label
        GtkWidget* nodeStatusFrame;

        // node status icon
        GtkWidget* nodeStatusIcon;

        // node status label
        GtkWidget* nodeStatusLabel;

    public:
        // sets up GUI main window
        MainWindow(string confFile);

        // sets up signal handlers for widgets
        void setEventHandlers();

        // checks whether the NODE is running or stopped
        bool checkNodeStatus();

		// enable start button
		void enableStartButton();

		// disable start button
		void disableStartButton();

		// enable stop button
		void enableStopButton();

		// disable stop button
		void disableStopButton();

		// toggle node status
		void toggleNodeStatus();

		// returns wans config file path
		string getConfFile();
};
#endif

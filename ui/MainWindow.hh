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

#define ETC_SERVICES "/etc/services"
#define NE_MAGIC_TEXT "vterm"

#include <gtkmm.h>
#include <iostream>

#include <Helper.hh>

using namespace std;

class MainWindow : public Gtk::Window {

    private:

        // scrolled window
        Gtk::ScrolledWindow mainScrolledWindow;

        // holds all the hboxex
        Gtk::VBox vbox;

        // holds the menu bar
        Gtk::HBox hbox1;

        // holds the start stop button
        Gtk::HBox hbox2;

        // holds the NE status label
        Gtk::HBox hbox3;

        // holds the actual NE status
        Gtk::HBox hbox4;

        // holds the scrolled window containing textview
        Gtk::HBox hbox5;

        Gtk::Frame nodeStatusFrame;

        // holds the textview
        Gtk::ScrolledWindow textScrolledWindow;

        // menu bar using UIManager and ActionGroup
        Glib::RefPtr<Gtk::UIManager> uiManager;
        Glib::RefPtr<Gtk::ActionGroup> actionGroup;
        Glib::ustring menubarLayout;

        // NODE start button
        Gtk::Button startButton;

        // NODE stop  button
        Gtk::Button stopButton;

        // Send alarm button
        Gtk::Button sendAlarmButton;

        // node status icon
        Gtk::Image nodeStatusIcon;

        // node status label
        Gtk::Label nodeStatusLabel;

        // task status view
        Gtk::TextView taskStatus;

    public:
        // sets up GUI main window
        MainWindow();

        // gets the Menubar layout
        Glib::ustring getMenubarLayout();

        // checks whether the NODE is running or stopped
        bool checkNodeStatus();
};
#endif

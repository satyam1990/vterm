/******************************************************************************
 *
 * DdEditorDialog.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit Default destination of OSS server
 *
 * ***************************************************************************/

#if !defined(DD_EDITOR_DIALOG_HH)
#define DD_EDITOR_DIALOG_HH

#include <gtk/gtk.h>

#include <iostream>
#include <string>

#include <Helper.hh>

using namespace std;

class DdEditorDialog {

 	private:
 		// wans config file
 		string wansConfFile;

 		// dialog window
 		GtkWidget* dialog;

 		// hbox that contain ip address label and entry
 		GtkWidget* hbox1;

 		// hbox that contain ip port label and entry
 		GtkWidget* hbox2;

 		// label for IP address
 		GtkWidget* ipLabel;

 		// label for port
 		GtkWidget* portLabel;

 		// entry(textbox)widgets to hold IP
 		GtkWidget* ipTextBox;

 		// entry(textbox)widgets to hold port
 		GtkWidget* portTextBox;

 	public:
 		// intializes the dialog box
 		DdEditorDialog(string confFile);

 		// edits Default Destination as entered by user
 		void editDefaultDestination();

 		// returns the wans conf file path
 		string getConfFile();
};
#endif

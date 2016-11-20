/******************************************************************************
 *
 * MoPathEditorDialog.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit MO file path
 *
 * ***************************************************************************/

#if !defined(MO_PATH_EDITOR_DIALOG_HH)
#define MO_PATH_EDITOR_DIALOG_HH

#include <gtk/gtk.h>

#include <iostream>
#include <string>

#include <Helper.hh>

using namespace std;

class MoPathEditorDialog {

 	private:
 		// wans config file
 		string wansConfFile;

 		// dialog window
 		GtkWidget* dialog;

 		// hbox that contain other widgets
 		GtkWidget* hbox;

 		// label for MO path
 		GtkWidget* moPathLabel;

 		// entry(textbox)widgets to hold MO file path
 		GtkWidget* moPathTextBox;

 	public:
 		// intializes the dialog box
 		MoPathEditorDialog(string confFile);

 		// edits MO File Path as entered by user
 		void editMoFilePath();

 		// returns the wans conf file path
 		string getConfFile();
};
#endif

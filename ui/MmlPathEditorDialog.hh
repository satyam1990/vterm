/******************************************************************************
 *
 * MmlPathEditorDialog.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit MML response directory path
 *
 * ***************************************************************************/

#if !defined(MML_PATH_EDITOR_DIALOG_HH)
#define MML_PATH_EDITOR_DIALOG_HH

#include <gtk/gtk.h>

#include <iostream>
#include <string>

#include <Helper.hh>

using namespace std;

class MmlPathEditorDialog {

 	private:
 		// wans config file
 		string wansConfFile;

 		// dialog window
 		GtkWidget* dialog;

 		// hbox that contain other widgets
 		GtkWidget* hbox;

 		// label for MO path
 		GtkWidget* mmlPathLabel;

 		// entry(textbox)widgets to hold MO file path
 		GtkWidget* mmlPathTextBox;

 	public:
 		// intializes the dialog box
 		MmlPathEditorDialog(string confFile);

 		// edits MML Directory Path as entered by user
 		void editMmlDirectoryPath();

 		// returns the wans conf file path
 		string getConfFile();
};
#endif

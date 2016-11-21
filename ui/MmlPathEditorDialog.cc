/******************************************************************************
 *
 * MmlPathEditorDialog.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit MML response directory path
 *
 * ***************************************************************************/


#include "MmlPathEditorDialog.hh"

// intializes the dialog box
MmlPathEditorDialog::MmlPathEditorDialog(string confFile)
{
	// store wans conf file path
	wansConfFile = confFile;

    // create the MO path editor main dialog window
    dialog = gtk_dialog_new_with_buttons("Edit MML Response Directory Path", 
                                        NULL, 
                                        GTK_DIALOG_MODAL, 
                                        GTK_STOCK_OK, 
                                        GTK_RESPONSE_OK, 
                                        GTK_STOCK_CANCEL, 
                                        GTK_RESPONSE_CANCEL,  
                                        NULL);

    gtk_window_set_default_size(GTK_WINDOW(dialog), 400, 200);

    hbox = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), 
                        hbox, FALSE, FALSE, 30);

    // create the MO path label
    mmlPathLabel = gtk_label_new("MML Directory Path:");

    // create the MO file path text box
    mmlPathTextBox = gtk_entry_new();

    gtk_widget_set_size_request(mmlPathTextBox, 300, 30);

    // set current MO file path
    gtk_entry_set_text(GTK_ENTRY(mmlPathTextBox), Helper::getVar(wansConfFile, "MML_PATH").c_str());

    // add label and textbox to hbox
    gtk_box_pack_start(GTK_BOX(hbox), mmlPathLabel, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox), mmlPathTextBox, TRUE, TRUE, 10);

    // display all widgets in dialog
    gtk_widget_show_all(hbox);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK)
    {
        editMmlDirectoryPath();
    }

    gtk_widget_destroy (dialog);
}

// returns the wans conf file path
string MmlPathEditorDialog::getConfFile()
{
    return wansConfFile;
}

// edits MML Directory Path as entered by user
void MmlPathEditorDialog::editMmlDirectoryPath()
{
    cout << "MML Directory Path Updated" << endl;
}

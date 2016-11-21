/******************************************************************************
 *
 * MoPathEditorDialog.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit MO file path
 *
 * ***************************************************************************/


#include "MoPathEditorDialog.hh"

// intializes the dialog box
MoPathEditorDialog::MoPathEditorDialog(string confFile)
{
	// store wans conf file path
	wansConfFile = confFile;

    // create the MO path editor main dialog window
    dialog = gtk_dialog_new_with_buttons("Edit MO Path", 
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
    moPathLabel = gtk_label_new("MO Path:");

    // create the MO file path text box
    moPathTextBox = gtk_entry_new();

    gtk_widget_set_size_request(moPathTextBox, 300, 30);

    // set current MO file path
    gtk_entry_set_text(GTK_ENTRY(moPathTextBox), Helper::getVar(wansConfFile, "MO_FILE").c_str());

    // add label and textbox to hbox
    gtk_box_pack_start(GTK_BOX(hbox), moPathLabel, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox), moPathTextBox, TRUE, TRUE, 10);

    // display all widgets in dialog
    gtk_widget_show_all(hbox);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK)
    {
        editMoFilePath();
    }

    gtk_widget_destroy (dialog);
}

// returns the wans conf file path
string MoPathEditorDialog::getConfFile()
{
    return wansConfFile;
}

// edits MO File Path as entered by user
void MoPathEditorDialog::editMoFilePath()
{
    cout << "MO File Path Updated" << endl;
}

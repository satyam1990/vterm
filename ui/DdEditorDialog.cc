/******************************************************************************
 *
 * DdEditorDialog.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Dialog box which allows user to to edit Default destination of OSS server
 *
 * ***************************************************************************/


#include "DdEditorDialog.hh"

// intializes the dialog box
DdEditorDialog::DdEditorDialog(string confFile)
{
	// store wans conf file path
	wansConfFile = confFile;

    // create the MO path editor main dialog window
    dialog = gtk_dialog_new_with_buttons("Edit Default Destination", 
                                        NULL, 
                                        GTK_DIALOG_MODAL, 
                                        GTK_STOCK_OK, 
                                        GTK_RESPONSE_OK, 
                                        GTK_STOCK_CANCEL, 
                                        GTK_RESPONSE_CANCEL,  
                                        NULL);

    gtk_window_set_default_size(GTK_WINDOW(dialog), 400, 200);

    hbox1 = gtk_hbox_new(FALSE, 0);
    hbox2 = gtk_hbox_new(FALSE, 0);

	// add both hboxex in dailog content area
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), 
                        hbox1, FALSE, FALSE, 20);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), 
                        hbox2, FALSE, FALSE, 20);

    // create the IP label
    ipLabel = gtk_label_new("IP Address:");

	// create the port label
	portLabel = gtk_label_new("Port:");

    // create the ip adress text box
    ipTextBox = gtk_entry_new();

    // create the port text box
    portTextBox = gtk_entry_new();

    // set current default IP in ip text box
    gtk_entry_set_text(GTK_ENTRY(ipTextBox), Helper::getVar(wansConfFile, "DD_IP").c_str());

    // set current default port in port text box
    gtk_entry_set_text(GTK_ENTRY(portTextBox), Helper::getVar(wansConfFile, "DD_PORT").c_str());

    // add ip label and textbox to hbox1
    gtk_box_pack_start(GTK_BOX(hbox1), ipLabel, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox1), ipTextBox, TRUE, TRUE, 10);

    // add port label and textbox to hbox2
    gtk_box_pack_start(GTK_BOX(hbox2), portLabel, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox2), portTextBox, TRUE, TRUE, 10);

    // display all widgets in dialog
    gtk_widget_show_all(GTK_DIALOG(dialog)->vbox);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK)
    {
        editDefaultDestination();
    }

    gtk_widget_destroy (dialog);
}

// returns the wans conf file path
string DdEditorDialog::getConfFile()
{
    return wansConfFile;
}

// edits MO File Path as entered by user
void DdEditorDialog::editDefaultDestination()
{
	// get the bin dir path
	string binDir = Helper::getVar(getConfFile(), "BIN_DIR");

	// get ip text box value
	string ip = gtk_entry_get_text(GTK_ENTRY(ipTextBox));

	// get port text box value
	string port = gtk_entry_get_text(GTK_ENTRY(portTextBox));

	// create the command to update wans conf file DD_IP
	string cmd = binDir + "/" + "editConf.sh " + getConfFile() + " DD_IP " + ip;
	
	// update ip
	system(cmd.c_str());
	
	// create the command to update wans conf file DD_PORT
	cmd = binDir + "/" + "editConf.sh " + getConfFile() + " DD_PORT " + port;
	
	// update port
	system(cmd.c_str());

    cout << "Default Destination Updated" << endl;
}

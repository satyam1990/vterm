/******************************************************************************
 *
 * EventHandler.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements the event handlers for processing signals emitted by
 * different widgets only from Main Window
 *
 * ***************************************************************************/

#include "EventHandler.hh"

#include "MoPathEditorDialog.hh"
#include "MmlPathEditorDialog.hh"
#include "DdEditorDialog.hh"

// launches edit MO path dialog
void EventHandler::editMOPath(GtkWidget *widget, gpointer data)
{
	cout << "Edit MO Path Handler" << endl;

	MainWindow* mainWin = static_cast<MainWindow*>(data);
	MoPathEditorDialog moEditor(mainWin->getConfFile());
}

// launches dialog for editing MML reponse path directory
void EventHandler::editMMLPath(GtkWidget *widget, gpointer data)
{
	cout << "Edit MML Path Handler" << endl;

	MainWindow* mainWin = static_cast<MainWindow*>(data);
	MmlPathEditorDialog mmlEditor(mainWin->getConfFile());
}

// launches dialog for editing default destination
void EventHandler::editDefaultDestination(GtkWidget *widget, gpointer data)
{
	cout << "Edit Default Destination Handler" << endl;

	MainWindow* mainWin = static_cast<MainWindow*>(data);
	DdEditorDialog ddEditor(mainWin->getConfFile());
}

// launches dialog to send custom alarms
void EventHandler::customAlarmHandler(GtkWidget *widget, gpointer data)
{
	cout << "Send Custom Alarm Handler" << endl;
}

// launches help dialog
void EventHandler::helpHandler(GtkWidget *widget, gpointer data)
{
	cout << "Help Handler" << endl;
}

// starts the Simulated NODE
void EventHandler::startNE(GtkWidget *widget, gpointer data)
{
	MainWindow* mainWin = static_cast<MainWindow*>(data);

	// disable the start button
	mainWin->disableStartButton();

	// enable the stop button
	mainWin->enableStopButton();

	// start the NE using start script
	string binDir = Helper::getVar(mainWin->getConfFile(), "BIN_DIR");
	string cmd = binDir + "/startNE.sh" + " " + binDir;
	system(cmd.c_str());

	// change NODE status
	mainWin->toggleNodeStatus();
	cout << "NE Started" << endl;
}

// stops the Simulated NODE
void EventHandler::stopNE(GtkWidget *widget, gpointer data)
{
	MainWindow* mainWin = static_cast<MainWindow*>(data);

	// disable the stop button
	mainWin->disableStopButton();

	// enable the start button
	mainWin->enableStartButton();

	// stop the NE using stop script
	string binDir = Helper::getVar(mainWin->getConfFile(), "BIN_DIR");
	string cmd = binDir + "/stopNE.sh";
	system(cmd.c_str());

	// change NODE status
	mainWin->toggleNodeStatus();
	cout << "NE Stopped" << endl;
}

// sends default alarm using alarm initiator
void EventHandler::sendAlarmHandler(GtkWidget *widget, gpointer data)
{
	MainWindow* mainWin = static_cast<MainWindow*>(data);
	
	// send alarm using alarmInitiator binary
	string binDir = Helper::getVar(mainWin->getConfFile(), "BIN_DIR");

	string cmd = binDir + "/alarmInitiator " + mainWin->getConfFile();

	// send the alarm
	system(cmd.c_str());

	cout << "Alarm Sent" << endl;
}

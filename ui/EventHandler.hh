/******************************************************************************
 *
 * EventHandler.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements the event handlers for processing signals emitted by
 * different widgets
 *
 * ***************************************************************************/

#if !defined(EVENT_HANDLER_HH)
#define EVENT_HANDLER_HH

#include <iostream>
#include <gtk/gtk.h>

#include "MainWindow.hh"

using namespace std;

class EventHandler {

	public:

		// closes main window
		static void onWindowClose(GtkWidget* widget, gpointer data);

		// launches edit MO path dialog
		static void editMOPath();

		// launches dialog for editing MML reponse path directory
		static void editMMLPath();

		// launches dialog for editing default destination
		static void editDefaultDestination();

		// launches dialog to send custom alarms
		static void customAlarmHandler();

		// launches help dialog
		static void helpHandler();

		// starts the Simulated NODE
		static void startNE(GtkWidget *widget, gpointer data);

		// stops the Simulated NODE
		static void stopNE(GtkWidget *widget, gpointer data);

		// sends default alarm using alarm initiator
		static void sendAlarmHandler();
};
#endif


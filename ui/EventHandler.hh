/******************************************************************************
 *
 * EventHandler.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements the event handlers for processing signals emitted by
 * different widgets only from Main Window
 *
 * ***************************************************************************/

#if !defined(EVENT_HANDLER_HH)
#define EVENT_HANDLER_HH

#include <iostream>
#include <cstdlib>
#include <gtk/gtk.h>

#include "MainWindow.hh"

using namespace std;

class EventHandler {

	public:

		// launches edit MO path dialog
		static void editMOPath(GtkWidget *widget, gpointer data);

		// launches dialog for editing MML reponse path directory
		static void editMMLPath(GtkWidget *widget, gpointer data);

		// launches dialog for editing default destination
		static void editDefaultDestination(GtkWidget *widget, gpointer data);

		// launches dialog to send custom alarms
		static void customAlarmHandler(GtkWidget *widget, gpointer data);

		// launches help dialog
		static void helpHandler(GtkWidget *widget, gpointer data);

		// starts the Simulated NODE
		static void startNE(GtkWidget *widget, gpointer data);

		// stops the Simulated NODE
		static void stopNE(GtkWidget *widget, gpointer data);

		// sends default alarm using alarm initiator
		static void sendAlarmHandler(GtkWidget *widget, gpointer data);
};
#endif


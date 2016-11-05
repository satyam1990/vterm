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

using namespace std;

class EventHandler {

	public:

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
		static void startNE();

		// stops the Simulated NODE
		static void stopNE();

		// sends default alarm using alarm initiator
		static void sendAlarmHandler();
};
#endif

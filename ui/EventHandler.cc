/******************************************************************************
 *
 * EventHandler.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements the event handlers for processing signals emitted by
 * different widgets
 *
 * ***************************************************************************/

#include "EventHandler.hh"

// launches edit MO path dialog
void EventHandler::editMOPath()
{
	cout << "Edit MO Path Handler" << endl;
}

// launches dialog for editing MML reponse path directory
void EventHandler::editMMLPath()
{
	cout << "Edit MML Path Handler" << endl;
}

// launches dialog for editing default destination
void EventHandler::editDefaultDestination()
{
	cout << "Edit Default Destination Handler" << endl;
}

// launches dialog to send custom alarms
void EventHandler::customAlarmHandler()
{
	cout << "Send Custom Alarm Handler" << endl;
}

// launches help dialog
void EventHandler::helpHandler()
{
	cout << "Help Handler" << endl;
}

// starts the Simulated NODE
void EventHandler::startNE()
{
	cout << "Start NE" << endl;
}

// stops the Simulated NODE
void EventHandler::stopNE()
{
	cout << "Stop NE" << endl;
}

// sends default alarm using alarm initiator
void EventHandler::sendAlarmHandler()
{
	cout << "Send Alarm Handler" << endl;
}

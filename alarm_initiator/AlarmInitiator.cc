/******************************************************************************
 *
 * AlarmInitiator.cc
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements alarm generation feature in order to send alarms to OSS
 * applications.
 *
 * ***************************************************************************/

#include "AlarmInitiator.hh"
/*
 = {
								
                                };*/
// intializes required data
AlarmInitiator::AlarmInitiator(string confFile)
{
	// store the wans conf file path
	wansConfFile = confFile;

	// fetch IP and Port from wans conf file
	ip = Helper::getVar(wansConfFile, "DD_IP");
	port = Helper::getVar(wansConfFile, "DD_PORT");

	ossServerfd = 0;
	alarm = "";

	alarmData.push_back(":type=alarm");
	alarmData.push_back(":type=alarm");
	alarmData.push_back("cpside=ex");
	alarmData.push_back("device=AD-0");
	alarmData.push_back("prca=42");
	alarmData.push_back("prseqno=0");
	alarmData.push_back("altype=new");
	alarmData.push_back("alcls=2");
	alarmData.push_back("alcat=8");
	alarmData.push_back("alseqno=0");
	alarmData.push_back("alno=111");
	alarmData.push_back("alvisno=0");
	alarmData.push_back(";");
	alarmData.push_back(ALARM_HEADER1);
	alarmData.push_back(ALARM_HEADER2);
	alarmData.push_back("SATYAM");
	alarmData.push_back("\r\nEND\r\n\r\n\04\00");
}

// makes a TCP connection with the OSS server
void AlarmInitiator::connectToOss()
{
	// stores address of the remote server to connect
	struct sockaddr_in server_addr;

	// create the socket
	ossServerfd = socket(AF_INET, SOCK_STREAM, 0);
	if (ossServerfd == -1)
	{
		cerr << "Error: Creating Socket" << endl;
		exit(-1);
	}

	// initialize the sockaddr
	memset(&server_addr, 0, sizeof(server_addr));

	// store server deatils as passed in arguments
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	server_addr.sin_port = htons(atoi(port.c_str()));

	// make connection to the OSS server
	if (connect(ossServerfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
	{
		cerr << "Error: Connecting to OSS Server" << endl;
		exit(-1);
	}
}

// building the as a one string from all alarm attributes
void AlarmInitiator::buildAlarm()
{
	alarm = "";

	for (int i = 0; i < ATTRIBUTE_COUNT; i++)
	{
		alarm += alarmData[i];
		if (i < separator)
		{
			alarm +=",";
		}
	}

	cout << "Alarm Length: " << alarm.length() << endl;

}

// sends alarm to the OSS server
bool AlarmInitiator::sendAlarm()
{
	int result = write(ossServerfd, alarm.c_str(), alarm.length());

	if (result == alarm.length())
	{
		return true;
	}

	return false;
}

// disconnect the connection
void AlarmInitiator::disconnect()
{
	close(ossServerfd);
}

// returns oss server file descriptor
int AlarmInitiator::getfd()
{
	return ossServerfd;
}

// return alarm that need to be sent to OSS server
string AlarmInitiator::getAlarm()
{
	return alarm;
}

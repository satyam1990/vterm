/******************************************************************************
 *
 * AlarmInitiator.hh
 *
 * Author: msatyam
 *
 * November, 2016
 *
 * Implements alarm generation feature in order to send alarms to OSS
 * applications.
 *
 * ***************************************************************************/

#if !defined(ALARM_INITIATOR_HH)
#define ALARM_INITIATOR_HH

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include <Helper.hh>

#define ATTRIBUTE_COUNT 16
#define ALARM_HEADER1 "\r\nWO      SSC01/GSM/BSC/G15B-APG43/ AD-0    TIME 160830 1244  PAGE    1\r\n"
#define ALARM_HEADER2 "*** ALARM 111 A3/POWER \"SSC01\"U 160830 1244\r\n"

enum AlarmAttributes {type, cpside, device, prca, prseqno, altype, alcls, 
						alcat, alseqno, alno, alvisno, separator, header1,
						header2, alarmtext, footer};
class AlarmInitiator {

	private:
		vector<string> alarmData;

		// alarm to send
		string alarm;

		// path to wans conf file
		string wansConfFile;

		// IP address to connect with
		string ip;

		// Port to connect with
		string port;

		// OSS server socket file descriptor
		int ossServerfd;

	public:
		// intializes required data
		AlarmInitiator(string confFile);

		// makes a TCP connection with the OSS server
		void connectToOss();

		// building the as a one string from all alarm attributes
		void buildAlarm();

		// sends alarm to the OSS server
		bool sendAlarm();

		// disconnect the connection
		void disconnect();

		// returns oss server file descriptor
		int getfd();

		// return alarm that need to be sent to OSS server
		string getAlarm();
};
#endif

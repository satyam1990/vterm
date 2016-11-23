#include "AlarmInitiator.hh"

int main(int argc, char* argv[])
{
	// validate proper usage
	if (argc != 2 )
	{
		cerr << "Usage:" << argv[0] << "<wans conf file path>" << endl;
		exit(-1);
	}

	// intantiate the alarm initiator object
	AlarmInitiator alarmGenerator(argv[1]);

	// build the alarm
	alarmGenerator.buildAlarm();

	// connect to the OSS server
	alarmGenerator.connectToOss();

	// send the alarm
	alarmGenerator.sendAlarm();

	// disconnect
	alarmGenerator.disconnect();

	return 0;
}

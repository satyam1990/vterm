#include "AlarmInitiator.hh"

int main(int argc, char* argv[])
{
	// validate proper usage
	if (argc != 2 )
	{
		cerr << "Usage:" << argv[0] << "<wans conf file path>" << endl;
		exit(-1);
	}

	AlarmInitiator alarmGenerator(argv[1]);
	return 0;
}
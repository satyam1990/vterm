/******************************************************************************
 *
 * Terminal.hh
 *
 * Author: mSatyam
 *
 * 2016, September
 *
 * Represents our virtual terminal which accepts user input in non-canonical 
 * mode , processes it and displays desired output to the user.
 *
 * ***************************************************************************/

#if !defined(TERMINAL_HH)
#define TERMINAL_HH

#define TAB '\t'
#define BACKSPACE 8
#define DELETE 127
#define ENTER '\n'
#define CR '\r'

#include <sys/termios.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>

#include "MMLProcessor.hh"
#include "APLOCProcessor.hh"
#include "MMLResponse.hh"
#include "APLOCResponse.hh"

class Terminal {

	private:
		// XML file name
		string xmlFile;

		// represents command text till now typed on our terminal
		string command;

		// states whether config mode is on or off
		bool aplocMode;

		// processes APLOC commands
		APLOCProcessor* aplocProcessor;

		// processes MML commands
		MMLProcessor* mmlProcessor;

		// states whether user want to exit or not
		bool isExitCommand;

		// initial terminal settings
		struct termios initial_settings;

	public:
		// initializes required stuff for our terminal
		Terminal(string mo_xml_file = "");

		// de-allocates necessary stuff
		~Terminal();

		// logins the user to the NODE
		bool login();

		// main loop of our terminal which keeps on accepting user input
		// processes it and displays desired results
		void main();

		// each input character is forwarded here for processing
		// then this function further decides what other input
		// processing functions to call
		void processInput(char c);

		// sends command for processing to respective processor
		// and gets the output
		void processCommand();

		// processes response and displays output if any
		void processAndDisplay(Response resp);

		// removes one character from the end from our command when backspace 
		// key is pressed
		void processBackspace();

		// sets the terminal in non-canonical mode
		void setTerminalAttributes();

		// resets the terminal to its original state
		void resetTerminalAttributes();

		string getCommand();
};
#endif

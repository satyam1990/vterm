/******************************************************************************
 *
 * Terminal.hh
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * Represents our virtual terminal which accepts user input in non-canonical 
 * mode , processes it and displays desired output to the user.
 *
 * ***************************************************************************/

#if !defined(TERMINAL_HH)
#define TERMINAL_HH

#include "MoTree.hh"
#include "MoList.hh"
#include "Mo.hh"
#include "headers.hh"
#include <sys/termios.h>
#include <unistd.h>

class Terminal {

	private:
		// represents our terminal's prompt
		string prompt;

		// represents command text till now typed on our terminal
		string command;

		// represents the output of the command entered
		string output;

        // states whether config mode is on or off
        bool configMode;

		// our MO Tree
		MoTree* ourMoTree;

		// our current MO
		Mo* currentMo;

        // initial terminal settings
        struct termios initial_settings;

	public:
		// initializes required stuff for our terminal
		Terminal();

        // logins the user to the NODE
        bool login();

		// main loop of our terminal which keeps on accepting user input
		// processes it and displays desired results
		void main();

		// each input character is forwarded here for processing
		// then this function further decides what other input
		// processing functions to call
		void processInput(char c);

		// handles tab autocomplete functionality
		void processTab();

		// checks if a valid MO name is typed at the terminal,
		// if it is a valid MO then update the prompt to that MO and
		// sets respective command output if MO also has a output associated with it
		void processEnter();

		// removes one character from the end from our command when backspace 
		// key is pressed
		void processBackspace();

        // checks whether it is a special commmand 
        // special commands for now are (end and up).
		bool isSpecialCommand();

        // handle special commands
        void processSpecialCommand();

		// handles non-MO commands
		void processNonMoCommand();

        // handles mml command
        void processMMLCommand();

		// handles Interactive commands which requires further user input
		void processInteractive();

        // sets the terminal in non-canonical mode
        void setTerminalAttributes();

        // resets the terminal to its original state
        void resetTerminalAttributes();

		string getPrompt();

		string getCommand();

		string getOutput();
};
#endif
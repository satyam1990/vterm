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

class Terminal {

	private:
		// represents our terminal's prompt
		string prompt;

		// represents command text till now typed on our terminal
		string command;

		// represents the output of the command entered
		string output;

		// our MO Tree
		MoTree* ourMoTree;

		// our current MO
		Mo* currentMo;

	public:
		// initializes required stuff for our terminal
		Terminal();

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

		// checks whether it is a non-MO commmand (like exit, up) etc.
		bool isNonMoCommand();

		// handles non-MO commands
		void processNonMoCommads();

		// handles Interactive commands which requires further user input
		void processInteractive();

		string getPrompt();

		string getCommand();

		string getOutput();
};
#endif

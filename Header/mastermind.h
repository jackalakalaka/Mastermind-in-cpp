#pragma once
/**mastermind.h*/
/* Project1     Dave Pleteau and Jack Carson						    */
/* Header file that defines the mastermind class						*/

#include <stdint.h>
#include "code.h"
#include "response.h"

#define CODE_LENGTH			(0x05)
#define DIGIT_RANGE			(0x0A)


class mastermind
{
public:
	//Constructors that if not inputted to, set n=5 and m=10
	mastermind();
	mastermind(uint32_t n, uint32_t m);

	//Prints secret code
	void printSecretCode();

	//Guess code obj
	code humanGuess();

	//Retrieves response for a guess
	response getResponse(code const &guess);

	//Checks in player has won
	bool isSolved(response const& guessResp);

	//Begins a game
	void playGame();

private:
	code secretCode;
	
	//Helper function for getResponse that returns response for a guess
	response checkGuess(const vector<uint32_t>& guess);

};



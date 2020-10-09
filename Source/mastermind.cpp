/* mastermind.cpp */
/* Project1  Dave Pleteau and Jack Carson	                  */
/* cpp file that contains the mastermind class implementation */

#include <iostream>
#include <string>
#include <vector>
#include "code.h"
#include "response.h"
#include "mastermind.h"

/* MACRO for max user attempts */
#define MAX_ATTEMPTS		(0x0A)  

mastermind::mastermind()
/**
* Initializes a mastermind game. Sets code object's code length and range of
* digits to 0.
* @param	none
* @param	none
* @retval	none
*/
{
	/* Create a temp Code object to copy to secretCode object */
	code tempCode(CODE_LENGTH, DIGIT_RANGE);
	secretCode = tempCode;
}//end mastermind constr #1

mastermind::mastermind(uint32_t n, uint32_t m)
/**
* Initializes a mastermind game. Sets code object's code length and range of
* digits to n and m.
* @param	n:	code length
* @param	m:	range of digits
* @retval	none
*/
{
	/* Create a temp Code object to copy to secretCode object */
	code tempCode(n, m);
	secretCode = tempCode;
}//end mastermind constr #2

void mastermind::printSecretCode()
/**
* Prints game's secret code
* @param	none
* @retval	none
*/
{
	std::cout << secretCode;
}//end mastermind::printSecretCode

code mastermind::humanGuess()
/**
* Reads a guess from the keyboard and returns a code object that represents the
			guess.
* @param	none
* @retval	retCode: code object that represents user's guess. If guessed code
*			is valid, retCode will store it and set the "set" flag true.
*			If guess code is invalid, retCode will have default constructor 
*			value {code length = 0, digit = range 0, and set = false}
*/
{
	bool error = false;/* Tracks whether user has inputted an incorrect value */
	
	/* Vector for user's guess */
	std::vector<uint32_t> guess(secretCode.getCodeLen(), 0);
	/* Read and store user's guess input */
	std::cout << "\nEnter your guess code: ";

	for (uint32_t i = 0; i < guess.size(); i++)
	{

		int val = 0; //Initialize int input that will be parsed from string

		//Initialize and pass in string input
		std::string x = "";
		std::cin >> x;

		/* Check if guess input is a positive interger */
		try
		{

			val = stoi(x); //Parses str val into int

			/* If guessed number is negative throw out of range error */
			if (val < 0) { throw std::out_of_range{ "" }; }

			/* Else assign val to be guess code vector */
			else { guess[i] = val; }

		}

		/* Set error flag true to indicate user inputed bad value */
		catch (std::invalid_argument& e){ error = true; }
		/* Set error flag true to indicate user inputed bad value */
		catch (std::out_of_range& e){ error = true; }
	}

	code retCode; /* code object that represents the user's guess */

	/* If there were no errors, return a code object with guess vector values*/
	if (!error)
	{
		retCode.setCode(guess);
	}

	/* else return code object with "set" flag as false */
	return retCode;
}//end mastermind::humanGuess

response mastermind::getResponse(code const& guess)
/**
* Inspects a valid guess code, returns a response object that stores the number
			of correct/incorrect digits in guess's code
* @param	guess: code object that represents user's guest
* @retval	guessResp: response object representing # correct/incorrect digits
*			from user's guess.
*/
{
	response guessResp;
	if (guess.getSetFlag())
	{
		/* Calculate Response */
		const std::vector<uint32_t> v = guess.getCode();
		guessResp = checkGuess(guess.getCode());
	}
	else
	{
		/* User inputted invalid guess */
		std::cout << "\nInvalid Guess";
	}

	return guessResp;
}//mastermind::getResponse

bool mastermind::isSolved(const response& guessResp)
/**
* Indicates if the board is solved by comparing a secretCode response obj and 
*			a guess response
* @param	guessResp: response object representing # correct/incorrect digits
*			from user's guess.
* @retval	solved: boolean to indicate board is solved or not 		
*/
{
	response secretCodeResp;
	secretCodeResp.setCorrect(secretCode.getCodeLen());
	return guessResp == secretCodeResp;
}//end mastermind::isSolved


void mastermind::playGame()
/**
* Sets up a game session that lets the user guess up to 10 attempts as many as a
* win takes, printing messages for each.
* @param	none
* @retval	none
*/
{
	//Generate and print secret code for debugging purposes
	secretCode.genCode(); std::cout << secretCode;

	//Initializes attempt counter, win flag, and a guess/response
	uint32_t attempts = 1;
	bool won;
	code guess;
	response resp;

	//Each sequence corresponds to a turn. The loop ends after a win or loss
	while (1) {
		
		//Retrieve corresponding response to user-entered guess
		resp = getResponse(humanGuess());
		//Check if guess is a winning one
		won = isSolved(resp);

		//Win
		if (won) {
			std::cout << "\nYou cracked the code!";
			break;
		}

		//Incorrect guess w/ attempts left
		else if (attempts < MAX_ATTEMPTS) {
			std::cout << "Results: " << resp << "    Attempts left: " <<
				MAX_ATTEMPTS - attempts++;
		}

		//Loss
		else {
			std::cout << "\n You've reached max attempts. The code was: " 
					  << secretCode << "\n Good Luck Next Time!";
			break;
		}
	}//end while
}//end mastermind::playGame




response mastermind::checkGuess(const vector<uint32_t>& guess)
/**
* Searches a user's guess and determines the number of correct digits in the
*			incorrect location. No digit in code/guess is counted repeatedly
* @param	guess:	vector containing user's guess of the secret code
* @retval	response: response to user's guess
*/
{
	/* Stores guess values that are correct but not at the right location */
	std::vector<uint32_t> incorrectCountLoc;

	/* Stores secret code vector values */
	std::vector<uint32_t> secretCodeVec = secretCode.getCode();

	/* Stores the location of elements in guess code that aren't correct nor in
	the correct location */
	std::vector<uint32_t> loc;

	/* Number of correct numbers in the correct position */
	uint32_t corr;

	/* Number of correct numbers in the incorrect position */
	uint32_t incorr;

	for (uint32_t i = 0; i < secretCodeVec.size(); i++)
	{
		/* If dig in index i in guess and code_seq are not identical nor in same
		loc, add index i to loc vector */
		if (guess[i] != secretCodeVec[i])
		{
			loc.push_back(i);
		}
	}
	/* correct values must equal guess vector size - loc vector size since */
	/* loc vector holds all values that are not identical nor in same loc */
	corr = guess.size() - loc.size();

	/* Loop To determine correct digits in incorrect positions in guess code */
	for (uint32_t i = 0; i < loc.size(); i++)
	{
		for (uint32_t j = 0; j < loc.size(); j++)
		{
			/* If secret code and guess code share a similar number but at
			different position, then inspect to see if this value has been
			accounted for */
			if (secretCodeVec[loc[j]] == guess[loc[i]])
			{

				bool noReps = true; /* Flag to indicate if current value has
									already been counted */

				/* If this is the first value being added to
				incorrectCountLoc then no need to check for repitition, just add
				it  */

				if (incorrectCountLoc.empty())
				{
					incorrectCountLoc.push_back(secretCodeVec[loc[j]]);
					break;
				}

				/* Check if we already added a similar value */
				/* If we did, set noReps flag to false to prevent adding value
				to incorrectCountLoc */

				for (uint32_t k = 0; k < incorrectCountLoc.size(); k++)
				{
					if (guess[loc[i]] == incorrectCountLoc[k]) { noReps = false; break; }                      
				}

				if (noReps)
				{
					incorrectCountLoc.push_back(secretCodeVec[i]); /* No repition so add value
																   to vector */
				}
			}//end if (secretCodeVec[loc[j]] == guess[loc[i]])

		}//end j for
	}//end i for

	/* Number of correct numbers in the incorrect position */
	incorr = incorrectCountLoc.size();

	/* Create a Response to user's guess */
	response guessResponse;
	guessResponse.setCorrect(corr);
	guessResponse.setIncorrect(incorrectCountLoc.size());

	return guessResponse;
}
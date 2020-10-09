/* main.cpp */
/* Project1 Dave Pleteau and Jack Carson */
/* main program file for project 1.	*/
/* Initializes a code object, polls user inputted guess, and prints out the
/* the results of the game. */

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <string>
#include <vector>
#include "code.h"
#include "response.h"
#include "mastermind.h"

int main()
{
	//Initialize n & m and retrieve from player
	uint32_t n, m;
	std::cout << "Enter Code Length: "; std::cin >> n;
	std::cout << "\nEnter Range of Digits: "; std::cin >> m;

	//Start game w/ n & m vals
	mastermind game1(n, m); /* Initialize code object */
	game1.playGame();

	return 0;
}
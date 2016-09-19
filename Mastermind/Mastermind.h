#pragma once
#include "Code.h"
#include "Response.h"

#ifndef MASTERMIND_H
#define MASTERMIND_H

class Mastermind
{
private:
	Code code;
	void const printCode();
	Code const humanGuess(); // take a guess from player keyboard
	Response const getResponse(Code& guess, Code& secretCode); // generate a response based on two codes
	bool const isSolved(Response& response); // returns true if the player has guessed the code
public:
	void playGame(); // structure of game; generates code and takes in guesses in a loop
};

#endif
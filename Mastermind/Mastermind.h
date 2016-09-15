#pragma once
#include "Code.h"
#include "Response.h"

#ifndef MASTERMIND_H
#define MASTERMIND_H

class Mastermind
{
private:
	Code code;
	void printCode();
	Code humanGuess();
	Response getResponse(Code guess, Code secretCode);
	bool isSolved(Response response);
public:
	void playGame();
};

#endif
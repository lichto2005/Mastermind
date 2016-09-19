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
	Code const humanGuess();
	Response const getResponse(Code guess, Code secretCode);
	bool const isSolved(Response response);
public:
	void playGame();
};

#endif
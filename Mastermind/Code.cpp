#include "Code.h"
#include <time.h>

Code::Code()
{
}

Code::~Code()
{
}

void Code::initializeCode()
{
	// generate a random seed based on the current time
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		//add a random number in [0,5] to code vector
		secretCode.push_back(rand() % 6);
	}
}

int const Code::checkCorrect(const Code& guess)
{
	int correct = 0;
	// for each digit
	for (int i = 0; i < secretCode.size(); i++)
	{
		// if the digit in position i matches the secretcode add 1 to correct
		if (secretCode.at(i) == guess.secretCode.at(i)) correct++;
	}
	// return num correct
	return correct;
}

int const Code::checkIncorrect(const Code& guess)
{
	int incorrect = 0;
	// for each digit in the guess code
	for (int i = 0; i < secretCode.size(); i++)
	{
		// if the digit is correct and in the correct place, move to next digit
		if (guess.secretCode.at(i) == secretCode.at(i)) continue;
		// else, for each digit in the secret code
		for (int j = 0; j < secretCode.size(); j++)
		{
			// if digit in the same position, move to next place
			if (j == i) continue;
			// else if the guess digit is contained in the secret code
			if (guess.secretCode.at(i) == secretCode.at(j))
			{
				// add 1 to incorrect and move to the next guess digit
				incorrect++;
				break;
			}
		}
	}
	// return num incorrect
	return incorrect;
}

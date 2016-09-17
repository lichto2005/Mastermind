#include <random>
#include "Code.h"


Code::Code()
{
}


Code::~Code()
{
}

void Code::initializeCode()
{
	for (int i = 0; i < 4; i++)
	{
		//add a random number in [0,5] to code vector
		secretCode.push_back(rand() % 6);
	}
}

int Code::checkCorrect(Code guess)
{
	int correct = 0;
	for (int i = 0; i < secretCode.size(); i++)
	{
		if (secretCode.at(i) == guess.secretCode.at(i)) correct++;
	}
	return correct;
}

int Code::checkIncorrect(Code guess)
{
	int incorrect = 0;
	for (int i = 0; i < secretCode.size(); i++)
	{
		for (int j = 0; j < secretCode.size(); j++)
		{
			if (j == i) continue;
			if (secretCode.at(i) == guess.secretCode.at(j))
			{
				incorrect++;
				break;
			}
		}
	}
	return incorrect;
}

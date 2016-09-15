// Mastermind.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Mastermind.h"
#include "Code.h"


int main()
{
    return 0;
}

void Mastermind::printCode()
{
	std::cout << "Secret Code: ";
	for (int i = 0; i < code.secretCode.size(); i++)
	{
		std::cout << code.secretCode.at(i);
	}
	std::cout << "\n";
}

Code Mastermind::humanGuess()
{
	int guess;
	bool isValid = false;
	do
	{
		Code code;
		std::cin >> guess;
		if (guess < 0)
		{
			std::cout << "Invalid entry\n";
			continue; //no negative
		}
		if (guess / 1000 > 5)
		{
			std::cout << "Invalid entry\n";
			continue; //4 digit guesses
		}
		for (int i = 0; i < 4; i++)
		{
			int remainder = guess % 10;
			if (remainder > 5)
			{
				std::cout << "Invalid entry\n";
				break;
			}
			code.secretCode.insert(code.secretCode.begin(), remainder);
			guess /= 10;
			if (i == 3) isValid = true;
		}
	} while (!isValid);
	return code;
}

Response Mastermind::getResponse(Code guess, Code secretCode)
{
	Response response;
	response.setCorrect(secretCode.checkCorrect(guess));
	response.setIncorrect(secretCode.checkIncorrect(guess));
	return Response();
}

bool Mastermind::isSolved(Response response)
{
	Response correctResponse;
	correctResponse.setCorrect(4);
	correctResponse.setIncorrect(0);
	return response.compareResponse(response, correctResponse);
}

void Mastermind::playGame()
{
	code.initializeCode();
	this->printCode();
	
}

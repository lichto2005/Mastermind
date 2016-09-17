// Mastermind.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Mastermind.h"
#include "Code.h"


int main()
{
	//init mastermind object and start game
	Mastermind mastermind;
	mastermind.playGame();

	//pause the program to prevent window from closing
	std::cin.get();
	std::cin.ignore();
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
	Code returnCode;
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
			if (i == 3)
			{
				returnCode = code;
				isValid = true;
			}
		}
	} while (!isValid);
	return returnCode;
}

Response Mastermind::getResponse(Code guess, Code secretCode)
{
	Response response;
	response.setCorrect(secretCode.checkCorrect(guess));
	response.setIncorrect(secretCode.checkIncorrect(guess));
	return response;
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
	printCode();
	bool playerWin = false;
	for (int i = 0; i < 10; i++)
	{
		Code guess = humanGuess();
		Response response = getResponse(guess, code);
		response.printResponse();
		if (isSolved(response))
		{
			playerWin = true;
			break;
		}
	}
	
	if (playerWin) std::cout << "Player wins!\n";
	else std::cout << "Computer wins!\n";
}

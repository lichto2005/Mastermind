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
	int digit;
	bool isValid = false;
	do
	{
		Code code;
		for (int i = 0; i < 4; i++)
		{
			std::cin >> digit;
			if (digit > 5 || digit < 0)
			{
				std::cout << "Invalid Entry, reenter code.\n";
				break;
			}

			code.secretCode.push_back(digit);

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
	std::cout << "Enter digits with white spaces inbetween or one per line.\n";
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

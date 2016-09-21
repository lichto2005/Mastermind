#include <iostream>
#include "Mastermind.h"
#include "Code.h"

void const Mastermind::printCode()
{
	std::cout << "Secret Code: ";
	for (int i = 0; i < code.secretCode.size(); i++)
	{
		std::cout << code.secretCode.at(i);
	}
	std::cout << "\n";
}

Code const Mastermind::humanGuess()
{
	Code returnCode;
	int digit;
	bool isValid = false;
	// do while loop to take user input from keyboard
	do
	{
		Code code;
		// take in 4 digits
		for (int i = 0; i < 4; i++)
		{
			// read from cin
			std::cin >> digit;
			// if digit is not in the range [0,5] reject code and start over
			if (digit > 5 || digit < 0)
			{
				std::cout << "Invalid Entry, reenter code.\n";
				break;
			}

			// if digit is in the range, add it to the code
			code.secretCode.push_back(digit);

			// if taken in 4 numbers all correct, input is valid
			if (i == 3)
			{
				returnCode = code;
				isValid = true;
			}
		}
	} while (!isValid); // while not valid
	return returnCode; // return error checked code object
}

Response const Mastermind::getResponse(Code& guess, Code& secretCode)
{
	// use guess and secretCode to creat a response and return it
	Response response;
	response.setCorrect(secretCode.checkCorrect(guess));
	response.setIncorrect(secretCode.checkIncorrect(guess));
	return response;
}

bool const Mastermind::isSolved(Response& response)
{
	// define a correct response (4, 0) and compare a response to the correct response
	Response correctResponse;
	correctResponse.setCorrect(4);
	correctResponse.setIncorrect(0);
	return correctResponse.compareResponse(response);
}

void Mastermind::playGame()
{
	// create the random code
	code.initializeCode();
	// print to screen
	printCode();
	// promt user iwth instructions
	std::cout << "Enter digits with white spaces inbetween or one per line.\n";
	// while player has not won
	bool playerWin = false;
	// loop up to 10 times
	for (int i = 0; i < 10; i++)
	{
		// get a guess, print the response, check if player wins
		Code guess = humanGuess();
		Response response = getResponse(guess, code);
		response.printResponse();
		if (isSolved(response))
		{
			// if win set win condition and break
			playerWin = true;
			break;
		}
	}
	
	// print win or lose based on the win condition
	if (playerWin) std::cout << "Player wins!\n";
	else std::cout << "Computer wins!\n";
}

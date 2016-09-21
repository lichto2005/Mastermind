#include "Response.h"


Response::Response()
{
}

Response::~Response()
{
}

int const Response::getCorrect()
{
	return correct;
}

void Response::setCorrect(int correct)
{
	this->correct = correct;
}

int const Response::getIncorrect()
{
	return incorrect;
}

void Response::setIncorrect(int incorrect)
{
	this->incorrect = incorrect;
}

bool const Response::compareResponse(const Response& response)
{
	// if num correct and num incorrect digits are the same, response is the same; return true
	return response.correct == this->correct && response.incorrect == this->incorrect;
}

void const Response::printResponse()
{
	std::cout << "(" << correct << ", " << incorrect << ")\n";
}

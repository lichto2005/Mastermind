#include "stdafx.h"
#include "Response.h"


Response::Response()
{
}


Response::~Response()
{
}

int Response::getCorrect()
{
	return correct;
}

void Response::setCorrect(int correct)
{
	this->correct = correct;
}

int Response::getIncorrect()
{
	return incorrect;
}

void Response::setIncorrect(int incorrect)
{
	this->incorrect = incorrect;
}

bool Response::compareResponse(Response x, Response y)
{
	return x.getCorrect() == y.getCorrect() && x.getIncorrect() == y.getIncorrect();
}

void Response::printResponse()
{
	std::cout << "(" << correct << ", " << incorrect << ")\n";
}

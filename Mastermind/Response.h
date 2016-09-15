#pragma once
#include <iostream>

#ifndef RESPONSE_H
#define RESPONSE_H

class Response
{
private:
	int correct = 0, incorrect = 0;
public:
	Response();
	~Response();
	int getCorrect();
	void setCorrect(int correct);
	int getIncorrect();
	void setIncorrect(int incorrect);
	const bool compareResponse(Response x, Response y);
	void printResponse();
};

#endif
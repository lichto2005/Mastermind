#include <iostream>

#ifndef RESPONSE_H
#define RESPONSE_H

// class to hold correct and incorrect parts of a guess
class Response
{
private:
	int correct = 0, incorrect = 0;
public:
	Response();
	~Response();
	int const getCorrect();
	void setCorrect(int correct);
	int const getIncorrect();
	void setIncorrect(int incorrect);
	bool const compareResponse(const Response& response); //compare a response to this response
	void const printResponse();
};

#endif
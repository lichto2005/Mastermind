#pragma once
#include <vector>

#ifndef CODE_H
#define CODE_H

class Code
{
public:
	Code();
	~Code();
	std::vector<int> secretCode;
	void initializeCode();
	int checkCorrect(Code guess);
	int checkIncorrect(Code guess);
};

#endif
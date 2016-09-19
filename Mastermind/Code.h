#pragma once
#include <vector>

#ifndef CODE_H
#define CODE_H

class Code
{
public:
	Code();
	~Code();
	std::vector<int> secretCode; // vector to hold secret code
	void initializeCode(); // init a random code
	int const checkCorrect(const Code& guess); // check correct digits in correct place
	int const checkIncorrect(const Code& guess); // check correct digits in incorrect place
};

#endif
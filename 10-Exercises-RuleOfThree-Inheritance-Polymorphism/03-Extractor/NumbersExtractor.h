#pragma once

#include <istream>
#include <string>
#include <cctype>

#include "BufferedExtractor.h"

class NumbersExtractor : public BufferedExtractor
{
protected:
	bool shouldBuffer(char symbol) override
	{
		return isdigit(symbol);
	}
public:
	NumbersExtractor(std::istream& lineIn) : BufferedExtractor(lineIn){}


	~NumbersExtractor() {}
};
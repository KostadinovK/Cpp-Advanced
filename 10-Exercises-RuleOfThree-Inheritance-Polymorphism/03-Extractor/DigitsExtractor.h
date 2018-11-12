#pragma once

#include <istream>
#include <string>

#include "Extractor.h"

class DigitsExtractor : public Extractor
{
public:
	DigitsExtractor(std::istream& lineIn) : Extractor(lineIn) {}

	~DigitsExtractor() {}
protected:
	bool process(char symbol, std::string& output) override
	{
		if(symbol >= '0' && symbol <= '9')
		{
			output = symbol;
			return true;
		}
		return false;
	}

	

};
#pragma once

#include <istream>
#include <string>


#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor
{
private:
	bool readyToStart;
public:
	QuotesExtractor(std::istream& stream) : BufferedExtractor(stream)
	{
		readyToStart = false;
	}

	~QuotesExtractor(){}
protected:
	bool process(char symbol, std::string& output) override
	{
		if(buffer.str().empty() && symbol == '"')
		{
			this->readyToStart = true;
		}

		if(this->readyToStart)
		{
			if (shouldBuffer(symbol)) {
				buffer << symbol;
				return false;
			}
			else if (!buffer.str().empty() && symbol == '"') {
				output = buffer.str();

				buffer.str("");
				buffer.clear();
				this->readyToStart = false;
				return true;
			}
		}

		return false;
		
	}

	bool shouldBuffer(char symbol) override
	{
		return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9');
	}
};
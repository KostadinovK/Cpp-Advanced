#pragma once

#include <memory>
#include <string>
#include <istream>

#include "Extractor.h"
#include "DigitsExtractor.h"
#include "NumbersExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istream& lineIn)
{
	if(extractType == "digits")
	{
		return std::make_shared<DigitsExtractor>(lineIn);
	}else if(extractType == "numbers")
	{
		return std::make_shared<NumbersExtractor>(lineIn);
	}else if(extractType == "quotes")
	{
		return std::make_shared<QuotesExtractor>(lineIn);
	}

	return nullptr;
}
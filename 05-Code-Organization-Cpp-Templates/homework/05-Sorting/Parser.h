#pragma once

#include <sstream>
template<typename T>
class Parser {

private:
	std::istream& input;
	std::string stopLine;
public:
	Parser(std::istream& input, std::string& stopLine) : input(input), stopLine(stopLine) {}


    bool readNext(T& toParse) {

		std::string s;
		std::getline(this->input,s);
		if(s == stopLine){
            return false;
		}

		std::istringstream sIn (s);
		sIn >> toParse;
		return true;

	}
};

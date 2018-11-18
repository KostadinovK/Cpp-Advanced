#pragma once

#include <string>
#include <sstream>

class Reader
{
private:
	std::istream& in;
public:
	Reader(std::istream& in) : in(in){}

	Reader& operator>>(std::vector<int>& nums)
	{
		std::string line;
		getline(in,line);
		int num;
		std::istringstream sIn(line);
		while(sIn >> num)
		{
			nums.push_back(num);
		}
		return *this;
	}
};
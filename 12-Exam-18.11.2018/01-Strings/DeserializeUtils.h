#pragma once

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> deserializeStrings(char* serialized)
{
	std::vector<std::string> strings;
	int stringsCount = serialized[0];
	int stringsAdded = 0;
	int index = 1;
	std::string res = "";
	while(stringsAdded < stringsCount)
	{
		int lenght = serialized[index];
		for(int i =0;i < lenght;i++)
		{
			index++;
			res += serialized[index];
			
		}
		stringsAdded++;
		strings.push_back(res);
		res = "";
		index++;
	}
	return strings;
}
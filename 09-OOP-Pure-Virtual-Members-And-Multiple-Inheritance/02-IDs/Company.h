#pragma once

#include "Resource.h"

#include <string>
#include <vector>
#include <sstream>


class Company : public HasInfo, public HasId
{
private:
	int id;
	std::string name;
	std::vector<std::pair<char, char>> employees;
public:
	Company();
	Company(int, std::string, std::vector<std::pair<char, char>>);

	int getId() const override;
	std::string getName() const;
	std::vector<std::pair<char, char>> getEmployees() const;

	std::string getInfo() const override;

	friend std::ostream& operator<<(std::ostream& stream, const Company& c);
	friend std::istream& operator>>(std::istream& stream, Company& c);
};

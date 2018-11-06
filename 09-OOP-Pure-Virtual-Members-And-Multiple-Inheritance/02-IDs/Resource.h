#pragma once
#include <string>

class HasInfo
{
public:
	virtual std::string getInfo() const = 0;
};

class HasId
{
public:
	virtual int getId() const = 0;
};
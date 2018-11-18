#pragma once

#include "ControllableUnit.h"

#include <iostream>
#include <vector>
#include <string>

class Marine : public ControllableUnit
{
public:
	static const int TRAINING_TIME = 15;

	Marine(Id id) : ControllableUnit(id,"marine") {}

	Id getId() const override {
		return ControllableUnit::getId();
	}

	void update() override {}

	void handleCommand(const std::vector<std::string>& commandParts)
	{
		if(commandParts[0] == "report")
		{
			std::cout << "marine " << this->getId() << " reporting" << std::endl;
		}
	}

	std::string getInfo() override {
		std::ostringstream info;
		info << Unit::getInfo() << " " << this->getId();
		return info.str();
	}
};
#pragma once

#include "TimedBuilder.h"
#include "Depot.h"
#include "Barracks.h"

class Worker : public TimedBuilder
{

public:
	Worker(Id id) : TimedBuilder(id,"worker"){}

	void handleCommand(const std::vector<std::string>& commandParts)
	{
		if (commandParts[0] == "report")
		{
			if(this->isConstructing())
			{
				std::cout << "worker " << this->getId() << " busy" << std::endl;
			}else
			{
				std::cout << "worker " << this->getId() << " free" << std::endl;
			}
			
		}else if(commandParts[0] == "build" && commandParts[1] == "depot")
		{
			if(!this->isConstructing())
			{
				TimedBuilder::startBuilding(UnitPtr(new Depot()), Depot::BUILD_TIME);
			}else
			{
				this->handleCommand(std::vector<std::string>{"report"});
			}
			

		}else if(commandParts[0] == "build" && commandParts[1] == "barracks")
		{
			Id id = commandParts[2][0];
			if (!this->isConstructing())
			{
				TimedBuilder::startBuilding(UnitPtr(new Barracks(id)), Barracks::BUILD_TIME);
			}
			else
			{
				this->handleCommand(std::vector<std::string>{"report"});
			}
		}
	}

	virtual void handleConstructionCompleted() {
		this->buildTimeRemaining = 0;
		this->currentConstruction = nullptr;
	}


};

#pragma once
#include "ProducerBase.h"
#include "Controllable.h"
#include "Marine.h"

#include <vector>
#include <queue>

class Barracks : public TimedBuilder 
{
private:
	std::queue<UnitPtr> q;
public:
	static const int BUILD_TIME = 50;

	Barracks(Id id) : TimedBuilder(id, "barracks") {}


	std::string getInfo() override {
		std::ostringstream info;
		info << Unit::getInfo() << " " << TimedBuilder::getId();
		return info.str();
	}

	void handleCommand(const std::vector<std::string>& commandParts)
	{
		
		if (commandParts[0] == "train" && commandParts[1] == "marine")
		{
			Id id = commandParts[2][0];

			if(this->q.size() < 5)
			{
				this->q.push(UnitPtr(new Marine(id)));
			}
			/*if (!this->isConstructing() && this->q.size() == 0)
			{
				TimedBuilder::startBuilding(UnitPtr(new Marine(id)), Marine::TRAINING_TIME);
			}
			else if (this->isConstructing() && this->q.size() < 5)
			{
				if (this->q.size() < 5)
				{
					this->q.push(UnitPtr(new Marine(id)));
				}

			}
			else if (!this->isConstructing() && this->q.size() > 0)
			{
				TimedBuilder::startBuilding(q.front(), Marine::TRAINING_TIME);
			}*/
		}
	}

	virtual void handleConstructionCompleted() {
		this->buildTimeRemaining = 0;
		this->currentConstruction = nullptr;
	}

};

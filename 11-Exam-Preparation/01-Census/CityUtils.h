#pragma once

#include <string>
#include <map>
#include <vector>

#include "City.h"


const City* initCity(const std::string& name, const size_t& population)
{
	return new City{name,population};
}

std::map<int, const City*> groupByPopulation(const std::vector<const City*>& cities, size_t& totalPopulation)
{
	std::map<int,const City*> grouped;
	totalPopulation = 0;
	for(int i = 0;i < cities.size();i++)
	{
		grouped[cities[i]->getPopulation()] = cities[i];
		totalPopulation += cities[i]->getPopulation();
	}
	return grouped;
}
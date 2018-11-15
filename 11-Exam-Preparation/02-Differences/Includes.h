#pragma once

#include <vector>
#include <utility>
#include <istream>
#include <ostream>
#include <string>
#include <algorithm>
#include <iostream>


#include "City.h"

class CityDiff
{

public:
	City a;
	City b;

	CityDiff(){}
	CityDiff(City a, City b) : a(a),b(b){}

};

std::istream& operator>>(std::istream& in, City& c)
{
	unsigned int censusYear;
	std::string name;
	size_t population;
	in >> name >> population >> censusYear;
	City c2(censusYear,name,population);
	c = c2;
	return in;
}

std::ostream& operator<<(std::ostream& out, const CityDiff& cDiff)
{
	if(cDiff.a.getName() == cDiff.b.getName())
	{
		out << cDiff.a.getName() << " (" << cDiff.a.getCensusYear() << " vs. " << cDiff.b.getCensusYear() << ")" << std::endl;
	}else
	{
		out << cDiff.a.getName() << " (" << cDiff.a.getCensusYear() << ") vs. " << cDiff.b.getName() << " (" << cDiff.b.getCensusYear() << ")" << std::endl;
	}

	size_t diff = std::max(cDiff.a.getPopulation(), cDiff.b.getPopulation()) - std::min(cDiff.a.getPopulation(),cDiff.b.getPopulation());
	if(cDiff.a.getPopulation() < cDiff.b.getPopulation())
	{
		out << "population: -" << diff << std::endl;
	}else
	{
		out << "population: +" << diff << std::endl;
	}
	
	return out;
}

CityDiff operator-(const City& a, const City& b)
{
	return CityDiff(a, b);
}
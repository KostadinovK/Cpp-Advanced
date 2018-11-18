#include "Group.h"
#include <algorithm>


class Comparer {
public:
	bool operator() (const UnitPtr a, const UnitPtr b) {
		return (*a).getId() < (*b).getId();
	}
};

bool hasSameId(UnitPtr* ptrs,int size, UnitPtr uptr)
{
	for(int i = 0;i < size;i++)
	{
		if(ptrs[i]->getId() == uptr->getId())
		{
			return true;
		}
	}

	return false;
}

const int Group::MAX_UNITS = 12;

Group::Group()
{
	this->units = new UnitPtr[Group::MAX_UNITS];
	this->unitsAdded = 0;
}

Group::Group(const Group& other) : Group()
{
	this->unitsAdded = other.unitsAdded;
	this->units = new UnitPtr[other.unitsAdded];
	for(int i = 0;i < other.unitsAdded;i++)
	{
		this->units[i] = other.units[i];
	}
}

void Group::add(UnitPtr unit)
{
	if(this->unitsAdded < 12)
	{
		if(!hasSameId(this->units,this->unitsAdded,unit))
		{
			this->units[unitsAdded] = unit;
			this->unitsAdded++;
		}
		
	}else if(this->unitsAdded == 12 && !hasSameId(this->units, this->unitsAdded, unit))
	{
		delete this->units[0];
		int index = 1;
		for (int i = 0; i < this->unitsAdded - 1; i++)
		{
			this->units[i] = this->units[index];
			index++;
		}
		this->units[Group::MAX_UNITS - 1] = unit;
	}
}

void Group::clear()
{
	delete[] units;
	this->units = new UnitPtr[Group::MAX_UNITS];
	this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other)
{
	if(this != &other)
	{
		this->unitsAdded = other.unitsAdded;
		this->units = new UnitPtr[other.unitsAdded];
		for (int i = 0; i < other.unitsAdded; i++)
		{
			this->units[i] = other.units[i];
		}
	}
	return *this;
}

Group& Group::operator<<(const Group& other)
{	
	if(other.unitsAdded + this->unitsAdded <= 12)
	{
		int index = this->unitsAdded;
		for (int i = 0; i < other.unitsAdded; i++)
		{
			if (!hasSameId(this->units, this->unitsAdded, other.units[i]))
			{
				this->units[index] = other.units[i];
				this->unitsAdded++;

			}
			index++;
		}
	}else
	{
		int diff = std::max(other.unitsAdded, this->unitsAdded) - std::min(other.unitsAdded, this->unitsAdded);
		for(int i = 0;i < diff;i++)
		{
			delete this->units[i];
		}
		int index = 0;
		for(int i = diff; i < other.unitsAdded - diff - 1;i++)
		{
			this->units[index] = other.units[i];
			index++;
			
		}
	}
	
	return *this;
}

Group::~Group()
{
	delete[] units;
	this->units = nullptr;
}
std::ostream& operator<<(std::ostream& out, const Group& group)
{
	std::vector<UnitPtr> unitsVec;
	for(int i = 0;i < group.unitsAdded;i++)
	{
		unitsVec.push_back(group.units[i]);
	}
	std::sort(unitsVec.begin(), unitsVec.end(), Comparer());

	for (int i = 0; i < unitsVec.size(); i++)
	{
		out << unitsVec[i]->getId() << " ";
	}
	return out;
}

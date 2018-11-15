#include "Range.h"

Range::Range() : valueCounts(new size_t[1]),rangeLength(1),rangeFirst(0){}

Range::Range(const Range& other) : Range()
{
	this->rangeFirst = other.rangeFirst;
	this->rangeLength = other.rangeLength;
	this->valueCounts = Range::copyValues(other);
}

Range& Range::operator=(const Range& other)
{
	if(this != &other)
	{
		this->rangeFirst = other.rangeFirst;
		this->rangeLength = other.rangeLength;
		this->valueCounts = Range::copyValues(other);
	}
	return *this;
}

void Range::add(T value)
{
	size_t* values = valueCounts;
	this->valueCounts = new size_t[rangeLength+1];
	this->valueCounts = this->copyValues(values,rangeLength);
	int index = value - rangeFirst;
	if(valueCounts[index] > 100)
	{
		valueCounts[index] = 0;
	}
	valueCounts[index]++;
	this->rangeLength++;
}

size_t Range::getCount(T value) const
{
	int index = value - rangeFirst;
	return valueCounts[index];
}

bool Range::empty() const
{
	for(int i = this->rangeFirst; i < this->rangeLength;i++)
	{
		if(valueCounts[i] > 0)
		{
			return false;
		}
	}
	
	return true;
}

void Range::clear() {}

void Range::resize(T first, T last) {}

size_t Range::getIndex(T value) const
{
	return 0;
}

Range::~Range()
{
	delete[] this->valueCounts;
	this->valueCounts = nullptr;
}





#pragma once

#include <algorithm>
#include <vector>

class VectorMax
{
public:
	int maximum;
	int* nums;
	int size;
	
public:
	VectorMax() : maximum(0),nums(new int[0]),size(0){}

	int getMaximum() const
	{
		return this->maximum;
	}
	bool operator<(const VectorMax& other)const
	{
		return this->maximum < other.maximum;
	}
};

std::vector<int> operator>>(std::vector<int>& nums, VectorMax& v)
{
	int max = nums[0];
	v.nums = new int[nums.size()];
	v.size = nums.size();
	for(int i = 0;i < nums.size();i++)
	{
		v.nums[i] = nums[i];
		if(max < nums[i])
		{
			max = nums[i];
		}
	}

	v.maximum = max;
	return nums;
}

std::ostream& operator<<(std::ostream& out, VectorMax& v)
{
	//std::sort(v.nums.begin(), v.nums.end());
	for (int i = 0; i < v.size; i++)
	{
		out << v.nums[i] << " ";
	}
	return out;
}
#pragma once

#include "Aggregator.h"
#include <vector>
#include <sstream>

class MinAggregator : public StreamAggregator {
private:
	std::vector<int> nums;

	int getNumsMinimum() {
		int min = INT16_MAX;
		for (int i = 0; i < this->nums.size();i++) {
			if (this->nums[i] < min) {
				min = this->nums[i];
			}
		}

		return min;
	}
public:
	MinAggregator(std::istream& stream) : StreamAggregator(stream) {
		this->aggregationResult = 0;
	}

	void aggregate(int next) {
		this->nums.push_back(next);
		this->aggregationResult = this->getNumsMinimum();
	}

	~MinAggregator() {}

};
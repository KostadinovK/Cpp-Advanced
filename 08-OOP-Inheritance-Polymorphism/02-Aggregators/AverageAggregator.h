#pragma once

#include "Aggregator.h"
#include <sstream>
#include <vector>

class AverageAggregator : public StreamAggregator {
private:
	std::vector<int> nums;

	int getNumsAverage() {
		int sum = 0;
		for (int i = 0; i < nums.size();i++) {
			sum += nums[i];
		}

		return sum / nums.size();
	}
public:
	AverageAggregator(std::istream& stream) : StreamAggregator(stream) {
		this->aggregationResult = 0;
	}

	void aggregate(int num) override {
		nums.push_back(num);
		this->aggregationResult = getNumsAverage();
		
	}


	~AverageAggregator() {
		
	}

};
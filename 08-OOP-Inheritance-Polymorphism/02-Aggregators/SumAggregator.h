#pragma once

#include "Aggregator.h"
#include <sstream>

class SumAggregator : public StreamAggregator {
public:
	SumAggregator(std::istream& stream) : StreamAggregator(stream) {
		this->aggregationResult = 0;
	}

	void aggregate(int num) override {
		this->aggregationResult += num;
		
	}

	~SumAggregator() {
		
	}

};
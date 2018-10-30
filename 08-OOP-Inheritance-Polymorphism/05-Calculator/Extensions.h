#pragma once
#include "Operation.h"
#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "MultiplicationOperation.h"
#include <string>
#include <vector>
#include <stack>

std::stack<int> memory;

class DivideOperation : public Operation {
	std::vector<int> operands;
	int result;
public:
	void addOperand(int operand) override {
		this->operands.push_back(operand);

		if (this->isCompleted()) {
			this->result = this->operands[0] / this->operands[1];
		}
	}

	bool isCompleted() override {
		return this->operands.size() == 2;
	}

	int getResult() override {
		return this->result;
	}
};

class MemorySaveOperation : public Operation {
public:
	void addOperand(int operand) override {
		memory.push(operand);
	}

	bool isCompleted() override {
		return false;
	}

	int getResult() override {
		return 0;
	}
};

class MemoryReadOperation : public Operation {
public:
	void addOperand(int operand) override { }

	bool isCompleted() override {
		return true;
	}

	int getResult() override {
		int result = memory.top();
		memory.pop();
		return result;
	}
};


class UpgradedInterpreter : public InputInterpreter {
public:
	UpgradedInterpreter(CalculationEngine& engine) :InputInterpreter(engine) {}

	std::shared_ptr<Operation> getOperation(std::string operation) override{
		if (operation == "*") {
			return std::make_shared<MultiplicationOperation>();
		}
		else if (operation == "/") {
			return std::make_shared<DivideOperation>();
		}
		else if (operation == "ms") {
			return std::make_shared<MemorySaveOperation>();
		}
		else if (operation == "mr") {
			return std::make_shared<MemoryReadOperation>();
		}

		return std::shared_ptr<Operation>(nullptr);
	}
};


std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
	return std::make_shared<UpgradedInterpreter>(engine);
}
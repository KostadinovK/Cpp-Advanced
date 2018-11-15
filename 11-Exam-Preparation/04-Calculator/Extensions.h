#pragma once

#include "InputInterpreter.h"
#include "Operation.h"
#include "CalculationEngine.h"

#include <memory>
#include <stack>

class DivideOperation : public Operation
{
private:
	bool completed = false;
	int result;
	int number;
	int hasNumber = false;
public:
	void addOperand(int operand) override
	{
		if(hasNumber)
		{
			this->result = number / operand;
			completed = true;
		}else
		{
			this->number = operand;
			this->hasNumber = true;
		}
	}

	int getResult() override
	{
		return this->result;
	}

	bool isCompleted() override
	{
		return this->completed;
	}
};

class MemorySaveOperation : public Operation
{
private:
	std::shared_ptr<std::stack<int>>& memory;
	bool completed = false;
	int result;
public:
	MemorySaveOperation(std::shared_ptr<std::stack<int>>& memory) : memory(memory){}

	bool isCompleted() override
	{
		return this->completed;
	}
	int getResult() override
	{
		return this->result;
	}
	void addOperand(int operand) override
	{
		this->result = operand;
		this->memory->push(this->result);
		this->completed = true;
	}
};

class MemoryReadOperation : public Operation
{
private:
	std::shared_ptr<std::stack<int>>& memory;
	int result;
	bool completed = true;
public:
	MemoryReadOperation(std::shared_ptr<std::stack<int>>& memory) : memory(memory){}

	void addOperand(int operand) override
	{
	}

	bool isCompleted() override
	{
		return this->completed;
	}
	int getResult() override
	{
		this->result = this->memory->top();
		this->memory->pop();
		return this->result;
	}
};

class ExtendedInputInterpreter : public InputInterpreter
{
public:
	std::shared_ptr<std::stack<int>> memory;
	ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine)
	{
		this->memory = std::make_shared<std::stack<int>>();
	}

	std::shared_ptr<Operation> getOperation(std::string operation) override
	{
		std::shared_ptr<Operation> o = InputInterpreter::getOperation(operation);
		if(o)
		{
			return o;
		}else if(operation == "/")
		{
			return std::make_shared<DivideOperation>();
		}else if(operation == "ms")
		{
			return std::make_shared<MemorySaveOperation>(this->memory);
		}else if(operation == "mr")
		{
			return std::make_shared<MemoryReadOperation>(this->memory);
		}
	}
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine)
{
	return std::make_shared<ExtendedInputInterpreter>(engine);
}
#pragma once

#include <string>

class ArrayOfPointers {
private:
	const int size = 50;
	Company** arr;
	int numAdded;
public:
	ArrayOfPointers() : numAdded(0), arr(new Company*[size]) {}

	void add(Company* c) {
		this->numAdded++;
		this->arr[numAdded - 1] = c;
	}

	int getSize() {
		return this->numAdded;
	}

	Company* get(int index) {
		if (index >= 0 && index < this->numAdded) {
			return this->arr[index];
		}
	}

	ArrayOfPointers(const ArrayOfPointers& other) = delete;
	ArrayOfPointers& operator=(const ArrayOfPointers& other) = delete;

	~ArrayOfPointers() {
		for (size_t i = 0; i < this->numAdded;i++) {
			delete this->arr[i];
			this->arr[i] = nullptr;
		}
		delete[] this->arr;
		this->arr = nullptr;
	}

};
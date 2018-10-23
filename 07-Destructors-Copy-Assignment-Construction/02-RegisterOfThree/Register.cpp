#include "Register.h"

#include <string>
#include <utility>

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}

Company Register::get(int companyId) const {
	for (size_t i = 0; i < this->numAdded; i++) {
		if (this->companiesArray[i].getId() == companyId) {
			return this->companiesArray[i];
		}
	}

	return Company();
}

void Register::add(const Company& c) {

	this->numAdded++;
	this->companiesArray[numAdded-1] = c;
	
}

Register& Register::operator=(const Register& other) {
	this->numAdded = other.numAdded;
	this->companiesArray = new Company[other.numAdded];
	for (size_t i = 0; i < this->numAdded;i++) {
		this->companiesArray[i] = other.companiesArray[i];
	}
	return *this;
}

Register::Register(const Register& other) {
	*this = other;
}

Register::~Register() {
	delete[] this->companiesArray;
	this->companiesArray = nullptr;
}
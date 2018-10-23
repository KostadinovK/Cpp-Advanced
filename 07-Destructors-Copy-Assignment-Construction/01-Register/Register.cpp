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

	this->companiesArray[numAdded] = c;
	this->numAdded++;


}

Register::~Register() {
	delete[] this->companiesArray;
	this->companiesArray = nullptr;
}
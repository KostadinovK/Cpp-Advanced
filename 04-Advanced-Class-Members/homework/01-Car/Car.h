#pragma once

#include <string>

using namespace std;

class Car{
private:
    const string brand;
    const string model;
    const int year;
public:
    Car(string brand,string model,int year) : brand(brand),model(model),year(year){}

    string GetBrand() const {
        return this->brand;
    }

    string GetModel() const {
        return this->model;
    }

    int GetYear() const {
        return this->year;
    }
};

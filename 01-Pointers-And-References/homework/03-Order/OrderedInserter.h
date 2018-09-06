#pragma once

#include "Company.h"
#include <vector>
#include <algorithm>

class OrderedInserter{

    std::vector<const Company*>& companies;

public:
    OrderedInserter(std::vector<const Company*>& companies): companies(companies){}

    std::vector<const Company*> getCompanies(){
        return this->companies;
    }

    void insert(const Company* c){
        companies.push_back(c);
        std::sort(companies.begin(),companies.end(),[](const Company* c1, const Company* c2){
                  return c1->getId() < c2->getId();
                  });

    }

};

#pragma once

#include "Company.h"
#include <string>
#include <vector>
#include <sstream>

Company* parseUniqueCompanies(std::string companies, int& numCompanies,std::string (*orderFunc)(const Company& c)){
    std::istringstream sIn(companies);
    std::string info;
    std::vector<std::string> words;
    std::vector<Company*> companies_vector;
    while(sIn >> info){
        words.push_back(info);
    }

    for(int i=0;i < words.size();i += 2){
        Company* c = new Company(std::stoi(words[i]),words[i+1]);
        std::string res = orderFunc(*c);

        companies_vector.push_back(c);
        numCompanies++;
    }

    Company* res = companies_vector[0];
    return res;

}


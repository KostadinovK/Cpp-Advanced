#pragma once

#include "Company.h"

#include <vector>

Company* find(const std::vector<Company*>& companies, const int& searchID){
    for(int i = 0;i < companies.size();i++){
        if(companies[i]->getId() == searchID){
            return companies[i];
        }
    }
}

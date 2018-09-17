#pragma once

#include "Company.h"
#include <string>
#include <vector>
#include <memory>

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& params){
    int id = std::stoi(params[0]);
    std::string name = params[1];
    std::vector<std::pair<char,char> > employees;
    for(int i = 2;i < params.size();i++){
        std::pair<char, char> employee;
        employee.first = params[i][0];
        employee.second = params[i][1];
        employees.push_back(employee);
    }
    std::shared_ptr<Company> c (new Company(id,name,employees));


    return c;
}


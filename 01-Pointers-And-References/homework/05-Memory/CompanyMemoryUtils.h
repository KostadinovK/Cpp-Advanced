#pragma once

#include "Company.h"
#include <vector>
#include <string.h>
#include <iostream>

typedef unsigned char byte;
std::vector<Company> readCompaniesFromMemory(byte* memory, int companiesNum){
    std::vector<Company> companies;

    for(int i = 0;i < companiesNum;i++){
        int id = (int)*memory;
        memory++;
        std::string name = "";
        while(*memory != '\0'){
            name += *memory;
            memory++;
        }
        memory++;
        int employeesNum = (int)*memory;
        memory++;
        std::vector<std::pair<char, char> > employees;
        for(int j = 0;j < employeesNum;j++){
            std::pair<char, char> p;
            p.first = *memory;
            memory++;
            p.second = *memory;
            memory++;
            employees.push_back(p);
        }

        Company c(id,name,employees);
        companies.push_back(c);
    }




    return companies;
}




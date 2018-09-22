#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Company.h"

bool comparatorById(const Company& c1, const Company& c2){
    return c1.getId() < c2.getId();
}

bool comparatorByName(const Company& c1, const Company& c2){
    return c1.getName() < c2.getName();
}

int main(){
    std::vector<Company> companies;
    std::string line;
    std::getline(std::cin,line);
    while(line != "end"){
        std::istringstream lineIn(line);
        int id;
        std::string name;
        lineIn >> name >> id;
        Company c(id,name);
        companies.push_back(c);
        std::getline(std::cin,line);
    }
    std::string comparator;
    std::getline(std::cin, comparator);
    bool (*compare) (const Company&, const Company&);

    if(comparator == "id"){
        compare = &comparatorById;
    }else if(comparator == "name"){
        compare = &comparatorByName;
    }else{
        compare = nullptr;
    }

    std::sort(companies.begin(), companies.end(),compare);

    for(int i = 0;i < companies.size();i++){
        std::cout << companies[i].toString()<<std::endl;
    }
    return 0;
}

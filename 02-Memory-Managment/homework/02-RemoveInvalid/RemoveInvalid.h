#pragma once

#include "Company.h"
#include<list>
#include<string>

void removeInvalid(std::list<Company*>& companies){
    for(auto i = companies.begin();i != companies.end();i++){
        Company* c_ptr = *i;

        if(c_ptr->getId() < 0){


            i = companies.erase(i);
            delete c_ptr;
            i--;
        }
    }

}

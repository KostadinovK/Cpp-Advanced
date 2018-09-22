#include "Company.h"

#include <list>
#include <set>

void removeDuplicates(std::list<Company*>& companies){
    std::set<Company*> uniquePtrs;
    std::set<std::string> uniqueNames;

    auto i = companies.begin();
    while(i != companies.end()){
        Company* c = *i;

        bool isPtrCopy = !uniquePtrs.insert(c).second;
        if(isPtrCopy){
            i = companies.erase(i);

        }else{
            if(!uniqueNames.insert(c->getName()).second){
                i = companies.erase(i);
                delete c;
            }else{
                i++;
            }
        }
    }
}

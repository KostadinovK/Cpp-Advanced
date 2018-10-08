#pragma once
#include <iostream>
#include <string>

template <typename T>
void printContainer (typename T::iterator begin, typename T::iterator end){
    for(auto i = begin; i != end;i++){
        std::cout << *i << " " ;
    }
}



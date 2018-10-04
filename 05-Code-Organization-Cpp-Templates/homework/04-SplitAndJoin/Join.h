#pragma once
#include <vector>
#include <string>
#include <sstream>

template<typename T>
std::string join(std::vector<T>& elements, std::string& separator){
    std::ostringstream sOut;
    for(int i = 0; i < elements.size();i++){
        if(i < elements.size()-1){
            sOut << elements[i];
            sOut << separator;
        }else{
            sOut << elements[i];
        }

    }

    return sOut.str();
}


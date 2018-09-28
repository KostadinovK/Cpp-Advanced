#pragma once

#include <string>
#include <vector>

std::vector<std::string> operator+(const std::vector<std::string>& v1, const std::vector<std::string>& v2){
    std::vector<std::string> res;
    std::string newValue;
    for(int i = 0;i < v1.size();i++){
        newValue = v1[i] + " " + v2[i];
        res.push_back(newValue);
    }

    return res;
}

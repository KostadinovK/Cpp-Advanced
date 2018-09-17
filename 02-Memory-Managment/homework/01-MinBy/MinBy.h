#pragma once

#include <string>
#include <vector>
#include <algorithm>
std::string minBy(std::vector<std::string> values, bool (*decisionFunc)(const std::string& a, const std::string& b)){

    for(int i = 0;i < values.size()-1;i++){
        for(int j = 0;j < values.size()-i-1;j++){
            if(decisionFunc(values[j+1],values[j])){
                std::string temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return values[0];
}

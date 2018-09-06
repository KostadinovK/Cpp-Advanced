#pragma once
#include <string>

bool tryParse(const std::string& s, int& parsedNum){

    for(int i = 0;i < s.size();i++){
        if(s[0] == '-'){
            continue;
        }
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    parsedNum = std::stoi(s);
    return true;

}

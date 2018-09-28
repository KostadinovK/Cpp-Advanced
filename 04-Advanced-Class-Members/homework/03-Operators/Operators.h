#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string>& operator<<(std::vector<std::string>& v, const std::string& s){
    v.push_back(s);
    return v;
}

std::string operator+(const std::string& s, const int num){
    std::ostringstream res;
    res << s << num;
    return res.str();
}

std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& v){
    for(int i = 0;i < v.size();i++){
        out << v[i];
        out << '\n';
    }
    return out;
}

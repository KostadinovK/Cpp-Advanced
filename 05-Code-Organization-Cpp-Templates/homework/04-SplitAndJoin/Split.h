#pragma once
#include <vector>
#include <sstream>

template<typename T>
std::vector<T> split(std::string& line, const char& separator){
    std::vector<T> res;
    int pos = 0;
    std::string token;
    T element;
    while ((pos = line.find(separator)) != std::string::npos) {
        token = line.substr(0, pos);
        std::istringstream sIn (token);
        sIn >> element;
        res.push_back(element);
        line.erase(0, pos+1);
    }
    std::istringstream lineIn(line);
	lineIn >> element;
	res.push_back(element);

    return res;

}

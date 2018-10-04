#pragma once

template<typename T>
void printVector(const std::vector<T>& v){
    for(auto i = v.begin(); i!= v.end();i++){
        std::cout << *i << " ";
    }
}

#pragma once

template<typename T>
class LessThan{
    bool operator()(const T& element1, const T& element2){
        return element1 < element2;
    }
};

template<typename T>
class Reverse{


};


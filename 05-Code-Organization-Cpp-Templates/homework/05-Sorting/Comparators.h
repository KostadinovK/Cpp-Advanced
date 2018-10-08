#pragma once

template<typename T>
class LessThan{
public:
    bool operator()(const T& element1, const T& element2){
        return element1 < element2;
    }
};

template<typename T, typename Comparator>
class Reverse{
    Comparator comp;
public:
    bool operator()(const T& element1, const T& element2){
        bool compareRes = this->comp(element1,element2);
        return !compareRes;
    }

};


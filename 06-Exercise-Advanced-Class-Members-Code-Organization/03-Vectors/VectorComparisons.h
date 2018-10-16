#pragma once

#include "Vector.h"

class VectorLengthComparer{
public:
    bool operator()(const Vector& v1, const Vector& v2){
        return v1.getLength() < v2.getLength();
    }

};
template<typename T, typename Comparator>
class ReverseComparer{
private:
    Comparator c;
public:
    bool operator()(const T& element1, const T& element2){
        bool compareResult = this->c(element1,element2);
        return !compareResult;
    }

};

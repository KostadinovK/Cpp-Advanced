#pragma once

#include "Filter.h"
#include <string>

class FilterFactory{
private:
    class DigitFilter : public Filter{
        bool shouldFilterOut(char symbol) const override{
            return symbol >= '0' && symbol <= '9';
        }

    };

    class UppercaseFilter : public Filter{
        bool shouldFilterOut(char symbol) const override{
            return symbol >= 'A' && symbol <= 'Z';
        }
    };

    class LowercaseFilter : public Filter{
        bool shouldFilterOut(char symbol) const override{
            return symbol >= 'a' && symbol <= 'z';
        }
    };
public:
    Filter* buildFilter(std::string type) const {
        Filter* result = nullptr;
        if(type == "a-z"){
            result = new LowercaseFilter();
        }else if(type == "A-Z"){
            result = new UppercaseFilter();
        }else if(type == "0-9"){
            result = new DigitFilter();
        }

        return result;
    }
};

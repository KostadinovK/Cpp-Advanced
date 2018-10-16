#pragma once

#include "NoteName.h"

#include <string>

class SolfegeNoteNaming{
public:
    NoteName operator()(const std::string& s)const{
        if(s == "Do"){
            return NoteName('C');
        }else if(s == "Re"){
            return NoteName('D');
        }else if(s == "Mi"){
            return NoteName('E');
        }else if(s == "Fa"){
            return NoteName('F');
        }else if(s == "Sol"){
            return NoteName('G');
        }else if(s == "La"){
            return NoteName('A');
        }else if(s == "Si"){
            return NoteName('B');
        }else{
            return NoteName('?');
        }
    }

};

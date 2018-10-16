#include "Echo.h"

bool echoOn;

void echo(const std::string& s){
    if(echoOn){
        std::cout << s << std::endl;
    }
}



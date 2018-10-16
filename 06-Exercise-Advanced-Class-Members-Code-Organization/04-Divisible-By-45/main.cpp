#include <iostream>
#include <string>

#include "BigInt.h"

bool IsDivisibleBy45(const std::string&);

int main(){
    std::string str1;
    std::getline(std::cin, str1);
    std::string str2;
    std::getline(std::cin, str2);
    BigInt from(str1);
    BigInt to(str2);
    BigInt i;

    std::string currentNum;
    for(i = from; i < to;i+=1){
        currentNum = i.getDigits();
        if(IsDivisibleBy45(currentNum)){
            std::cout << currentNum << std::endl;
        }
    }

    return 0;
}
bool IsDivisibleBy45(const std::string& num){
    long sum = 0;
    if(num[num.size()-1] == '0' || num[num.size()-1] == '5'){
        for(int i = 0;i < num.size();i++){
            sum += num[i] - '0';
        }
        if(sum % 9 == 0){
            return true;
        }
    }

    return false;
}

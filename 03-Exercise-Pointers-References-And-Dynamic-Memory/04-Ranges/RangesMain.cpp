# include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <memory>

struct Range{
    const int from;
    const int to;

    Range(int from, int to): from(from), to(to) {}

};

bool isInRange(int num, const std::map<int, std::shared_ptr<Range> >& byFrom, const std::map<int, std::shared_ptr<Range> >& byTo){
    auto fromIter = byFrom.upper_bound(num);
    if(fromIter == byFrom.begin()){
        return false;
    }

    fromIter--;

    auto toIter = byTo.lower_bound(num);
    if(toIter == byTo.end()){
        return false;
    }

    return fromIter->second == toIter->second;
}


int main(){
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    std::map<int, std::shared_ptr<Range> > rangesByFrom;
    std::map<int, std::shared_ptr<Range> > rangesByTo;

    std::string line;
    std::getline(std::cin,line);
    while(line != "."){
        std::istringstream lineIn (line);
        int from;
        int to;
        lineIn >> from >> to;

        std::shared_ptr<Range> r = std::make_shared<Range>(from,to);

        rangesByFrom[r->from] = r;
        rangesByTo[r->to] = r;

        std::getline(std::cin,line);
    }
    std::string numStr;
    std::getline(std::cin,numStr);

    while(numStr != "."){
        std::istringstream numIn (numStr);
        int num;
        numIn >> num;
        if(isInRange(num, rangesByFrom, rangesByTo)){
            std::cout << "in" <<std::endl;
        }else{
            std::cout << "out" <<std::endl;
        }
        std::getline(std::cin,numStr);
    }

    return 0;
}


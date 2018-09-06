#pragma once
#include "Company.h"
#include "ProfitCalculator.h"

#include <strings.h>
#include <map>
#include <sstream>
#include <algorithm>

std::string getProfitReport(const Company* from, const Company* const to,std::map<int, ProfitCalculator>&  profitCalculatorsByCompany){

    std::ostringstream res;

    while(from <= to){
        //res << "\n"<<*from << " " << from << "\n";
        Company c = *from;
        ProfitCalculator calc = profitCalculatorsByCompany[c.getId()];
        int profit = calc.calculateProfit(c);
        res << c.getName()<<" = " << profit<<"\n";
        from++;
    }

    return res.str();

}


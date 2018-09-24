#pragma once
#include <algorithm>
#include <iostream>
#include "Company.h"

void sortBy(Company** companiesBegin, Company** companiesEnd, bool (*comparator)(const Company&, const Company&)){
    std::sort(companiesBegin,companiesEnd,[&](Company* c1,Company* c2) -> bool {
        comparator(*c1,*c2);
    });
}

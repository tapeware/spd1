//
// Created by mikolaj on 4/1/25.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Problem.h"
#include "Solution.h"
#include <algorithm>

Solution my_algorithm(Problem& p);
Solution overview(Problem& p);
std::vector<unsigned int> number_range(unsigned int beginning, unsigned int end);

#endif //ALGORITHMS_H

//
// Created by mikolaj on 4/1/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>
#include <sstream>

typedef std::vector<unsigned int> Range;
Range get_range(unsigned int beginning, unsigned int end);
std::ostream& operator<<(std::ostream& os, const Range& r);
#endif //UTILS_H

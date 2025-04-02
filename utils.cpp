//
// Created by mikolaj on 4/1/25.
//

#include "utils.h"

Range get_range(unsigned int beginning, unsigned int end)
{
    std::vector<unsigned int> result;

    for (unsigned int i=beginning; i<=end; i++) result.push_back(i);

    return result;
}

std::ostream& operator<<(std::ostream& os, const Range& r)
{
    std::stringstream formatted_string;
    unsigned int counter=0;

    for (unsigned int i : r)
    {
        if(++counter == 1)
            formatted_string << "[" << i << ", ";
        else if(counter != r.size())
            formatted_string << i << ", ";
        else
            formatted_string << i << "]";

    }

    os << formatted_string.str();
    return os;
}
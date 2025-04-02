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

std::string unit_to_str(time_unit unit)
{
    switch (unit)
    {
        case s: return "s";
        case ms: return "ms";
        case us: return "us";
        case ns: return "ns";
    }
    return "";
}


double Timer::get_measurement(time_unit unit) const
{
    if(!measured)
        return 0;

    switch (unit)
    {
        case s:
        {
            return static_cast<double> (std::chrono::duration_cast<std::chrono::seconds>
                    (end - begin).count());
        }
        case ms:
        {
            return static_cast<double> (std::chrono::duration_cast<std::chrono::milliseconds>
                    (end - begin).count());
        }
        case us:
        {
            return static_cast<double> (std::chrono::duration_cast<std::chrono::microseconds>
                    (end - begin).count());
        }
        case ns:
        {
            return static_cast<double> (std::chrono::duration_cast<std::chrono::nanoseconds>
                    (end - begin).count());
        }
    }

    return 0.0;
}

void Timer::print_measurement(time_unit unit) const
{
    if (!measured) return;
    const std::string unit_str = unit_to_str(unit);
    std::cout << "Duration: " << get_measurement(unit) << unit_str << "\n";
}
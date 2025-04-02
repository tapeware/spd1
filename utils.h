//
// Created by mikolaj on 4/1/25.
//

#ifndef UTILS_H
#define UTILS_H


#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>

typedef std::vector<unsigned int> Range;
Range get_range(unsigned int beginning, unsigned int end);
std::ostream& operator<<(std::ostream& os, const Range& r);

typedef std::chrono::steady_clock::time_point time_measurement;

enum time_unit {s, ms, us, ns};
std::string unit_to_str(time_unit unit);

class Timer
{
    time_measurement begin;
    time_measurement end;
    bool measured;

public:
    Timer() {measured=false;}
    double get_measurement(time_unit unit) const;
    void start() {begin=std::chrono::steady_clock::now();}
    void stop() {end=std::chrono::steady_clock::now(); measured=true;}
    void print_measurement(time_unit unit) const;
};



#endif //UTILS_H

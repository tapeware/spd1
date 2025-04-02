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

class Timer
{
    time_measurement begin;
    time_measurement end;
    bool measured;

public:
    Timer() {measured=false;}
    double get_measurement() const;
    void start() {begin=std::chrono::steady_clock::now();}
    void stop() {end=std::chrono::steady_clock::now(); measured=true;}
    void print() {std::cout << "Time: " << get_measurement() << "\n"; }
};



#endif //UTILS_H

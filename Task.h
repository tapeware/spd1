//
// Created by mikolaj on 3/26/25.
//

#ifndef TASK_H
#define TASK_H

#include <vector>
#include <iostream>

class Task
{
    unsigned int pj, rj, qj;
    //static unsigned int current_max_index;

public:

    Task(unsigned int pj, unsigned int rj, unsigned int qj) : pj(pj), rj(rj), qj(qj) {}
    Task() {pj=0; rj=0; qj=0;}

    unsigned int get_pj() const {return pj;}
    unsigned int get_qj() const {return qj;}
    unsigned int get_rj() const {return rj;}
};

std::ostream& operator<<(std::ostream& os, const Task& t);



#endif //TASK_H
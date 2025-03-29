//
// Created by mikolaj on 3/26/25.
//

#include "Task.h"


std::ostream& operator<<(std::ostream& os, const Task& t)
{
    os << "pj=" << t.get_pj() << ", rj=" << t.get_rj() << ", qj=" << t.get_qj() << "\n";
    return os;
}
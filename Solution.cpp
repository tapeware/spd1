//
// Created by danie on 29.03.2025.
//

#include "Solution.h"

void Solution::print_solution() {
    for (auto task : solution_list) {
        std::cout<<task.get_pj()<<" "<<task.get_rj()<<" "<<task.get_qj()<<std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Solution& s)
{
    std::stringstream formatted_string;
    Task tmp;
    unsigned int task_count = s.get_task_count();

    formatted_string << "Total tasks: " << task_count << "\n";
    for (unsigned int i=0; i<task_count; i++)
    {
        tmp = s.get_task_by_index(i);
        formatted_string << i+1 << ") pj=" << tmp.get_pj()
                                << ", rj=" << tmp.get_rj()
                                << ", qj=" << tmp.get_qj()
                                << "\n";

    }

    os << formatted_string.str();
    return os;
}
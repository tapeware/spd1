//
// Created by danie on 29.03.2025.
//

#include "Solution.h"

void Solution::print_solution() {
    for (auto task : solution_list) {
        std::cout<<task.get_pj()<<" "<<task.get_rj()<<" "<<task.get_qj()<<std::endl;
    }
}

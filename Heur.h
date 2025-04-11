//
// Created by danie on 29.03.2025.
//

#ifndef HEUR_H
#define HEUR_H
#include <vector>
#include "Task.h"
#include "Solution.h"
#include "Problem.h"


class Heur {
    const std::vector<Task>& to_do_list;
public:
    explicit Heur(std::vector<Task> &to_do_list_in):to_do_list(to_do_list_in){};
    std::vector<Task> rj_sort();
    std::vector<Task> qj_sort();
};




#endif //HEUR_H

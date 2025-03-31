//
// Created by danie on 29.03.2025.
//

#include "Heur.h"

#include <algorithm>

std::vector<Task> Heur::rj_sort() {
    std::vector<Task> solution = to_do_list;
    std::sort(solution.begin(), solution.end(),
        [](const Task &t1, const Task &t2) {
            return t1.get_rj() < t2.get_rj();
        });
    return solution;
}

std::vector<Task> Heur::qj_sort() {
    std::vector<Task> solution = to_do_list;
    std::sort(solution.begin(), solution.end(),
        [](const Task &t1, const Task &t2) {
            return t1.get_qj() > t2.get_qj();
        });
    return solution;
}

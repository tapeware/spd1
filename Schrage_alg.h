//
// Created by danie on 2.04.2025.
//

#ifndef SCHRAGE_ALG_H
#define SCHRAGE_ALG_H

#include <vector>
#include "Task.h"
#include <queue>
#include <algorithm>


class Schrage {
    const std::vector<Task>& to_do_list;
    public:
    explicit Schrage(std::vector<Task> &to_do_list_in):to_do_list(to_do_list_in){};
    std::vector<Task> schrage_sort();
   int schrage_with_div_sort();

};



#endif //SCHRAGE_ALG_H

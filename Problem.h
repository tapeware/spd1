//
// Created by mikolaj on 3/26/25.
//

#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "utils.h"


#include "Task.h"


class Problem
{
    std::vector<Task> to_do_list;

public:
    explicit Problem(const std::string& file_path);
    Problem() = default;

    void rearrange(const Range& new_order);
    std::vector<Task> get_tasks() const {return to_do_list;}
    const Task& get_task_by_index(unsigned int index) const {return to_do_list[index];}
    unsigned int get_task_count() const {return to_do_list.size();}
    void append_task(Task t) {to_do_list.push_back(t);}
    unsigned int simulate(bool with_cooldowns) const;
};


std::ostream& operator<<(std::ostream& os, const Problem& p);


#endif //PROBLEM_H
//
// Created by danie on 29.03.2025.
//

#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "Task.h"


class Solution {
  std::vector<Task> solution_list;
public:
  explicit Solution(const std::vector<Task> &solution_list):solution_list(solution_list){}
  void print_solution();

  std::vector<Task> get_tasks() const {return solution_list;}
  const Task& get_task_by_index(unsigned int index) const {return solution_list[index];}
  unsigned int get_task_count() const {return solution_list.size();}

};

std::ostream& operator<<(std::ostream& os, const Solution& s);

#endif //SOLUTION_H

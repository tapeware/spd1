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
  explicit Solution(const std::vector<Task> &solution_list):solution_list(solution_list){};
  void print_solution();
};



#endif //SOLUTION_H

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

#include "Task.h"


class Problem
{
    std::vector<Task> to_do_list;

public:
    explicit Problem(const std::string& file_path);
    Problem() = default;




    //to zwraca referencje do wektora czyli zmienna
    //do ktorej sie to przypisze bedzie sie aktualizowala
    //jesli sie zmieni wektor
    std::vector<Task>& get_tasks() {return to_do_list;}


    //to zwraca tylko zadanie i ono sie nie bedzie aktualizowalo
    const Task& get_task_by_index(unsigned int index) const {return to_do_list[index];}



    unsigned int get_task_count() const {return to_do_list.size();}
    void append_task(Task t) {to_do_list.push_back(t);}
};


std::ostream& operator<<(std::ostream& os, const Problem& p);


#endif //PROBLEM_H
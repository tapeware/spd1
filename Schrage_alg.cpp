//
// Created by danie on 2.04.2025.
//

#include "Schrage_alg.h"

std::vector<Task> Schrage::schrage_sort() {

    int actual_time=0;
    std::vector<Task> sol = to_do_list;
    std::vector<Task> final_sol;
    std::vector<Task> temp;
    auto cmp = [](const Task &t1,const Task &t2) {
        return t1.get_qj() < t2.get_qj();
    };


    while (sol.empty() == false)
    {
        temp.clear();
        std::priority_queue<Task,std::vector<Task>, decltype(cmp)> lambda_priority_queue(cmp);
        for (auto task : sol)
        {
            if (task.get_rj()<=actual_time) {
                temp.push_back(task);
            }
        }
        if (temp.empty())
        {
            actual_time++;
        }
        else {
            for (const auto& task : temp)
            {
                lambda_priority_queue.push(task);
            }
            actual_time=actual_time+lambda_priority_queue.top().get_pj();
            final_sol.push_back(lambda_priority_queue.top());
            const Task& top_task = lambda_priority_queue.top();
            auto it = std::find(sol.begin(), sol.end(), top_task);
            if (it != sol.end()) {
                sol.erase(it);
            }
        }
    }
    return final_sol;

}

int Schrage::schrage_with_div_sort() {
    unsigned int actual_time=0;
    std::vector<Task> sol = to_do_list;
    std::vector<Task> final_sol;
    std::vector<Task> temp;
    unsigned int max_styg=0;
    auto cmp = [](const Task &t1,const Task &t2) {
        return t1.get_qj() < t2.get_qj();
    };


    while (sol.empty() == false)
    {
        temp.clear();
        std::priority_queue<Task,std::vector<Task>, decltype(cmp)> lambda_priority_queue(cmp);
        for (auto task : sol)
        {
            if (task.get_rj()<=actual_time) {
                temp.push_back(task);
            }
        }
        if (temp.empty())
        {
            actual_time++;
            if (!max_styg<=0)
                max_styg--;
        }
        else {
            for (const auto& task : temp)
            {
                lambda_priority_queue.push(task);
            }
            actual_time++;
            if (!max_styg<=0)
                max_styg--;
            //final_sol.push_back(lambda_priority_queue.top());
            const Task& top_task = lambda_priority_queue.top();
            auto it = std::find(sol.begin(), sol.end(), top_task);
            if (it != sol.end()) {
                if (it->get_pj()>=2) {
                    it->set_pj(it->get_pj()-1);
                }
                else {
                    if (it->get_qj()>max_styg) {
                        max_styg=it->get_qj();
                    }
                    if (sol.size()==1 &&max_styg>0) {
                        actual_time=actual_time+max_styg;
                    }
                    sol.erase(it);
                }
            }
        }
    }
    return actual_time;
}

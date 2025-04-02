//
// Created by mikolaj on 4/1/25.
//

#include "algorithms.h"

Solution my_algorithm(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();

    std::sort(tasks.begin(), tasks.end(),
        [](const Task& t1, const Task& t2)
        {
            unsigned int id1=0, id2=0;
            id1 = t1.get_pj() * t1.get_qj() * t1.get_rj();
            id2 = t2.get_pj() * t2.get_qj() * t2.get_rj();
            return id1 < id2;
        }
            );
    Solution s(tasks);

    return s;
}


Solution overview(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();
    Range task_order = get_range(0, p.get_task_count()-1);
    Problem tmp=p, optimally_aranged_problem;
    unsigned int time=0, minimal_time=0;

    do
    {
        tmp=p;
        tmp.rearrange(task_order);
        time = tmp.simulate(true);

        if(time < minimal_time || minimal_time==0)
        {
            minimal_time = time;
            optimally_aranged_problem = tmp;
        }

    }
    while (std::next_permutation(task_order.begin(), task_order.end()));

    Solution result(optimally_aranged_problem.get_tasks());
    return result;
}
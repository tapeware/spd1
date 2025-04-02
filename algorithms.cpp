//
// Created by mikolaj on 4/1/25.
//

#include "algorithms.h"

Solution my_algorithm(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();
    //std::cout << "ROZMIAR: " << tasks.size() << "\n";

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
    //std::cout << "ROZMIAR: " << tasks.size() << "\n";
    return s;
}





Solution overview(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();
    Range task_order = get_range(0, p.get_task_count()-1), optimal_task_order;
    Problem tmp=p;
    unsigned int time=0, minimal_time=0;

    do
    {
        tmp=p;
        tmp.rearrange(task_order);
        std::cout << tmp << "\n";

        time = tmp.simulate(true);
        //std::cout << "TIME = " << time << "\n";

        if( (time < minimal_time) || minimal_time==0)
        {
            minimal_time = time;
            //std::cout << "MINIMAL TIME = " << minimal_time << "\n";
            optimal_task_order = task_order;
        }

    }
    while (std::next_permutation(task_order.begin(), task_order.end()));

    tmp=p;
    tmp.rearrange(optimal_task_order);

    std::cout << "OPTIMAL: " << optimal_task_order << " (" << minimal_time << ")\n";

    Solution result(p.get_tasks());
    return result;
}
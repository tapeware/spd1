#include "Problem.h"
#include "Solution.h"
#include "Task.h"
#include "Heur.h"


int main()
{
    const std::string file_path = "../dane/SCHRAGE1.DAT";

    Problem p(file_path);

    std::cout << p << "\n";

    Solution test1(p.get_tasks());
    test1.print_solution();

    std::cout<<std::endl;

    Heur heur(p.get_tasks());

    Solution heur_qj(heur.qj_sort());
    heur_qj.print_solution();

    std::cout<<std::endl;
    Solution heur_rj(heur.rj_sort());
    heur_rj.print_solution();




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
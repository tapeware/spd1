#include "algorithms.h"
#include "Problem.h"
#include "Solution.h"
#include "Task.h"
#include "Heur.h"
#include <chrono>
#include "Schrage_alg.h"


int main()
{
    const std::string file_path1 = "../dane/test.txt";
    const std::string file_path2 = "../dane/test1.txt";
    const std::string file_path3 = "../dane/SCHRAGE3.DAT";

    Problem p(file_path3);

    Timer t;
    std::vector<Task> tasks(p.get_tasks());
    Schrage schrage(tasks);
    int s;
    t.start();
    //std::cout << p.simulate(true);
    s= schrage.schrage_with_div_sort();
   // Solution s1 (schrage.schrage_sort());
    t.stop();

    //std::cout << s1 << "  CZAS: "<< t.get_measurement() << "us" <<  "\n";
    std::cout <<"Cmax:"<< s << "  CZAS: "<< t.get_measurement() << "us" <<  "\n";

    //overview(p);

    //Solution test1(p.get_tasks());
    //test1.print_solution();
    //std::cout<<std::endl;

    // std::vector<Task> tasks = p.get_tasks();

    // Heur heur(tasks);

    // std::vector<Task> sorted_by_qj = heur.qj_sort();
    // Solution heur_qj(sorted_by_qj);
    // //heur_qj.print_solution();
    // std::cout << "Posortowane po qj: \n"<< heur_qj <<"\n";
    //
    // std::vector<Task> sorted_by_rj = heur.rj_sort();
    // Solution heur_rj(sorted_by_rj);
    // //heur_rj.print_solution();
    // std::cout << "Posortowane po rj: \n"<< heur_rj <<"\n";
    //
    // Solution sorted_by_my_alg = my_algorithm(p);
    // std::cout << "Posortowane po wlasnym algorytmie: \n"<< sorted_by_my_alg <<"\n";
    //
    // std::cout << "Czas: " << p.simulate(true) << "\n";

    //std::cout<<std::endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
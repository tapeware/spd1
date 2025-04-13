#include "algorithms.h"
#include "Problem.h"
#include "Solution.h"
#include "Task.h"
#include "Heur.h"
#include "Schrage_alg.h"

void test_algorithms(unsigned int test_begin, unsigned int test_end)
{
    std::string file_path;
    for (unsigned int i=test_begin; i<=test_end; i++)
    {
        Timer t;
        std::stringstream input_name;
        input_name << "../dane/SCHRAGE" << i << ".DAT";
        file_path = input_name.str();
        std::cout<<"\nSCHRAGE" << i << ":\n";
        Problem p(file_path);
        auto tasks = p.get_tasks();

        // ==== HEUR RJ ==== //
        // t=Timer();
        // Heur rj_sort(tasks);
        //
        // t.start();
        // Solution s_heur_rj (rj_sort.rj_sort());
        // t.stop();
        //
        // std::cout<<"    rj sort: \n        "<< s_heur_rj << "\n"
        //          <<"        ";
        // t.print_measurement();
        //
        //
        // // ==== HEUR QJ ==== //
        // t=Timer();
        // Heur qj_sort(tasks);
        //
        // t.start();
        // Solution s_heur_qj (qj_sort.qj_sort());
        // t.stop();
        //
        // std::cout<<"    qj sort: \n        "<< s_heur_qj << "\n"
        //          <<"        ";
        // t.print_measurement();
        //
        // // ==== OUR OWN ==== //
        // t=Timer();
        //
        // t.start();
        // Solution s_own = my_algorithm(p);
        // t.stop();
        //
        // std::cout<<"    our own: \n        "<< s_own << "\n"
        //          <<"        ";
        // t.print_measurement();

        // ==== SCHRAGE ==== //
        t=Timer();
        Schrage sch(tasks);

        t.start();
        Solution s_sch = sch.schrage_with_div_sort();
        t.stop();

        std::cout<<"    schrage: \n        "<< s_sch << "\n"
                 <<"        ";
        t.print_measurement();

        // ==== CARLIER ==== //
        t=Timer();

        t.start();
        Solution s_car = carlier(p);
        t.stop();

        std::cout<<"    carlier: \n        "<< s_car << "\n"
                 <<"        ";
        t.print_measurement();

        //std::cout << "    c = " << s_sch.get_c() << "\n";

    }
}

void test_car() {
    Timer t;
    std::string file_path;
    std::stringstream input_name;
    input_name << "../dane/SCHRAGE3.DAT";
    file_path = input_name.str();
    std::cout<<"\nSCHRAGE3" << ":\n";
    Problem p(file_path);
    auto tasks = p.get_tasks();


    // t=Timer();
    // Schrage sch(tasks);
    //
    // t.start();
    // Solution s_sch = sch.schrage_sort();
    // t.stop();
    //
    // std::cout<<"    schrage: \n        "<< s_sch << "\n"
    //          <<"        ";
    // t.print_measurement();

    // ==== SCHRAGE ==== //
    // t=Timer();
    //
    // t.start();
    Solution s_car = carlier(p);
    //t.stop();

    std::cout<<"    carlier: \n        "<< s_car << "\n"
             <<"        ";
    //t.print_measurement();
}

int main()
{
    const std::string file_path1 = "../dane/test.txt";
    const std::string file_path2 = "../dane/test2.txt";
    const std::string file_path3 = "../dane/SCHRAGE4.DAT";

    Problem p(file_path3);


    test_algorithms(1, 9);

    //test_car();



    //t.start();
    //Solution sol = sch.schrage_with_div_sort();
    //Solution sol = sch.schrage_sort();
    //Problem p2(sch.schrage_sort());
    //cmax = p2.simulate(true);

    //t.stop();

    //std::cout << sol << "\n";

    //t.print_measurement();

    //overview(p);

    //Solution test1(p.get_tasks());
    //test1.print_solution();
    //std::cout<<std::endl;
    // std::vector<Task> tasks = p.get_tasks();
    // Heur heur(tasks);
    //
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

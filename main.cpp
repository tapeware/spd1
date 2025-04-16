#include "algorithms.h"
#include "Problem.h"
#include "Solution.h"
#include "Heur.h"
#include "Schrage_alg.h"
#include <cstdlib>

#define MAX_PARAMETER 1024
#define MIN_PARAMETER 1
#define INSTANCE_TIMES 3
#define MIN_SIZE 5
#define MAX_SIZE 12


void test_one_instance(const std::string& file_path)
{
    Timer t;
    Problem p(file_path);
    auto tasks = p.get_tasks();
    std::cout <<"size = " << tasks.size() << "\n";

    // ==== HEUR RJ ==== //
    t=Timer();
    Heur rj_sort(tasks);

    t.start();
    Solution s_heur_rj (rj_sort.rj_sort());
    t.stop();

    std::cout<<"    rj sort: \n        "<< s_heur_rj << "\n"
             <<"        ";
    t.print_measurement();


    // ==== HEUR QJ ==== //
    t=Timer();
    Heur qj_sort(tasks);

    t.start();
    Solution s_heur_qj (qj_sort.qj_sort());
    t.stop();

    std::cout<<"    qj sort: \n        "<< s_heur_qj << "\n"
             <<"        ";
    t.print_measurement();



    // ==== ZUPELNY ==== //

    if(p.get_task_count() <= 10)
    {
        t=Timer();
        t.start();
        Solution s_ov = overview(p);
        t.stop();

        std::cout<<"    overview: \n        "<< s_ov << "\n"
                 <<"        ";
        t.print_measurement();
    }


    // ==== OUR OWN ==== //
    t=Timer();

    t.start();
    Solution s_own = my_algorithm(p);
    t.stop();

    std::cout<<"    our own: \n        "<< s_own << "\n"
             <<"        ";
    t.print_measurement();

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
}

void test_algorithms(unsigned int test_begin, unsigned int test_end)
{
    for (unsigned int i=test_begin; i<=test_end; i++)
    {
        std::stringstream input_name;
        std::string file_path;

        input_name << "../dane/SCHRAGE" << i <<".DAT";
        file_path = input_name.str();

        test_one_instance(file_path);

    }
}

void generate_instance(unsigned int tasks, unsigned int index, unsigned int max, unsigned int min)
{
    std::string file_name = "../dane/test_instance" + std::to_string(index);
    std::ofstream output(file_name);

    output << tasks << "\n";

    for (unsigned int i=0; i<tasks; i++)
    {
        output << min + (rand() % (max-min+1)) << " ";
        output << (min + (rand() % (max-min+1)))/10 << " ";
        output << min + (rand() % (max-min+1)) << "\n";
    }


}

void generate_test_instances()
{
    unsigned int index=0;

    for(unsigned int i=MIN_SIZE; i<=MAX_SIZE; i++)
    {
        for(unsigned int t=0; t<INSTANCE_TIMES; t++)
        {
            generate_instance(i, index++, MAX_PARAMETER, MIN_PARAMETER);
        }
    }

}

long double calculate_mean_time(const std::vector<long double>& times)
{
    long double sum=0.0;
    for (long double t : times) sum+=t;
    return sum/times.size();
}

std::string time_with_unit(long double time)
{
    long double duration = time;
    long double number_to_print;
    std::string unit;
    std::stringstream result;

    if(duration <= 1000.0)
    {
        unit = "ns";
        number_to_print = duration;
    }
    else if(duration <= 1000'000.0)
    {
        unit = "us";
        number_to_print = duration/1000.0;
    }
    else if(duration <= 1000'000'000.0)
    {
        unit = "ms";
        number_to_print = duration/1000'000.0;
    }
    else
    {
        unit = "s";
        number_to_print = duration/1000'000'000.0;
    }

    result << std::fixed << std::setprecision(3)<< number_to_print << unit << "\n";
    return result.str();
}

void test_final()
{
    unsigned int index=0;
    for(unsigned int i=MIN_SIZE; i<=MAX_SIZE; i++)
    {
        std::vector<long double> times;
        for(unsigned int t=0; t<INSTANCE_TIMES; t++)
        {
            index++;
            std::string file_name = "../dane/test_instance" + std::to_string(i);
            Problem p(file_name);
            Timer tm;

            tm.start();
            Solution s = overview(p);
            tm.stop();

            times.push_back(tm.get_measurement());
        }

        std::cout << "file nr " << index << "\n";
        std::cout << "mean time: " << time_with_unit(calculate_mean_time(times)) << "\n";
    }

}

int main()
{
    srand(time(nullptr));
    const std::string file_path1 = "../dane/test.txt";
    const std::string file_path2 = "../dane/test2.txt";
    const std::string file_path3 = "../dane/SCHRAGE4.DAT";

    test_algorithms(1,9);

    return 0;
}

//
// Created by mikolaj on 3/26/25.
//

#include "Problem.h"


Problem::Problem(const std::string& file_path)
{
    unsigned int task_count=0, pj=0, rj=0, qj=0;
    std::ifstream input(file_path);
    //Task tmp;

    if(!input.is_open())
        perror("File opening error");

    input >> task_count;

    for (unsigned int i=0; i<task_count; i++)
    {
        input >> pj >> rj >> qj;
        Task tmp(pj,rj,qj);
        //std::cout << tmp << "\n";
        append_task(tmp);
        //std::cout << "pj: " << pj << ", rj: " << rj << ", qj: " << qj << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Problem& p)
{
    std::stringstream formatted_string;
    Task tmp;
    unsigned int task_count = p.get_task_count();

    formatted_string << "Total tasks: " << task_count << "\n";
    for (unsigned int i=0; i<task_count; i++)
    {
        tmp = p.get_task_by_index(i);
        formatted_string << i+1 << ") pj=" << tmp.get_pj()
                                << ", rj=" << tmp.get_rj()
                                << ", qj=" << tmp.get_qj()
                                << "\n";

    }

    os << formatted_string.str();
    return os;
}
#ifndef DATA_H
#define DATA_H

#include <string>
#include <ctime>

struct Data{
    Data();
    
    unsigned dia;
    unsigned mes;
    unsigned ano;

    void set_from_string(const std::string& time);
    std::string toString();
};

#endif
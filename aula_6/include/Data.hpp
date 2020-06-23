#ifndef DATA_H
#define DATA_H

#include <string>
#include <ctime>

struct Data{
    std::string format_current_date(const std::string &format);
    std::string get_current_date();
    std::string get_current_time();
    
    unsigned dia;
    unsigned mes;
    unsigned ano;

    void set_from_string(const std::string& time);
};

#endif
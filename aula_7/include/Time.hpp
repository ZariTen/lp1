#ifndef TIME_H
#define TIME_H

#include <string>
#include <ctime>

struct Time{
    std::string format_current_date(const std::string &format);
    std::string get_current_date();
    std::string get_current_time();

    unsigned hora;
    unsigned minutos;
    unsigned segundos;

    void set_from_string(const std::string& time);
};

#endif
#ifndef TIME_H
#define TIME_H

#include <string>
#include <ctime>

struct Time{
    Time();

    unsigned hora;
    unsigned minutos;
    unsigned segundos;

    void set_from_string(const std::string& time);
    std::string toString();
};

#endif
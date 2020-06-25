#include "Time.hpp"
#include <sstream>

Time::Time() : hora(0),minutos(0),segundos(0){}


void Time::set_from_string(const std::string& time){

    std::stringstream stream(time);
    char discard;

    stream >> hora;
    stream >> discard;
    stream >> minutos;
    stream >> discard;
    stream >> segundos;

}

std::string Time::toString(){
    std::stringstream str;
    str << std::to_string(hora) << ":" << std::to_string(minutos) << ":" << std::to_string(segundos);

    return str.str();
}
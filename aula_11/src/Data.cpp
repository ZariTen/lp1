#include "Data.hpp"
#include <sstream>

Data::Data() : dia(0),mes(0),ano(0){}


void Data::set_from_string(const std::string& time){

    std::stringstream stream(time);
    char discard;

    stream >> dia;
    stream >> discard;
    stream >> mes;
    stream >> discard;
    stream >> ano;

}

std::string Data::toString(){
    std::stringstream str;
    str << std::to_string(dia) << "/" << std::to_string(mes) << "/" << std::to_string(ano);

    return str.str();
}
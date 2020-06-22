#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <ctime>


std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();


struct Mensagem {

    std::string conteudo;
    std::string data;
    std::string hora;

};




#endif
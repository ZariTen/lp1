#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <ctime>




struct Time{
    std::string format_current_date(const std::string &format);
    std::string get_current_date();
    std::string get_current_time();
    
    int data;
    int hora;
    int minutos;
};


struct Mensagem {

    std::string conteudo;
    Time time;

};




#endif
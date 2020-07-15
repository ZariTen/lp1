#include "clientepj.hpp"

void clientepj::setRazao(std::string razao){
    this->razaoSocial = razao;
}

void clientepj::setCnpj(std::string cnpj){
    this->cnpj = cnpj;
}

std::string clientepj::getCnpj(){
    return this->cnpj;
}

std::string clientepj::getRazao(){
    return this->razaoSocial;
}

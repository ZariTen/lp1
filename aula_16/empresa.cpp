#include "empresa.hpp"

void empresa::setNome(std::string name){
    this->nome = name;
}

void empresa::contratar(funcionario& f){
    this->funcionarios.push_back(f);
    //f.setEmpresa(*this);
}

std::vector<funcionario> &empresa::getFuncionarios(){
    return funcionarios;
}

void empresa::setCNPJ(std::string cnpjset){
    this->cnpj = cnpjset;
}

std::string empresa::getNome(){
    return this->nome;
}

std::string empresa::getCNPJ(){
    return this->cnpj;
}
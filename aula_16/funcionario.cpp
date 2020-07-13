#include "funcionario.hpp"

funcionario::funcionario(std::string name,std::string dataAdmissao){
    this->nome = name;
    this->dataAdmissao = dataAdmissao;
}


void funcionario::setSalario(float salar){
    this->salario = salar;
}

float funcionario::getSalario(){
    return this->salario;
}


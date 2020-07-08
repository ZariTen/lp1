#include "cliente.hpp"

int Cliente::clienteQuantidade;

Cliente::Cliente(std::string name,std::string cpfv) : nome(name),cpf(cpfv){
    clienteQuantidade+=1;
}
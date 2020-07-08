#include "cliente.hpp"

int cliente::clienteQuantidade;

cliente::cliente(std::string name,std::string cpfv) : nome(name),cpf(cpfv){
    clienteQuantidade+=1;
}
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class cliente{
    public:
        std::string nome;
        std::string cpf;

        static int clienteQuantidade;
        cliente(std::string name,std::string cpfv);
};

#endif
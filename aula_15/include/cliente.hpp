#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente{
    public:
        std::string nome;
        std::string cpf;

        static int clienteQuantidade;
        Cliente(std::string name,std::string cpfv);
};

#endif
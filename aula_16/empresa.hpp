#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include "funcionario.hpp"

class empresa{
    private:
        std::string nome;
        std::string cnpj;
        std::vector<funcionario> funcionarios;

    public:
        void setNome(std::string name);
        void setCNPJ(std::string cnpjset);

        void contratar(funcionario& f);


        std::vector<funcionario> &getFuncionarios();
        std::string getNome();
        std::string getCNPJ();

};


#endif
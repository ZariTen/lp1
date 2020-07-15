#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class produto{
    public:
        produto();
        produto(std::string nome,int codigo,std::string unidade,float preco,int quantidade);
        std::string nameProduct;
        int codigo;
        std::string unidadeMedida;
        float preco;
        int quantidade;
};


#endif
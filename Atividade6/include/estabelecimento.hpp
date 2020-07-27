#ifndef ESTAB_H
#define ESTAB_H

#include <string>
#include "produto.hpp"
#include "vetor_supermercado.hpp"

class estabelecimento{
    public:
        std::string caixaNome;
        std::string listarNome;
        vetor_supermercado<produto> produtos; //Vetor de produtos do mercado

        bool vender(int codigoProduto); //Modificar estoque.csv e criar caixa.csv
        void caixa(); //Atualizar caixa
        void listar();
        void atualizarEstoque();

        std::string separateString(std::string str,int index);
        float toPrice(std::string str);
};

#endif
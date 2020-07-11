#ifndef ESTAB_H
#define ESTAB_H

#include <string>
#include "produto.hpp"
#include <vector>

class estabelecimento{
    public:
        estabelecimento();
        ~estabelecimento();
        std::vector<produto> produtos; //Vetor de produtos do mercado

        void consultar(); //Consultar estoque.csv e insere os produtos da lista
        void atualizarEstoque(); //Atualiza o estoque com informações dos produtos salvos
        void listar(); //Listar produtos de estoque.csv
        bool vender(int codigoProduto); //Modificar estoque.csv e criar caixa.csv
        void caixa(); //Listar caixa.csv
};

#endif
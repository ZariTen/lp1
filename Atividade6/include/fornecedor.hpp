#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "vetor_supermercado.hpp"
#include "produto.hpp"
#include "estabelecimento.hpp"
#include <string>

class fornecedor{
    private:
        void atualizarLista(); //Atualizar os numeros em fornecedor.csv
    public:
        vetor_supermercado<produto> produtosEstoque;
        fornecedor();
        void atualizarProdutos(); //Atualiza produtosEstoque
        void listarProdutos(); //Listar produtos de fornecedor.csv
        void repassarProdutos(std::string produtoN,estabelecimento e,int quantidade); //Retirar de fornecedor.csv e adicionar em estoque 
};

#endif
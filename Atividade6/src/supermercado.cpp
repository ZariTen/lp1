#include "supermercado.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

supermercado::supermercado(){
    listarNome = "estoque.csv";
    caixaNome = "caixa_mercado.csv";
    consultar(); //Inicializar com a lista de produtos atualizada para não haver erro
    std::ofstream caixa(caixaNome);
    caixa << "COD,PRODUTO,QUANTIDADE,TOTAL" << std::endl;
    caixa.close();
}

supermercado::~supermercado(){
    atualizarEstoque();
    caixa();
}

void supermercado::consultar(){
    std::ifstream arquivo("estoque.csv");

    std::string linha;
    int linhaCount=0;
    produtos.clear();

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 && linha != ""){
            produto p;
            p.codigo = linhaCount;
            p.unidadeMedida = separateString(linha,3);
            p.preco = toPrice(separateString(linha,4));
            p.quantidade = std::stoi(separateString(linha,5));
            p.nameProduct = separateString(linha,2);
            produtos.adicionar(p);
            linhaCount++;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}

void supermercado::atualizarEstoque(){
    std::ofstream arquivo("estoque.csv");

    arquivo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

    for(int i = 0; i < produtos.size; ++i){
        produto p = produtos.listagem[i];
        produto empty;
        if (p.codigo == i+1 || p.nameProduct != empty.nameProduct){
            arquivo << p.codigo << "," << p.nameProduct << "," << p.unidadeMedida
            << "," << "\"R$ " << p.preco << "\"" << "," << p.quantidade << std::endl;
        }
    }

    arquivo.close();
}

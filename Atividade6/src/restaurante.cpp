#include "restaurante.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

restaurante::restaurante(){
    listarNome = "menu.csv";
    caixaNome = "caixa_restaurante.csv";
    consultar(); //Inicializar com a lista de produtos atualizada para não haver erro
    std::ofstream caixa(caixaNome);
    caixa << "COD,PRODUTO,QUANTIDADE,TOTAL" << std::endl;
    caixa.close();
}

restaurante::~restaurante(){
    caixa();
}

void restaurante::consultar(){
    std::ifstream arquivo("menu.csv");

    std::string linha;
    int linhaCount=0;
    produtos.clear();

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 && linha != ""){
            produto p;
            p.codigo = linhaCount;
            p.unidadeMedida = "";
            p.preco = toPrice(separateString(linha,2));
            p.quantidade = 999;
            p.nameProduct = separateString(linha,1);
            produtos.adicionar(p);
            linhaCount++;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}
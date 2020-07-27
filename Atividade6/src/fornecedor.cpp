#include "fornecedor.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

fornecedor::fornecedor(){
    atualizarProdutos();
}

void fornecedor::atualizarLista(){
    std::ofstream arquivo("fornecedor.csv");

    arquivo << "PRODUTO,QUANTIDADE" << std::endl;

    for(int i = 0; i < produtosEstoque.size; ++i){
        produto p = produtosEstoque.listagem[i];
        if (p.codigo != 0){
            arquivo << p.nameProduct << "," << p.quantidade << std::endl;
        }
    }

    arquivo.close();
}

std::string separateStringF(std::string str,int index){
    std::stringstream ss(str);
    std::vector<std::string> vect;
    index = index - 1;

    while(ss.good()){
        std::string substr;
        std::getline(ss,substr,',');
        vect.push_back(substr);
    }

    return vect[index];
}

void fornecedor::listarProdutos(){
    std::ifstream arquivo("fornecedor.csv");

    std::string linha;
    int linhaCount=0;

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 ){
            std::cout << separateStringF(linha,1) << " - Restantes: "<< separateStringF(linha,2)
            << std::endl;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}

void fornecedor::atualizarProdutos(){
    std::ifstream arquivo("fornecedor.csv");

    std::string linha;
    int linhaCount=0;
    produtosEstoque.clear();

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 && linha != ""){
            produto p;
            p.nameProduct = separateStringF(linha,1);
            p.quantidade = std::stoi(separateStringF(linha,2));
            produtosEstoque.adicionar(p);
            linhaCount++;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}

void fornecedor::repassarProdutos(std::string produtoN,estabelecimento e,int quantidade){
    for(int i = 0; i < produtosEstoque.size; ++i){

        if(produtosEstoque.listagem[i].nameProduct == produtoN){

            if (produtosEstoque.listagem[i].quantidade < quantidade){
                std::cout << "O fornecedor tem apenas " << produtosEstoque.listagem[i].quantidade
                 << " " << produtoN << " disponiveis" << std::endl;
                break;
            }
            else{
                std::cout << quantidade << std::endl;
                e.produtos.listagem[i].quantidade += quantidade;
                //e.atualizarEstoque();
                produtosEstoque.listagem[i].quantidade -= quantidade;
                atualizarLista();
                std::cout << "Produto reabastecido" << std::endl;

            }

            
        }
    }

    atualizarProdutos();

}
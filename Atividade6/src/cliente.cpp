#include "cliente.hpp"
#include "iostream"
#include <fstream>

cliente::cliente(float saldoInicial) : saldo(saldoInicial){}

int cliente::clientesCount = 0;

void cliente::restart(cliente *c){
    c = new cliente(0);
    this->saldo = 0;
}

bool cliente::compra(std::string nomeProduto,estabelecimento& e){

    produto produtoComprar;
    //Achar produto pelo nome
    int codigoProduto;
    for(int i = 0; i < e.produtos.size;++i){
        std::string name = e.produtos.listagem[i].nameProduct;

        for(auto& c : name){
            c = tolower(c); //Transforma tudo em minusculo
        }

        for(auto& c : nomeProduto){
            c = tolower(c);
        }
        
        if(name == nomeProduto){
            codigoProduto = e.produtos.listagem[i].codigo-1;
            produtoComprar = e.produtos.listagem[i];
            break;
        }
    }
     
    //Checar saldo
    if(saldo < produtoComprar.preco){
        std::cout << "Cliente sem saldo para a compra" << std::endl;
        return false;
    }
    else if(produtoComprar.quantidade == 0){
        std::cout << "Mercado com falta de " << nomeProduto << std::endl;
        return false;
    }
    else{//Retirar saldo e adicionar na sacola
        std::cout << "Cliente comprou " << produtoComprar.nameProduct << " por R$" << produtoComprar.preco << std::endl;
        e.vender(codigoProduto);
        saldo -= produtoComprar.preco;
        sacola.adicionar(produtoComprar);
        std::cout << "Saldo atual: " << saldo << std::endl;
        return true;
    }
}

void cliente::verSacola(){
    for (int i = 0; i < sacola.size; ++i){
        std::cout << sacola.listagem[i].nameProduct << " - R$" << sacola.listagem[i].preco << std::endl;
    }
}

void cliente::registro(){
    clientesCount += 1;
    std::ofstream arquivo("cliente_"+std::to_string(clientesCount)+".txt");

    for (int i = 0; i < sacola.size; ++i){
        arquivo << sacola.listagem[i].nameProduct << " - R$" << sacola.listagem[i].preco << std::endl;
    }
}
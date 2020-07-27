#include <iostream>
#include "restaurante.hpp"
#include "supermercado.hpp"
#include "cliente.hpp"
#include "fornecedor.hpp"

void display_menu(int saldo);
void choicef(std::string choosen,cliente& c,estabelecimento& e,fornecedor& f);
void choiceLoop(cliente& c,fornecedor& f,estabelecimento& e);

int main(int argc, char* argv[]){
    std::string choice;
    cliente c(500);

    std::cout << "Supermercado ou restaurando (s/r)" << std::endl;
    
    std::cin >> choice;

    if (choice == "s"){
        supermercado mercado;
        
        fornecedor f;
        choiceLoop(c,f,mercado);
    }
    else{
        restaurante mercado;
        fornecedor f; //Não usado
        choiceLoop(c,f,mercado);
    }
    
    
    
    
}

void choiceLoop(cliente& c,fornecedor& f,estabelecimento& e){
    std::string choice;
    while (choice != "x"){
        display_menu(c.saldo);
        std::cin >> choice;
        choicef(choice,c,e,f);
    }
}

void choicef(std::string choosen,cliente& c,estabelecimento& e,fornecedor& f){
    if (choosen == "1"){
        int saldo;
        std::cout << "Quanto deseja adicionar: ";
        std::cin >> saldo;
        c.saldo += saldo;
    }
    else if (choosen == "2"){
        e.listar();
    }
    else if (choosen == "3"){
        c.verSacola();
    }
    else if  (choosen == "4"){
        std::cout << "O que deseja comprar: ";
        std::string produtoC;
        std::cin >> produtoC;
        c.compra(produtoC,e);
    }
    else if (choosen == "5"){
        f.listarProdutos();
    }
    else if (choosen == "6"){
        std::cout << "O que deseja reabastecer: ";
        std::string produtoC;
        std::cin >> produtoC;

        std::cout << std::endl;
        std::cout << "Quantas unidades: ";
        int i;
        std::cin >> i;

        f.repassarProdutos(produtoC,e,i);
    }
    else if (choosen == "0"){
        std::cout << "Deseja adicionar mais um cliente (y/n)" << std::endl;
        std::string choiceClient;
        std::cin >> choiceClient;
        if (choiceClient == "n"){
            std::exit(0);
        }
        else{
            c.registro();
            c.restart(&c);
        }
    }
}

void display_menu(int saldo){
    std::cout << std::endl << "Supermercado - 1.0" << std::endl;
    std::cout << "Seu saldo é de " << saldo << " Reais" << std::endl;
    std::cout << "O que gostaria de fazer: " << std::endl;
    std::cout << "1 - Adicionar saldo" << std::endl;
    std::cout << "2 - Verificar produtos" << std::endl;
    std::cout << "3 - Ver conteúdo da sacola" << std::endl;
    std::cout << "4 - Comprar algo" << std::endl;
    std::cout << "5 - Ver fornecedor" << std::endl;
    std::cout << "6 - Reabastecer estoque" << std::endl;
    std::cout << "0 - Finalizar compra do cliente" << std::endl;
}
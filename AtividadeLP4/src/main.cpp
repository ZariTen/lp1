#include <iostream>
#include "estabelecimento.hpp"
#include "cliente.hpp"

void display_menu(int saldo);
void choicef(std::string choosen,cliente& c,estabelecimento& e);

int main(int argc, char* argv[]){
    estabelecimento mercado;
    cliente c(0);

    std::string choice;

    while (choice != "x"){
        display_menu(c.saldo);
        std::cin >> choice;
        choicef(choice,c,mercado);
    }
    
}

void choicef(std::string choosen,cliente& c,estabelecimento& e){
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
    std::cout << "0 - Finalizar compra do cliente" << std::endl;
}
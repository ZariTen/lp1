#ifndef CLIENTE_H
#define CLIENTE_H

#include "produto.hpp"
#include "estabelecimento.hpp"
#include <vector>

class cliente{
    public:
        cliente(float saldoInicial);

        float saldo;
        std::vector<produto> sacola;

        static int clientesCount;

        void restart(cliente *c); //reinicia o cliente

        bool compra(std::string nomeProduto,estabelecimento& e); /*Comprar produto, checar saldo,
        retirar saldo, metodo vender do estabelecimento */
        void verSacola(); //Printar produtos na sacola
        void registro(); //Criar arquivo cliente_x.txt com sacola nela
};

#endif
#ifndef CONTA_H
#define CONTA_H

#include <string>
#include "cliente.hpp"
#include "agencia.hpp"

class Conta{
    public:
        static int quantidadeContas;
        Cliente contaCliente;
        Agencia contaAgencia;

        std::string numero;
        std::string titular; 

        int saldo;

        Conta(Cliente c,Agencia a);
        void sacar(int dinheiroSacado);
        void depositar(int dinheiroDepositado);
        void transferir(int dinheiroTransferido, Conta& c);

};


#endif
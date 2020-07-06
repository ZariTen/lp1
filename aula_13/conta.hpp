#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta{
    public:
        int numero;
        std::string titular; 
        int saldo;
        void sacar(int dinheiroSacado);
        void depositar(int dinheiroDepositado);
        void transferir(int dinheiroTransferido, Conta& c);

};


#endif
#include "conta.hpp"

void Conta::depositar(int dinheiroDepositado){
    this->saldo += dinheiroDepositado;
}

void Conta::sacar(int dinheiroSacado){
    this->saldo -= dinheiroSacado;
}

void Conta::transferir(int dinheiroTransferido, Conta& c){
    this->saldo -= dinheiroTransferido;

    c.depositar(dinheiroTransferido);
}
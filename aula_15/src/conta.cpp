#include "conta.hpp"

int Conta::quantidadeContas;

Conta::Conta(cliente c, agencia a) : contaCliente(c),contaAgencia(a){
    quantidadeContas+=1;
}

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
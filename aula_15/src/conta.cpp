#include "conta.hpp"

int Conta::quantidadeContas;

Conta::Conta(Cliente c, Agencia a) : contaCliente(c),contaAgencia(a){
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
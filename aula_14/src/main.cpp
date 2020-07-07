#include <iostream>
#include "conta.hpp"

int main(int argc, char *argv[]){
    Conta contaum;
    Conta contadois;


    contaum.saldo = 100;
    contadois.saldo = 10;

    contaum.transferir(30,contadois);
    std::cout << contaum.saldo << std::endl;
    std::cout << contadois.saldo << std::endl;


    return 0;
}

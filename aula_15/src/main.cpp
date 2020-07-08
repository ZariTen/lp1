#include <iostream>
#include "cliente.hpp"
#include "agencia.hpp"
#include "conta.hpp"



int main(int argc, char *argv[]){
    Agencia agbr;
    Cliente c1("Jose","000.000.000");
    Cliente c2("Joao","000.111.000");
    Conta contaum(c1,agbr);
    Conta contadois(c2,agbr);

    std::cout << contaum.quantidadeContas << std::endl;


    return 0;
}

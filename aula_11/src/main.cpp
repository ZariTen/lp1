#include <iostream>

#include "App.hpp"

int main(int argc, char *argv[]){

    App aplicativo("diario.txt");

    aplicativo.run(argc,argv);
    aplicativo.searchMsg("dia");
    
    return 1;
}


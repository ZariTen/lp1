#include <iostream>


#include "App.hpp"

int main(int argc, char *argv[]){
    App aplicativo("diario.txt");
    return aplicativo.run(argc,argv);
}


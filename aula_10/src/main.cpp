#include <iostream>

#include "App.hpp"

int main(int argc, char *argv[]){
    std::string date = "25/06/2020";

    App aplicativo("diario.txt");


    //aplicativo.searchMsg("duas");
    aplicativo.run(argc,argv);
    


    return 1;
}


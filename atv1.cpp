#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    if (argc <= 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>";
        return -1;
    }

    std::string msg;
    if (argc == 2 && std::string(argv[1]) == "add"){ //Recebeu apenas add
        std::cout << "Adicione uma mensagem: ";
        std::getline(std::cin,msg);
        std::cout << msg;
    }
    else if (argc == 3 && std::string(argv[1]) == "add")
    {
        std::cout << "Mensagem: " << argv[2];
    }
    return 0;
}
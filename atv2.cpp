#include <iostream>
#include <string>
#include <fstream>

void show_usage(std::string nome);

int main(int argc, char *argv[]){
    if (argc <= 1){
        show_usage(argv[0]);
    }

    std::string msg;
    if (argc == 2 && std::string(argv[1]) == "add"){ //Recebeu apenas add
        std::cout << "Adicione uma mensagem: ";
        std::getline(std::cin,msg);
    }
    else if (argc == 3 && std::string(argv[1]) == "add")
    {
        msg =  std::string(argv[2]);
    }

    std::ofstream arquivo_saida ("arquivo.txt",std::ios::app); //Cria/abre o arquivo com append para adicionar linha nele

    if (arquivo_saida.is_open()){
        arquivo_saida << msg << std::endl; //Escreve a variavel msg no arquivo
    }else{
        std::cout << "Falha ao abrir o arquivo";
        return -1;
    }
    
    return 0;
}

void show_usage(std::string nome){
    std::cout << "Uso: " << nome << " add <mensagem>";
}
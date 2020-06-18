#include <iostream>
#include <string>
#include <fstream>

void show_usage(std::string nome);
void write_text(std::string txtfile,std::string msg);
void read_text(std::string txtfile);

int main(int argc, char *argv[]){
    if (argc <= 1){
        show_usage(argv[0]);
    }

    std::string command = std::string(argv[1]);
    std::string msg;

    //Checagem de comandos
    if (command == "add" && argc == 3)
    {
        msg =  std::string(argv[2]);
        write_text("arquivo.txt",msg);
    }
    else if(command == "list"){
        read_text("arquivo.txt");
    }

    return 0;
}

void show_usage(std::string nome){
    std::cout << "Uso: " << nome << " add <mensagem>";
}

void write_text(std::string txtfile,std::string msg){
    std::ofstream arquivo_saida (txtfile,std::ios::app); // Cria/abre o arquivo com append para adicionar linha nele

    if (arquivo_saida.is_open()){
        arquivo_saida << msg << std::endl; //Escreve a variavel msg no arquivo
        arquivo_saida.close();
        std::cout << "Linha adicionada com sucesso" << std::endl;
    }else{
        std::cerr << "Falha ao abrir o arquivo" << std::endl;
    }
}

void read_text(std::string txtfile){ // Mostra cada linha do arquivo para o usuário
    std::ifstream arquivo_entrada (txtfile);
    std::string linha;

    while (!arquivo_entrada.eof()){
        std::getline(arquivo_entrada,linha);

        if (linha.size() == 0){
            continue;
        }

        std::cout << linha << std::endl; // Mostra "linha" para o usuario
    }

}
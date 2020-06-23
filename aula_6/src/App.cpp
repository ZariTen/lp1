#include "App.hpp"
#include <iostream>

App::App(const std::string& filename) : diario(filename)
{
}


int App::run(int argc, char* argv[]){
    if (argc == 1){
        return showUsage();
    }

    std::string action = argv[1];

    if(action == "add"){
        if (argc == 2){
            add();
        } else{
            add(argv[2]);
        }
    }
    else if (action == "list"){
        listMensagens();
    }
    else{
        return showUsage();
    }
}

void App::add(const std::string mensagem){
    diario.adicionarMensagem(mensagem);
    diario.escreverMensagens();
}

void App::add(){
    std::string msg;
    std::cout << "Insira a mensagem" << std::endl;
    std::getline(std::cin,msg);

    add(msg);
}

void App::listMensagens(){
    for(size_t i = 0; i < diario.mensagemSize; ++i){
        const Mensagem& msg = diario.mensagem[i];
        std::cout << "-" << msg.conteudo << std::endl;
    }
}

int App::showUsage(){
    return 1;
}
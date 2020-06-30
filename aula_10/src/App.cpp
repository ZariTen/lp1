#include "App.hpp"
#include <iostream>

App::App(const std::string& filename) : diario(filename)
{
}


int App::run(int argc, char* argv[]){
    if (argc == 1){
        showUsage();
        return 0;
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
    else if (action == "load"){
        if (argc == 2){
            loadMsgs();
        }
        else{
            loadMsgs(argv[2]);
        }
    }
    else if (action == "search"){
        if (argc == 2){
            showUsage();
        }
        else{
            searchMsg(argv[2]);
        }
    }
    else{
        showUsage();
        return 0;
    }
    return 1;
}

void App::add(const std::string mensagem){
    diario.adicionarMensagem(mensagem);
    diario.escreverMensagens();
}

void App::loadMsgs(const std::string& fileName){
    diario.loadMensagem(fileName);
}

void App::searchMsg(const std::string msg){
    Mensagem* found = diario.searchMsg(msg);

    if (found == nullptr){
        std::cout << "Mensagem não encontrada..." << std::endl;
    }
    else{
        std::cout << found->conteudo << std::endl;
        delete found;
    }
}

void App::loadMsgs(){
    std::string filenm;
    std::cout << "Insira o nome do arquivo" << std::endl;
    std::getline(std::cin,filenm);

    loadMsgs(filenm);
}

void App::add(){
    std::string msg;
    std::cout << "Insira a mensagem" << std::endl;
    std::getline(std::cin,msg);

    add(msg);
}

void App::listMensagens(){
    diario.listMensagem();
}

void App::showUsage(){
    std::cout << "<nomePrograma> add|list|load|search" << std::endl;
}
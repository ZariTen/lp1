#ifndef DIARIO_H
#define DIARIO_H

#include "Message.hpp"
#include <string>


struct Diario{

    Diario(const std::string& nomeFile);
    ~Diario();

    std::string nomeArquivo;
    Mensagem* mensagem;
    size_t mensagemSize;
    size_t mensagemCapacidade;


    void adicionarMensagem(const std::string& msg);
    void adicionarMensagem(const Mensagem& msg);
    void loadMensagem(std::string arquivoAbrir);
    void escreverMensagens();
    void listMensagem();

};




#endif
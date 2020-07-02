#ifndef DIARIO_H
#define DIARIO_H

#include "Message.hpp"
#include <string>
#include <vector>

struct Diario{

    Diario(const std::string& nomeFile);
    ~Diario();

    std::string nomeArquivo;
    size_t mensagemSize;

    std::vector<Mensagem> mensagensVec; 

    void adicionarMensagem(const std::string& msg);
    void adicionarMensagem(const Mensagem& msg);
    void loadMensagem(std::string arquivoAbrir);
    void escreverMensagens();
    void listMensagem();
    std::vector<Mensagem*> searchMsg(const std::string& msg);

};




#endif
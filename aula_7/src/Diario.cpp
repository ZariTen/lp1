#include "Diario.hpp"




Diario::Diario(const std::string& nomeFile) : nomeArquivo(nomeFile),mensagem(nullptr),mensagemSize(0)
{
    mensagemCapacidade = 10;
    mensagem = new Mensagem[mensagemCapacidade];
}

Diario::~Diario(){
    delete[] mensagem;
}



void Diario::adicionarMensagem(const std::string& msg){
    //Adicionar msg a array mensagem
    if (mensagemSize > mensagemCapacidade){ //Array cheio
        return;
    }

    mensagem[mensagemSize].conteudo = msg;
    ++mensagemSize;
}

void Diario::escreverMensagens(){
    //Escrever todas as mensagens guardadas e escrever no arquivo texto
}
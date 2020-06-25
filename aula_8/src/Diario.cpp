#include "Diario.hpp"
#include "Funcs.hpp"
#include <fstream>




Diario::Diario(const std::string& nomeFile) : nomeArquivo(nomeFile),mensagem(nullptr),mensagemSize(0),mensagemCapacidade(10)
{
    mensagem = new Mensagem[mensagemCapacidade];
}

Diario::~Diario(){
    delete[] mensagem;
}



void Diario::adicionarMensagem(const std::string& msg){
    //Adicionar msg a array mensagem
    if (mensagemSize >= mensagemCapacidade){ //Array cheio
        return;
    }
    Mensagem m;
    m.conteudo = msg;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    mensagem[mensagemSize]= m;
    ++mensagemSize;
}

void Diario::escreverMensagens(){
    //Escrever todas as mensagens guardadas e escrever no arquivo texto
    std::ofstream arquivoEscrever (nomeArquivo,std::ios::app);

    for (int i = 0; i < mensagemSize; ++i){
        if(arquivoEscrever.is_open()){
            arquivoEscrever << "-" << mensagem[i].time.toString() << " " << mensagem[i].conteudo << std::endl;
        }
    }
}
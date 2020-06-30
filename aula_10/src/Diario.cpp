#include "Diario.hpp"
#include "Funcs.hpp"
#include <fstream>
#include <iostream>
#include <sstream>




Diario::Diario(const std::string& nomeFile) : nomeArquivo(nomeFile),mensagem(nullptr),mensagemSize(0),mensagemCapacidade(2)
{
    mensagem = new Mensagem[mensagemCapacidade];
}

Diario::~Diario(){
    delete[] mensagem;
}


//Adiciona mensagem para a array de mensagens
void Diario::adicionarMensagem(const std::string& msg){
    //Adicionar msg a array mensagem

    if (mensagemSize >= mensagemCapacidade){ //Array cheio
        //Cria nova array com tamanho duas vezes maior
        mensagemCapacidade *= 2;
        Mensagem* tempArray = new Mensagem[mensagemCapacidade];

        for (size_t i = 0; i < mensagemSize; ++i){ //Passa todas as mensagens para a nova array
            tempArray[i] = mensagem[i];
        }

        delete[] mensagem; //Desaloca o endereço original de mensagem
        mensagem = tempArray;//mensagem agora aponta para o novo endereço, com dobro de tamanho

    }

    Mensagem m;
    m.conteudo = msg;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    mensagem[mensagemSize]= m;
    ++mensagemSize;
}

//Verifica se a data existe no arquivo
bool checkDate(std::string nomeArquivo,Mensagem msg){
    std::ifstream arquivoLeitura(nomeArquivo);
    std::string linha;

    while(std::getline(arquivoLeitura,linha)){
        if (linha == "# "+ msg.date.toString()){
            arquivoLeitura.close();
            return true;
        }
    }
    arquivoLeitura.close();
    return false;
}

void Diario::adicionarMensagem(const Mensagem& msg){
    if (mensagemSize >= mensagemCapacidade){ //Array cheio
        //Cria nova array com tamanho duas vezes maior
        mensagemCapacidade *= 2;
        Mensagem* tempArray = new Mensagem[mensagemCapacidade];

        for (size_t i = 0; i < mensagemSize; ++i){ //Passa todas as mensagens para a nova array
            tempArray[i] = mensagem[i];
        }

        delete[] mensagem; //Desaloca o endereço original de mensagem
        mensagem = tempArray;//mensagem agora aponta para o novo endereço, com dobro de tamanho

    }

    mensagem[mensagemSize]= msg;
    ++mensagemSize;
}

Mensagem* Diario::searchMsg(const std::string& msgFind){
    std::ifstream arquivoLer(nomeArquivo);

    std::string linha;
    Mensagem* msg = new Mensagem;

    while (std::getline(arquivoLer,linha)){
        if (linha.find(msgFind) != std::string::npos){
            msg->conteudo = linha;
        }
    }

    return msg;
}

//Abre arquivo ja escrito
void Diario::loadMensagem(std::string arquivoAbrir){
    std::ifstream arquivoLer(arquivoAbrir);
    std::string linha;
    std::string data;
    Time t;

    if (!arquivoLer.is_open()){
        return;
    }

    int i = 0;
    while(std::getline(arquivoLer,linha)){

        Mensagem msg;

        if(linha[0] == '#'){
            data = linha.substr(2);
            std::cout << data << std::endl;
        }
        else if(linha[0] == '-'){
            std::string lx = linha.substr(2);
            t.set_from_string(lx);

            msg.conteudo = linha.substr(11);
            msg.date.set_from_string(data);
            msg.time.set_from_string(t.toString());

            adicionarMensagem(msg);
            ++i;
        }
    }

    arquivoLer.close();

}

//Escreve todas as mensagens na array mensagens para o arquivo
void Diario::escreverMensagens(){

    //Escrever todas as mensagens guardadas e escrever no arquivo texto
    std::ofstream arquivoEscrever (nomeArquivo,std::ios::app);
    arquivoEscrever.open(nomeArquivo,std::ios::app);

    for (size_t i = 0; i < mensagemSize; ++i){
        if(arquivoEscrever.is_open()){

            arquivoEscrever.close();
            //Data não existe
            if (!checkDate(nomeArquivo,mensagem[i])){
                arquivoEscrever.open(nomeArquivo,std::ios::app);
                arquivoEscrever << "# " << mensagem[i].date.toString() << std::endl;
                arquivoEscrever.close();
            }
            arquivoEscrever.open(nomeArquivo,std::ios::app);


            arquivoEscrever << "- " << mensagem[i].time.toString() << ": " << mensagem[i].conteudo << std::endl;
        }
    }
}

void Diario::listMensagem(){
    std::ifstream arquivoLer(nomeArquivo);
    std::string linha;

    while(std::getline(arquivoLer,linha)){


        if(linha[0] == '#'){
            continue;
        }
        else{
            std::cout << linha << std::endl;
        }
    }
}
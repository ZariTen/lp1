#include "Diario.hpp"
#include "Funcs.hpp"
#include <fstream>
#include <iostream>
#include <sstream>




Diario::Diario(const std::string& nomeFile) : nomeArquivo(nomeFile),mensagemSize(0)
{

}

Diario::~Diario(){
    //delete[] mensagem;
}


//Adiciona mensagem para a array de mensagens
void Diario::adicionarMensagem(const std::string& msg){
    //Adicionar msg a array mensagem
    Mensagem m;
    m.conteudo = msg;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    mensagensVec.push_back(m);
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
    mensagensVec.push_back(msg);
    ++mensagemSize;
}

std::vector<Mensagem*> Diario::searchMsg(const std::string& msgFind){
    std::ifstream arquivoLer(nomeArquivo);

    std::string linha;

    std::vector<Mensagem*> msgFound; 
    int findCount = 0;

    while (std::getline(arquivoLer,linha)){
        if(linha[0] != '-') {continue;}
        ++findCount;
        linha = linha.substr(11);
        if (linha.find(msgFind) != std::string::npos){
            msgFound.push_back(&mensagensVec[findCount-1]);
        }
    }

    return msgFound;
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
            if (!checkDate(nomeArquivo,mensagensVec[i])){
                arquivoEscrever.open(nomeArquivo,std::ios::app);
                arquivoEscrever << "# " << mensagensVec[i].date.toString() << std::endl;
                arquivoEscrever.close();
            }
            arquivoEscrever.open(nomeArquivo,std::ios::app);


            arquivoEscrever << "- " <<mensagensVec[i].time.toString() << ": " << mensagensVec[i].conteudo << std::endl;
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
#ifndef DIARIO_H
#define DIARIO_H

#include <string>

struct Diario{

    void adicionarMensagem(std::string msg,std::string arquivoNome);
    void listarMensagens();

};




#endif
#include "produto.hpp"


produto::produto(){}

produto::produto(std::string nome,int codigo,std::string unidade,float preco,int quantidade){
    nameProduct = nome;
    this->codigo = codigo;
    unidadeMedida = unidade;
    this->preco = preco;
    this->quantidade = quantidade;
}
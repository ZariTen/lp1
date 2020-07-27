#include "estabelecimento.hpp"
#include "vetor_supermercado.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

std::string estabelecimento::separateString(std::string str,int index){
    std::stringstream ss(str);
    std::vector<std::string> vect;
    index = index - 1;

    while(ss.good()){
        std::string substr;
        std::getline(ss,substr,',');
        vect.push_back(substr);
    }
    
    return vect[index];
}

float estabelecimento::toPrice(std::string str){
    str.replace(0,4,"");


    try{
        str.replace(str.begin()+4,str.end(),"");
    }
    catch(const std::out_of_range& e){
        str.replace(str.begin()+3,str.end(),"");
    }

    float f;
    f = std::stof(str);
    return f;
}

void estabelecimento::caixa(){
    std::ifstream caixa(caixaNome);
    float total = 0;

    std::string linha;
    int linhaCount=0;

    while(std::getline(caixa, linha)){
        if(linhaCount !=0 ){
            std::string str = separateString(linha,4);
            total+= std::stof(str.erase(0,2));
        }
        else{linhaCount++;}
    }

    caixa.close();

    std::ofstream caixai(caixaNome,std::ios::app);
    caixai << "TOTAL: R$" << total << std::endl;
    caixai.close();
}

void estabelecimento::atualizarEstoque(){

    if(listarNome == "estoque.csv"){
        std::ofstream arquivo("estoque.csv");

        arquivo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

        for(int i = 0; i < produtos.size; ++i){
            produto p = produtos.listagem[i];
            produto empty;
            if (p.codigo == i+1 || p.nameProduct != empty.nameProduct){
                arquivo << p.codigo << "," << p.nameProduct << "," << p.unidadeMedida
                << "," << "\"R$ " << p.preco << "\"" << "," << p.quantidade << std::endl;
            }
        }

        arquivo.close();
    }
    
}


void estabelecimento::listar(){
    std::ifstream arquivo(listarNome);

    std::string linha;
    int linhaCount=0;

    while(std::getline(arquivo, linha)){
        std::cout << linha << std::endl;
    }
    arquivo.close();
};

bool estabelecimento::vender(int codigoProduto){
    std::ofstream caixa(caixaNome,std::ios::app);
    produto p = produtos.listagem[codigoProduto];

    caixa << codigoProduto+1 << "," << p.nameProduct << "," 
    << 1 << ",R$" << p.preco*1 << std::endl;

    produtos.listagem[codigoProduto].quantidade -= 1;
    caixa.close();
    return true;
}
#include "estabelecimento.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

estabelecimento::estabelecimento(){
    consultar(); //Inicializar com a lista de produtos atualizada para não haver erro
    std::ofstream caixa("caixa.csv");
    caixa << "COD,PRODUTO,QUANTIDADE,TOTAL" << std::endl;
    caixa.close();
}

std::string separateString(std::string str,int index){
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

estabelecimento::~estabelecimento(){
    atualizarEstoque();
    std::ifstream caixa("caixa.csv");
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

    std::ofstream caixai("caixa.csv",std::ios::app);
    caixai << "TOTAL: R$" << total << std::endl;
    caixai.close();
    
}



float toPrice(std::string str){
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


void estabelecimento::listar(){
    std::ifstream arquivo("estoque.csv");

    std::string linha;
    int linhaCount=0;

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 ){
            std::cout << separateString(linha,2) << " - Restantes: "<< separateString(linha,5)
             << " - " << separateString(linha,4) << std::endl;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}

void estabelecimento::caixa(){
    std::ifstream arquivo("caixa.csv");

    std::string linha;
    int linhaCount=0;

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0 ){
            std::cout << linha << std::endl;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}


void estabelecimento::atualizarEstoque(){
    std::ofstream arquivo("estoque.csv");

    arquivo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

    for(int i = 0; i < produtos.size(); ++i){
        produto p = produtos[i];
        arquivo << p.codigo << "," << p.nameProduct << "," << p.unidadeMedida
        << "," << "\"R$ " << p.preco << "\"" << "," << p.quantidade << std::endl;
    }

    arquivo.close();
}

void estabelecimento::consultar(){
    std::ifstream arquivo("estoque.csv");

    std::string linha;
    int linhaCount=0;
    produtos.clear();

    while(std::getline(arquivo, linha)){
        if(linhaCount !=0){
            produto p;
            p.codigo = linhaCount;
            p.unidadeMedida = separateString(linha,3);
            p.preco = toPrice(separateString(linha,4));
            p.quantidade = std::stoi(separateString(linha,5));
            p.nameProduct = separateString(linha,2);
            produtos.push_back(p);
            linhaCount++;
        }
        else{linhaCount++;}
    }
    arquivo.close();
}

bool estabelecimento::vender(int codigoProduto){
    std::ofstream caixa("caixa.csv",std::ios::app);
    produto p = produtos[codigoProduto];

    caixa << codigoProduto+1 << "," << p.nameProduct << "," 
    << 1 << ",R$" << p.preco*1 << std::endl;

    produtos[codigoProduto].quantidade -= 1;
    atualizarEstoque();
    return true;
}
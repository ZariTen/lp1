#ifndef VETORMERCADO_H
#define VETORMERCADO_H

#include <iostream>
#define INITIAL_SIZE 5

template<class C>
class vetor_supermercado{
    private:
        int preenchido = 0;
    public:
        int size = INITIAL_SIZE;
        ~vetor_supermercado();
        
        C *listagem = new C[size];
        void adicionar(C elemento); //Adiciona no final da array
        void clear(); //Limpa a array
};
template<class C>
vetor_supermercado<C>::~vetor_supermercado(){
    delete[] listagem;
}
template <class C>
void vetor_supermercado<C>::adicionar(C elemento){
    if (preenchido >= size){//Caso o array esteja cheio, aumentar o tamanho em 10
        size += 10;

        C *temp = new C[size];
        //std::cout << "debug" << std::endl;
        for(int i = 0; i < preenchido; ++i){
            temp[i] = listagem[i];
        }
        
        delete[] listagem;
        listagem = temp;
        //std::cout << "debug2" << std::endl;
    }

    listagem[preenchido] = elemento;
    ++preenchido;
}
template <class C>
void vetor_supermercado<C>::clear(){
    size = INITIAL_SIZE;//Limpa o array e retorna ao tamanho original
    preenchido = 0;
    C *temp = new C[size];
    delete[] listagem;
    listagem = temp;
}

#endif
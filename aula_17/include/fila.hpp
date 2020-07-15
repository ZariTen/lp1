#ifndef FILA_H
#define FILA_H

#include <queue>

template <class C>
class fila{
    private:
        std::queue<C> filaQ;
    public:
        void entrarFila(C obj);
        void sairFila();
};

template<class C>
void fila<C>::entrarFila(C obj){
    filaQ.push(obj);
}

template<class C>
void fila<C>::sairFila(){
    filaQ.pop();
}

#endif
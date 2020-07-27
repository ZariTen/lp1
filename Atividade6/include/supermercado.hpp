#ifndef MERCADO_H
#define MERCADO_H

#include "estabelecimento.hpp"

class supermercado : public estabelecimento{
    public:
        supermercado();
        ~supermercado();
        void atualizarEstoque();
        void consultar();
};

#endif
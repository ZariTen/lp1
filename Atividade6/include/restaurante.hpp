#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "estabelecimento.hpp"

class restaurante : public estabelecimento{
    public:
        restaurante();
        ~restaurante();
        void consultar();
};

#endif
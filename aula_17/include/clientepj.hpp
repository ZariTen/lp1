#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

class clientepj{
    private:
        std::string razaoSocial;
        std::string cnpj;
    public:
        void setRazao(std::string razao);
        void setCnpj(std::string cnpj);

        std::string getRazao();
        std::string getCnpj();
};

#endif
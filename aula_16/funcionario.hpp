#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include <string>

class funcionario{
    private:
        std::string nome;
        //empresa empr;
        float salario;
        std::string dataAdmissao;

    public:
        funcionario(std::string name,std::string dataAdmissao);
        //void setEmpresa(empresa e);
        void setSalario(float salar);

        float getSalario();
        //empresa getEmpresa();
        


};


#endif
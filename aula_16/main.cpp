#include <iostream>
#include "funcionario.hpp"
#include "empresa.hpp"

int main(int argc,char* argv[]){
    empresa e;
    std::cout << "Quantos funcionarios" << std::endl;

    int count;
    std::cin >> count;

    for(int i = 0; i < count; ++i){
        funcionario x("Func","13/07/20");
        x.setSalario(rand() % 800);
        e.contratar(x);
    }

    for(int i = 0; i < e.getFuncionarios().size(); ++i){
        float sal = e.getFuncionarios()[i].getSalario();
        sal = sal*1.1;
        e.getFuncionarios()[i].setSalario(sal);
        std::cout << e.getFuncionarios()[i].getSalario() << std::endl;
        
    }

}
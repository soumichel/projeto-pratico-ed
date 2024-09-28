#ifndef OPERACOES_H
#define OPERACOES_H

#include <iostream>
#include "estrutura.h"

class operacoes {
private:
    void funcaoImprime(std::ostream& out, info& aux);
public:
    void inserir(long pos);
    void exibir(long posIni, long posFim, bool imprimirTudo);
    void trocar(long pos1, long pos2);
    void alterar(long id);
};

#endif // OPERACOES_H
#ifndef ESTRUTURA_H
#define ESTRUTURA_H

const int TAM_NOME = 109, TAM_CIDADE = 23, TAM_ESPORTE = 26, TAM_EVENTO = 88, TAM_NOC = 4;

struct info {
    long id;
    char nome[TAM_NOME];
    char cidade[TAM_CIDADE];
    char esporte[TAM_ESPORTE];
    char evento[TAM_EVENTO];
    char noc[TAM_NOC];
};

#endif // ESTRUTURAINFO_H

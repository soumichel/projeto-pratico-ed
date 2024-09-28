#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "leCSV.h"
#include "estrutura.h"
#include "operacoes.h"

using namespace std;

void operacoes::funcaoImprime(ostream& out, info& aux) {
    out << aux.id << ", " << aux.nome << ", " << aux.cidade << ", " << aux.esporte << ", " << aux.evento << ", " << aux.noc << endl;
}

void operacoes::exibir(long posIni, long posFim, bool eParaImprimirTudo) {
    info aux;
    posIni *= sizeof(aux);
    bool elementoEncontrado = false;
    int cont = 0;
    ifstream arquivobi("csv_em_binario.dat", ios::binary);


    cout << "Deseja imprimir os elementos na TELA ou em um ARQUIVO(recomendado)? ([T]/[A]) ";
    char opcao;
    cin >> opcao;
    if (eParaImprimirTudo) {
        ofstream novoTxt("todos-os-registros.txt");
        while (!arquivobi.eof()) {
            arquivobi.read((char*)&aux, sizeof(aux));
            if (opcao == 'T' or opcao == 't') {
                funcaoImprime(cout, aux);
            } else if (opcao == 'A' or opcao == 'a') {
                funcaoImprime(novoTxt, aux);
            }
            cont += sizeof(aux);
        }
    } else {
        ofstream novoTxt("registros-ID-" + to_string(posIni / sizeof(aux)) + "-" + to_string(posFim) + ".txt");
        arquivobi.seekg(posIni);
        while (!arquivobi.eof() and !(elementoEncontrado)) {
            arquivobi.read((char*)&aux, sizeof(aux));
            if (opcao == 'T' or opcao == 't') {
                funcaoImprime(cout, aux);
            } else if (opcao == 'A' or opcao == 'a') {
                funcaoImprime(novoTxt, aux);
            }
            if (aux.id == posFim) {
                elementoEncontrado = true;
            }
        }
    }
    arquivobi.close();
}


void operacoes::alterar(long id) {
    //altera binario na posicao do id
    //procura uma posição específica e altera os dados desse campo
    string nome, cidade, esporte, evento, noc;
    info aux;
    fstream arquivobi("csv_em_binario.dat", ios::binary | ios::in | ios::out);
    arquivobi.seekp(id * sizeof(aux));
    aux.id = id;
    cout << "Digite o novo nome(maximo 108 caracteres): ";
    getline(cin >> ws, nome);
    strcpy(aux.nome, (nome.substr(0, TAM_NOME - 1)).c_str());
    cout << "Digite a nova cidade(maximo 22 caracteres): ";
    getline(cin >> ws, cidade);
    strcpy(aux.cidade, (cidade.substr(0, TAM_CIDADE - 1)).c_str());
    cout << "Digite o novo esporte(maximo 25 caracteres): ";
    getline(cin >> ws, esporte);
    strcpy(aux.esporte, (esporte.substr(0, TAM_ESPORTE - 1)).c_str());
    cout << "Digite o novo evento(maximo 87 caracteres): ";
    getline(cin >> ws, evento);
    strcpy(aux.evento, (evento.substr(0, TAM_EVENTO - 1)).c_str());
    cout << "Digite o novo noc(maximo 3 caracteres): ";
    getline(cin >> ws, noc);
    strcpy(aux.noc, (noc.substr(0, TAM_NOC - 1)).c_str());
    arquivobi.write((char*)&aux, sizeof(aux));
    arquivobi.close();
}

void operacoes::trocar(long pos1, long pos2) {
    //troca binario na posicao do id
    //utiliza dois registros aux. pra realizar a troca entre as posições inseridas
    info aux;
    info aux2;
    fstream arquivobi("csv_em_binario.dat", ios::binary | ios::in | ios::out);

    arquivobi.seekg(pos1 * sizeof(aux));
    arquivobi.read((char*)&aux, sizeof(aux));
    arquivobi.seekp(pos2 * sizeof(aux));
    arquivobi.read((char*)&aux2, sizeof(aux2));
    arquivobi.seekp(pos1 * sizeof(aux));
    arquivobi.write((char*)&aux2, sizeof(aux2));
    arquivobi.seekp(pos2 * sizeof(aux));
    arquivobi.write((char*)&aux, sizeof(aux));
    arquivobi.close();
}

void operacoes::inserir(long pos) {
    //insere binario na posicao do id
    //copia os dados do arquivo csv_em_binario.dat para o arquivo binarioTemp.dat ate a posicao pos

    info aux;
    info aux2;
    fstream arquivobi("csv_em_binario.dat", ios::binary | ios::in | ios::out);
    fstream arquivobinarioTemp;
    arquivobinarioTemp.open("binarioTemp.dat", ios::binary | ios::out);
    long posicao = 0;
    while (posicao < (pos * sizeof(aux))) {
        arquivobi.seekg(posicao);
        arquivobi.read((char*)&aux, sizeof(aux));
        arquivobinarioTemp.write((char*)&aux, sizeof(aux));
        posicao += sizeof(aux);
    }
    //insercao do novo elemento
    string nome, cidade, esporte, evento, noc;
    cout << "Digite o novo ID: ";
    cin >> aux.id;
    cout << "Digite o novo nome(maximo 108 caracteres): ";
    getline(cin >> ws, nome);
    strcpy(aux.nome, (nome.substr(0, TAM_NOME - 1)).c_str());
    cout << "Digite a nova cidade(maximo 22 caracteres): ";
    getline(cin >> ws, cidade);
    strcpy(aux.cidade, (cidade.substr(0, TAM_CIDADE - 1)).c_str());
    cout << "Digite o novo esporte(maximo 25 caracteres): ";
    getline(cin >> ws, esporte);
    strcpy(aux.esporte, (esporte.substr(0, TAM_ESPORTE - 1)).c_str());
    cout << "Digite o novo evento(maximo 87 caracteres): ";
    getline(cin >> ws, evento);
    strcpy(aux.evento, (evento.substr(0, TAM_EVENTO - 1)).c_str());
    cout << "Digite o novo noc(maximo 3 caracteres): ";
    getline(cin >> ws, noc);
    strcpy(aux.noc, (noc.substr(0, TAM_NOC - 1)).c_str());
    arquivobinarioTemp.seekp(pos * sizeof(aux));
    arquivobinarioTemp.write((char*)&aux, sizeof(aux));

    //copia o resto do arquivo csv_em_binario.dat para o arquivo binarioTemp.dat
    arquivobinarioTemp.seekp((pos + 1) * sizeof(aux));

    while (!arquivobi.eof()) {
        arquivobi.read((char*)&aux, sizeof(aux));
        arquivobinarioTemp.write((char*)&aux, sizeof(aux));
    }

    //copia o arquivo binarioTemp.dat para o arquivo csv_em_binario.dat
    arquivobinarioTemp.seekg(0);
    arquivobi.seekp(0);
    int cont = 0;
    while (!arquivobinarioTemp.eof()) {
        arquivobinarioTemp.read((char*)&aux, sizeof(aux));
        arquivobi.write((char*)&aux, sizeof(aux));
        cout << cont << endl;
        cont++;
    }
}
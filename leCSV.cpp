#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "leCSV.h"
#include "estrutura.h"

using namespace std;

leCSV::leCSV() {
    info aux;
    ifstream arquivocsv("data_athlete_event.csv");
    ofstream arquivoBin("csv_em_binario.dat", ios::binary);
    try {
        if (!arquivoBin.is_open() or !arquivocsv.is_open()) {
            throw invalid_argument("Erro ao converter arquivo csv para binario! Verifique se todos arquivos necessarios encontram-se na pasta.");
        } else {
            string linha, dadoCampo;
            getline(arquivocsv, linha); // le primeira linha
            int posicaoDoDelimitador = 0;
            while (getline(arquivocsv, linha)) {
                //obter primeiro  campo csv
                posicaoDoDelimitador = linha.find(",");
                dadoCampo = linha.substr(0, posicaoDoDelimitador);
                linha.erase(0, posicaoDoDelimitador + 1);
                aux.id = stoi(dadoCampo);

                //obter segundo campo
                if (linha[0] == '\"') {
                    posicaoDoDelimitador = linha.find("\",");
                    dadoCampo = linha.substr(0, posicaoDoDelimitador + 1);
                    linha.erase(0, posicaoDoDelimitador + 2);
                    strcpy(aux.nome, dadoCampo.c_str());
                    //cout << aux.nome << " - ";
                } else {
                    posicaoDoDelimitador = linha.find(",");
                    dadoCampo = linha.substr(0, posicaoDoDelimitador);
                    linha.erase(0, posicaoDoDelimitador + 1);
                    strcpy(aux.nome, dadoCampo.c_str());
                    //cout << aux.nome << " - ";
                }


                //obter terceiro campo
                posicaoDoDelimitador = linha.find(",");
                dadoCampo = linha.substr(0, posicaoDoDelimitador);
                linha.erase(0, posicaoDoDelimitador + 1);
                strcpy(aux.cidade, dadoCampo.c_str());
                //cout << aux.cidade << " - ";


                //obter quarto campo
                posicaoDoDelimitador = linha.find(",");
                dadoCampo = linha.substr(0, posicaoDoDelimitador);
                linha.erase(0, posicaoDoDelimitador + 1);
                strcpy(aux.esporte, dadoCampo.c_str());
                //cout << aux.esporte << " - ";

                //obter quinto campo
                if (linha[0] == '\"') {
                    posicaoDoDelimitador = linha.find("\",");
                    dadoCampo = linha.substr(0, posicaoDoDelimitador + 1);
                    linha.erase(0, posicaoDoDelimitador + 2);
                    strcpy(aux.evento, dadoCampo.c_str());
                    //cout << aux.evento << " - ";
                } else {
                    posicaoDoDelimitador = linha.find(",");
                    dadoCampo = linha.substr(0, posicaoDoDelimitador);
                    linha.erase(0, posicaoDoDelimitador + 1);
                    strcpy(aux.evento, dadoCampo.c_str());
                    //cout << aux.evento << " - ";
                }

                //obter sexto campo
                posicaoDoDelimitador = linha.find(",");
                dadoCampo = linha.substr(0, posicaoDoDelimitador);
                linha.erase(0, posicaoDoDelimitador + 1);
                strcpy(aux.noc, dadoCampo.c_str());
                //cout << aux.noc << endl;
                arquivoBin.write((char*)&aux, sizeof(aux));
            }
            cout << "conversao concluida com exito!" << endl;
        }
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
        abort();
    }

    arquivoBin.close();
    arquivocsv.close();

}
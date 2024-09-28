#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct Campos {
    long id;
    string name;
    string city;
    string sport;
    string event;
    string noc;
};

int confereOMaiorDadoNoCampo(int& campo, int tamanho) {
    if (tamanho > campo) {
        campo = tamanho;
    }
}

int main() {
    ifstream arquivocsv("data_athlete_event.csv");
    ofstream arquivobi("csv_em_binario.dat", ios::binary);
    ofstream arquivotxt("data_athlete_event.txt");
    int maiorDadoId, maiorDadoName, maiorDadoCity, maiorDadoSport, maiorDadoEvent, maiorDadoNoc;
    maiorDadoId = maiorDadoName = maiorDadoCity = maiorDadoSport = maiorDadoEvent = maiorDadoNoc = 0;
    Campos auxiliar;
    string dadoCampo;
    int posicaoDoDelimitador = 0;
    string campo;
    getline(arquivocsv, campo); // le primeira linha
    int contador = 0;
    while (getline(arquivocsv, campo)) {
        //obter primeiro  campo csv
        posicaoDoDelimitador = campo.find(",");
        dadoCampo = campo.substr(0, posicaoDoDelimitador);
        arquivotxt << dadoCampo << "[" << dadoCampo.size() << "]" << " - ";
        campo.erase(0, posicaoDoDelimitador + 1);
        auxiliar.id = stoi(dadoCampo);
        confereOMaiorDadoNoCampo(maiorDadoId, dadoCampo.size());

        //obter segundo campo
        if (campo[0] == '\"') {
            posicaoDoDelimitador = campo.find("\",");
            dadoCampo = campo.substr(0, posicaoDoDelimitador + 1);
            campo.erase(0, posicaoDoDelimitador + 2);
            auxiliar.name = dadoCampo;
            arquivotxt << auxiliar.name << "[" << auxiliar.name.size() << "]" << " - ";
        } else {
            posicaoDoDelimitador = campo.find(",");
            dadoCampo = campo.substr(0, posicaoDoDelimitador);
            campo.erase(0, posicaoDoDelimitador + 1);
            auxiliar.name = dadoCampo;
            arquivotxt << auxiliar.name << "[" << auxiliar.name.size() << "]" << " - ";
        }
        confereOMaiorDadoNoCampo(maiorDadoName, auxiliar.name.size());
    
        //obter terceiro campo
        posicaoDoDelimitador = campo.find(",");
        dadoCampo = campo.substr(0, posicaoDoDelimitador);
        campo.erase(0, posicaoDoDelimitador + 1);
        auxiliar.city = dadoCampo;
        arquivotxt << auxiliar.city << "[" << auxiliar.city.size() << "]" << " - ";
        confereOMaiorDadoNoCampo(maiorDadoCity, auxiliar.city.size());

        //obter quarto campo
        posicaoDoDelimitador = campo.find(",");
        dadoCampo = campo.substr(0, posicaoDoDelimitador);
        campo.erase(0, posicaoDoDelimitador + 1);
        auxiliar.sport = dadoCampo;
        arquivotxt << auxiliar.sport << "[" << auxiliar.sport.size() << "]" << " - ";
        confereOMaiorDadoNoCampo(maiorDadoSport, auxiliar.sport.size());

        //obter quinto campo
        if (campo[0] == '\"') {
            posicaoDoDelimitador = campo.find("\",");
            dadoCampo = campo.substr(0, posicaoDoDelimitador + 1);
            campo.erase(0, posicaoDoDelimitador + 2);
            auxiliar.event = dadoCampo;
            arquivotxt << auxiliar.event << "[" << auxiliar.event.size() << "]" << " - ";
        } else {
            posicaoDoDelimitador = campo.find(",");
            dadoCampo = campo.substr(0, posicaoDoDelimitador);
            campo.erase(0, posicaoDoDelimitador + 1);
            auxiliar.event = dadoCampo;
            arquivotxt << auxiliar.event << "[" << auxiliar.event.size() << "]" << " - ";
        }
        confereOMaiorDadoNoCampo(maiorDadoEvent, auxiliar.event.size());

        //obter sexto campo
        posicaoDoDelimitador = campo.find(",");
        dadoCampo = campo.substr(0, posicaoDoDelimitador);
        campo.erase(0, posicaoDoDelimitador + 1);
        auxiliar.noc = dadoCampo;
        arquivotxt << auxiliar.noc << "[" << auxiliar.noc.size() << "]" << endl;
        confereOMaiorDadoNoCampo(maiorDadoNoc, dadoCampo.size());

        arquivobi.write((char*)&auxiliar, sizeof(auxiliar));
        cout << contador << endl;
        contador++;
    }
    
    //escreve no arquivo txt o tamanho dos maiores campos
    arquivotxt << endl
    << "maiorDadoId: " << maiorDadoId << endl
    << "maiorDadoName: " << maiorDadoName << endl
    << "maiorDadoCity: " << maiorDadoCity << endl
    << "maiorDadoSport: " << maiorDadoSport << endl
    << "maiorDadoEvent: " << maiorDadoEvent << endl
    << "maiorDadoNoc: " << maiorDadoNoc << endl;

    arquivobi.close();
    arquivocsv.close();
    arquivotxt.close();

    cout << "Fim" << endl;
    return 0;

}
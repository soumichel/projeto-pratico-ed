#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "leCSV.h"
#include "estrutura.h"
#include "operacoes.h"

using namespace std;

int main() {
    ifstream testa;
    testa.open("csv_em_binario.dat");
    if (testa) {
        cout << "O arquivo binario ja existe convertido neste diretorio." << endl;
    } else {
        cout << "Convertendo arquivo CSV para binario..." << endl;
        leCSV arqCSV;
    }
    //assim que declarado faz toda a operação de converter o csv para binário
    operacoes op;
    //arrumar que so pode ser convertido uma vez
    int opcao;
    cout << "O que deseja fazer?: " << endl
        << "1 - Adicionar um elemento no arquivo binario em uma posicao especifica " << endl
        << "2 - Visualizar os registros entre a posicao x e y." << endl
        << "3 - Alterar os dados de um registro em uma posicao especifica." << endl
        << "4 - Trocar dois registros de posicao no arquivo." << endl
        << "5 - Imprimir todos os registros do arquivo binario, na ordem em que estao armazenados." << endl
        << "6 - SAIR" << endl;
    do {
        cin >> opcao;
        cout << "Voce escolheu ";
        switch (opcao) {
        case 1:
            cout << "adicionar um elemento no arquivo binario em uma posicao especifica " << endl;
            cout << "Digite a posicao que deseja inserir o elemento: ";
            long pos;
            cin >> pos;
            op.inserir(pos);
            break;
        case 2:
            cout << "visualizar os registros entre a posicao x e y." << endl;
            cout << "Digite a posicao inicial do intervalo que deseja visualizar: ";
            int posIni;
            cin >> posIni;
            cout << "Agora a posicao final: ";
            int posFim;
            cin >> posFim;
            op.exibir(posIni, posFim, false);
            break;
        case 3:
            cout << "alterar os dados de um registro em uma posicao especifica." << endl;
            cout << "Digite o ID do registro que deseja alterar: ";
            long id;
            cin >> id;
            op.alterar(id);
            break;
        case 4:
            cout << "trocar dois registros de posicao no arquivo." << endl;
            cout << "Digite a posicao do primeiro registro: ";
            int pos1;
            cin >> pos1;
            cout << "Agora a posicao do segundo registro: ";
            int pos2;
            cin >> pos2;
            op.trocar(pos1, pos2);
            break;
        case 5:
            cout << "imprimir todos os registros do arquivo binario, na ordem em que estao armazenados." << endl;
            op.exibir(0, 0, true);
            break;
        case 6:
            cout << "sair" << endl;
            break;
        default:
            cout << "uma opcao invalida" << endl;
            break;
        }
        if (opcao != 6) {
            cout << "O que deseja fazer?: " << endl
                << "1 - Adicionar um elemento no arquivo binario em uma posicao especifica " << endl
                << "2 - Visualizar os registros entre a posicao x e y." << endl
                << "3 - Alterar os dados de um registro em uma posicao especifica." << endl
                << "4 - Trocar dois registros de posicao no arquivo." << endl
                << "5 - Imprimir todos os registros do arquivo binario, na ordem em que estao armazenados." << endl
                << "6 - SAIR" << endl;
        }
    } while (opcao != 6);
    return 0;
}
#include "iostream"
#include "funciones.h"
using namespace std;

partida(){
cout << "-----Lista simbolos-----" << endl 
         << "Cristal comun = ◊" << endl 
         << "Cristal azul  = ◈" << endl
         << "DEA = [D]" << endl 
         << "Pollos Hermanos = <°)" << endl
         << "------------------------" << endl;

    int ww[3] = {0,0,0}; // litros , plata_dia , plata_banco

    for (int dia = 1; dia <= 6; dia++)
    {
        int dados[3] = {};

        cout << "Dia " << dia << endl;

        lanzarDados(dados);

        cout << "Valores de los dados : " << simbolo_dado(dados[0]) << " " << simbolo_dado(dados[1]) << " " << simbolo_dado(dados[2]) << endl;
    

    };
}

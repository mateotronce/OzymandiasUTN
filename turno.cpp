#include <iostream>
#include "funciones.h"
using namespace std;

void turno(Jugador &j, EstadoDia &dia)
{

    int dados[3] = {};

    lanzarDados(dados);

    cout << "Valores de los dados : " ;
    for (int dado : dados) {
        cout << simbolo_dado(dado) << " ";

        modificadorJugador(j, dia ,dado);
    }
    cout << "\n" << endl;
}


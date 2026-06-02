#include <iostream>
#include "funciones.h"
using namespace std;

void turno(Jugador &j, EstadoDia &dia)
{

    int dados[3] = {};

    srand(time(nullptr));

    for (int i = 0; i < 3 ; i++  ) {
        dados[i] = lanzarDados();
    }
    
    cout << "Valores de los dados : " ;
    for (int dado : dados) {
        cout << simbolo_dado(dado) << " ";

        modificadorJugador(j, dia ,dado);
    }
    cout << "\n" << endl;
}


#include <iostream>
#include "funciones.h"
using namespace std;

void turno(Jugador &j, EstadoDia &dia)
{

    int dados[3] = {};
    int acu_dado_azul = 0;


    for (int i = 0; i < 3 ; i++  ) {
        dados[i] = lanzarDados();
        //99.1 HITO busco la tirada perfecta con el bool
        if(dados[i] == 4){
            acu_dado_azul++;
        }
    }

    if(acu_dado_azul == 3){
            j.tirada_perfecta = true;
        }
    //dados[0] = 1; dados[1] = 2; dados[2] = 3;
    cout << "LANZAMIENTO #" << j.contLanzamientos << endl;
    dibujarDados(dados);

    for (int i = 0; i < 3; i++) {
        modificadorJugador(j, dia, dados[i]);
    }
}


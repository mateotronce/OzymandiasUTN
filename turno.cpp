#include <iostream>
#include "funciones.h"
using namespace std;

void turno(Jugador &j, EstadoDia &dia)
{

    int dados[3] = {};
    int acu_dado_azul = 0;

    for (int i = 0; i < 3 ; i++)
    {
        dados[i] = lanzarDados();
        //99.1 HITO busco la tirada perfecta con el bool
        if(dados[i] == 4)
        {
            acu_dado_azul++;
        }
    }

    if(acu_dado_azul == 3)
    {
        j.tirada_perfecta = true;
    }

    cout << "LANZAMIENTO #" << j.contLanzamientos << endl;
    dibujarDados(dados);

    for (int i = 0; i < 3; i++)
    {
        modificadorJugador(j, dia, dados[i]);
    }
}

void probarDados(Jugador &j, EstadoDia &dia, int d1, int d2, int d3)
{

    int dados[3] = {d1, d2, d3};
    int acu_dado_azul = 0;

    for (int i = 0; i < 3 ; i++)
    {
        //99.1 HITO busco la tirada perfecta con el bool
        if(dados[i] == 4)
        {
            acu_dado_azul++;
        }
    }

    if(acu_dado_azul == 3)
    {
        j.tirada_perfecta = true;
    }

    cout << "LANZAMIENTO #" << j.contLanzamientos << endl;
    dibujarDados(dados);

    for (int i = 0; i < 3; i++)
    {
        modificadorJugador(j, dia, dados[i]);
    }
}

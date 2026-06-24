#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>

using namespace std;

void menuFinal(Jugador &j2, Jugador &j1, Puntaje puntajes[5]){

    limpiarPantalla();

    float tirada_perfectaj2 = 0, tirada_perfectaj1 = 0;

    //Calculo hito car wash
    if(j2.plata_turno_max > j1.plata_turno_max)
    {
        j2.plata_turno_max = 50000;
        j1.plata_turno_max = 0;
    }
    else if(j2.plata_turno_max < j1.plata_turno_max)
    {
        j2.plata_turno_max = 0;
        j1.plata_turno_max = 50000;
    }
    else if(j2.plata_turno_max > 0)
    {
        j2.plata_turno_max = 50000;
        j1.plata_turno_max = 50000;
    }
    else
    {
        j2.plata_turno_max = 0;
        j1.plata_turno_max = 0;
    }

    //Calculo hito favor de gus
    if(j2.favor_gus_total > j1.favor_gus_total)
    {
        j2.favor_gus_total = 50000;
        j1.favor_gus_total = 0;
    }
    else if(j2.favor_gus_total < j1.favor_gus_total)
    {
        j2.favor_gus_total = 0;
        j1.favor_gus_total = 50000;
    }
    else if(j2.favor_gus_total == j1.favor_gus_total && (j2.favor_gus_total != 0 || j1.favor_gus_total != 0))
    {
        j2.favor_gus_total = 50000;
        j1.favor_gus_total = 50000;
    }
    else
    {
        j2.favor_gus_total = 0;
        j1.favor_gus_total = 0;
    }

    //Calculo hito plantarse Say my name
    if(j2.cant_dia_plantado > j1.cant_dia_plantado)
    {
        j2.cant_dia_plantado = 30000;
        j1.cant_dia_plantado = 0;
    }
    else if(j2.cant_dia_plantado < j1.cant_dia_plantado)
    {
        j2.cant_dia_plantado = 0;
        j1.cant_dia_plantado = 30000;
    }
    else if(j2.cant_dia_plantado > 0)
    {
        j2.cant_dia_plantado = 30000;
        j1.cant_dia_plantado = 30000;
    }
    else
    {
        j2.cant_dia_plantado = 0;
        j1.cant_dia_plantado = 0;
    }


    //Calculo hito tirada perfecta
    if(j2.tirada_perfecta){
        tirada_perfectaj2 = 50000;
    }
    if(j1.tirada_perfecta){
        tirada_perfectaj1 = 50000;
    }

    //Calculo hito it's all good man
    if(j2.cant_allanado > j1.cant_allanado)
    {
        j2.cant_allanado = 25000;
        j1.cant_allanado = 0;
    }
    else if(j2.cant_allanado < j1.cant_allanado)
    {
        j2.cant_allanado = 0;
        j1.cant_allanado = 25000;
    }
    else if(j2.cant_allanado == j1.cant_allanado && (j2.cant_allanado != 0 || j1.cant_allanado != 0))
    {
        j2.cant_allanado = 25000;
        j1.cant_allanado = 25000;
    }
    else
    {
        j2.cant_allanado = 0;
        j1.cant_allanado = 0;
    }


    //Calculo plata final y ganador
    j2.plata_final_banco = j2.plata_banco + j2.plata_turno_max + j2.favor_gus_total + j2.cant_dia_plantado + tirada_perfectaj2 + j2.cant_allanado;
    j1.plata_final_banco = j1.plata_banco + j1.plata_turno_max + j1.favor_gus_total + j1.cant_dia_plantado + tirada_perfectaj1 + j1.cant_allanado;

    string ganador;

    //Busqueda del ganador para agregar al ranking
    if (j1.plata_final_banco > j2.plata_final_banco) {
        // Si el Jugador 1 fue el ganador
        ganador = j1.nombre;
        evaluarYAgregarAlRanking(puntajes, j1.nombre, j1.plata_final_banco);
    }
    else if (j2.plata_final_banco > j1.plata_final_banco) {
        // Si el Jugador 2 fue el ganador
        ganador = j2.nombre;
        evaluarYAgregarAlRanking(puntajes, j2.nombre, j2.plata_final_banco);
    }
    else {
        // En caso de un empate, desempatamos por los kilos de cristal azul
        if (j1.kilos_azul_total > j2.kilos_azul_total) {
            ganador = j1.nombre;
            evaluarYAgregarAlRanking(puntajes, j1.nombre, j1.plata_final_banco);
        }
        else if (j2.kilos_azul_total > j1.kilos_azul_total) {
            ganador = j2.nombre;
            evaluarYAgregarAlRanking(puntajes, j2.nombre, j2.plata_final_banco);
        }
        else
        {
            ganador = "Empataron, Gus Fring los considera químicos excepcionales por igual y ambos comparten el control del superlaboratorio.";
            evaluarYAgregarAlRanking(puntajes, j1.nombre, j1.plata_final_banco);
            evaluarYAgregarAlRanking(puntajes, j2.nombre, j2.plata_final_banco);
        }
    }

    //Display de menu final

    cout << "HITO                  " << j2.nombre             << "             " << j1.nombre << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Dinero                $" << j2.plata_banco       << "        $"     << j1.plata_banco << endl;
    cout << "A1A Car Wash          $" << j2.plata_turno_max   << "        $"     << j1.plata_turno_max << endl;
    cout << "Negocio del imperio   $" << j2.favor_gus_total   << "        $"     << j1.favor_gus_total << endl;
    cout << "Say My Name           $" << j2.cant_dia_plantado << "        $"     << j1.cant_dia_plantado << endl;
    cout << "99.1%                 $" << tirada_perfectaj2    << "        $"     << tirada_perfectaj1 << endl;
    cout << "It´s All Good Man     $" << j2.cant_allanado     << "        $"     << j1.cant_allanado << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "TOTAL                 $" << j2.plata_final_banco << "        $"     << j1.plata_final_banco << endl << endl;
    cout << "GANADOR: "               << ganador             << endl            << endl;

    pausar();

}

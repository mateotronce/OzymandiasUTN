#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>

using namespace std;

void menuFinal(Jugador &g, Jugador &w){

    system("cls");

    float tirada_perfectag = 0, tirada_perfectaw = 0;

    //Calculo hito car wash
    if(g.plata_turno_max > w.plata_turno_max){
        g.plata_turno_max = 50000;
        w.plata_turno_max = 0;
    }else if(g.plata_turno_max < w.plata_turno_max){
        g.plata_turno_max = 0;
        w.plata_turno_max = 50000;
    }else if(g.plata_turno_max == w.plata_turno_max){
        g.plata_turno_max = 50000;
        w.plata_turno_max = 50000;
    }

    //Calculo hito favor de gus
    if(g.favor_gus_total > w.favor_gus_total){
        g.favor_gus_total = 50000;
        w.favor_gus_total = 0;
    }else if(g.favor_gus_total < w.favor_gus_total){
        g.favor_gus_total = 0;
        w.favor_gus_total = 50000;
    }else if(g.favor_gus_total == w.favor_gus_total && (g.favor_gus_total != 0 || w.favor_gus_total != 0)){
        g.favor_gus_total = 50000;
        w.favor_gus_total = 50000;
    }else{
        g.favor_gus_total = 0;
        w.favor_gus_total = 0;
    }

    //Calculo hito plantarse
    if(g.cant_dia_plantado > w.cant_dia_plantado){
        g.cant_dia_plantado = 30000;
        w.cant_dia_plantado = 0;
    }else if(g.favor_gus_total < w.favor_gus_total){
        g.cant_dia_plantado = 0;
        w.cant_dia_plantado = 30000;
    }else if(g.favor_gus_total == w.favor_gus_total){
        g.cant_dia_plantado = 30000;
        w.cant_dia_plantado = 30000;
    }



    //Calculo hito tirada perfecta
    if(g.tirada_perfecta){
        tirada_perfectag = 50000;
    }
    if(w.tirada_perfecta){
        tirada_perfectaw = 50000;
    }

    //Calculo hito all good man
    if(g.cant_allanado > w.cant_allanado){
        g.cant_allanado = 25000;
        w.cant_allanado = 0;
    }else if(g.cant_allanado < w.cant_allanado){
        g.cant_allanado = 0;
        w.cant_allanado = 25000;
    }else if(g.cant_allanado == w.cant_allanado){
        g.cant_allanado = 25000;
        w.cant_allanado = 25000;
    }

    //Calculo plata final y ganador
    g.plata_final_banco = g.plata_banco + g.plata_turno_max + g.favor_gus_total + g.cant_dia_plantado + tirada_perfectag + g.cant_allanado;
    w.plata_final_banco = w.plata_banco + w.plata_turno_max + w.favor_gus_total + w.cant_dia_plantado + tirada_perfectaw + w.cant_allanado;

    string ganador;
    if(g.plata_final_banco > w.plata_final_banco){
        ganador = g.nombre;
    }else if(g.plata_final_banco < w.plata_final_banco){
        ganador = w.nombre;
    }else if(g.plata_final_banco == w.plata_final_banco){
        if(w.kilos_azul_total > g.kilos_azul_total){
            ganador = w.nombre;
        }else if(w.kilos_azul_total < g.kilos_azul_total){
            ganador = g.nombre;
        }else{
            ganador = "Empataron, Gus Fring los considera químicos excepcionales por igual y ambos comparten el control del superlaboratorio. ";
        }
    }



    //Display de menu final

    cout << "HITO                  " << g.nombre             << "             " << w.nombre << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Dinero                $" << g.plata_banco       << "        $"     << w.plata_banco << endl;
    cout << "A1A Car Wash          $" << g.plata_turno_max   << "        $"     << w.plata_turno_max << endl;
    cout << "Negocio del imperio   $" << g.favor_gus_total   << "        $"     << w.favor_gus_total << endl;
    cout << "Say My Name           $" << g.cant_dia_plantado << "        $"     << w.cant_dia_plantado << endl;
    cout << "99.1%                 $" << tirada_perfectag    << "        $"     << tirada_perfectaw << endl;
    cout << "It´s All Good Man     $" << g.cant_allanado     << "        $"     << w.cant_allanado << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "TOTAL                 $" << g.plata_final_banco << "        $"     << w.plata_final_banco << endl << endl;
    cout << "GANADOR: "               << ganador             << endl            << endl;

    system("pause");


}

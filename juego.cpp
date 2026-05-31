#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>

using namespace std;





void juego() {
    srand(time(nullptr));

    cout << "-----Lista simbolos-----" << endl
         << "Cristal comun = ◊" << endl
         << "Cristal azul  = ◈" << endl
         << "DEA = [D]" << endl
         << "Pollos Hermanos = <°)" << endl
         << "------------------------\n" << endl;

    EstadoDia dia = {};
    Jugador w = {0, 0, 0, 0, 0};
    Jugador g = {0, 0, 0, 0, 0};

    pedirNombres(w, g);

    bool continua;
    bool primer_pasada;
    bool victoria = false;

    for (int i = 1; i <= 6 && !victoria; i++) {

//        mod_carta(dia);
        cout.flush(); // Flush the output stream
        system("clear"); // Clear the console with the "system" function

        // Turno jugador 1
        continua = true;
        primer_pasada = true;
        reset_turno(w, dia);
        while (continua) {
            condicionesJuego(w, dia, continua, primer_pasada, i);
        }

        cout << "\nPresiona Enter para el turno de " << g.nombre << "..." << endl;
        cin.get();

        cout.flush(); 
        system("clear"); 

        // Turno jugador 2
        continua = true;
        primer_pasada = true;
        reset_turno(g, dia);
        while (continua) {
            condicionesJuego(g, dia, continua, primer_pasada, i);
        }

        // Victoria inmediata: se verifica al terminar el dia completo
        if (w.plata_banco >= 737000 || g.plata_banco >= 737000) {
            victoria = true;
            cout << "\n!Victoria inmediata! Un jugador alcanzo $737.000.\n" << endl;
        }

        if (!victoria) {
            cout.flush(); 
            system("clear"); 
            cout << "------------------------" << endl;
            cout << "Estadisticas del turno para el dia " << i << endl; 
            cout << "------------------------" << endl;

            mostrar_estadisticas(w);
            cout << "\n" << endl;
            mostrar_estadisticas(g);
        }

        if (!victoria && i < 6) {
            cout << "\nPresiona Enter para continuar al dia " << i + 1 << "..." << endl;
            cin.get();
        }
        
    }
}

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia) {

    if (primer_pasada) {
        cout << "\n --------------------------------------- \n" << endl;
        cout << "Turno de " << j.nombre << " - Dia: " << num_dia << endl;
        cout << "\n --------------------------------------- \n" << endl;

        cout << "Presiona enter para tirar los dados:" << endl;
        cin.get();
        primer_pasada = false;
    }
    else if (j.dea >= dia.dea_limite) {
        cout << "\n Escuchas sirenas desde lejos que se acercan... . Presiona enter para continuar" << endl;
        cin.get();
        cout << "\nFin: La DEA te encontro, perdes todo lo del turno.\n" << endl;
        j.plata_turno = 0;
        j.kilos_turno = 0;
        continua = false;
    }
    else if (j.kilos_turno < dia.kilos_minimos && j.litros_turno >= 3) {
        cout << "No te podes plantar, presiona enter para tirar los dados:" << endl;
        cin.get();
    }
    else if (j.litros_turno < 3) {
        cout << "\nTe quedaste sin material, el laboratorio se apaga y escuchas pasos desde lejos. presiona enter para conrinuar" << endl; 
        cin.get();
        if (j.kilos_turno < dia.kilos_minimos) {
            cout << "\nEntra Gus y ve que no lograste la cuota. Perdes todo lo de hoy.\n" << endl;
            continua = false;
        }
        else {
            cout << "\nEntra y Gus ve que lograste la cuota. Se transfiere la plata al banco.\n" << endl;
            j.plata_banco += j.plata_turno;
            j.plata_turno = 0;
            continua = false;
        }
    }
    else {
        int valor;
        cout << "Tenes 2 opciones:" << endl;
        cout << "1) Seguir" << endl << "2) Parar\n" << endl;
        cin >> valor;
        cin.ignore();
        if (valor == 2) {
            continua = false;
            cout << "Finalizas el turno, se suma a tu banco: $" << j.plata_turno << "\n" << endl;
            j.plata_banco += j.plata_turno;
            j.plata_turno = 0;
        }
    }

    if (continua) {
        turno(j, dia);
        mostrarEstadisticasSimples(j);
    }
    
}


void reset_turno(Jugador &j, EstadoDia &dia) {
    j.kilos_turno = 0;
    j.litros_turno = dia.litros_metalamina;
    j.plata_turno = 0;
    j.dea = 0;
    j.pollos_hermanos = 0;
}


void mostrar_estadisticas(Jugador &w) {
    cout << "\nInformacion del turno de " << w.nombre << ":" << endl;
    cout << "Litros disponibles: " << w.litros_turno << endl;
    cout << "Plata generada:     $" << w.plata_turno << endl;
    cout << "Kilos acumulados:   " << w.kilos_turno << endl;
    cout << "Plata en banco:     $" << w.plata_banco << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/ 3" << endl;
    cout << "Favor de Gus:       " << w.pollos_hermanos << "/ 3" << endl;
}

void mostrarEstadisticasSimples(Jugador &w) {
    cout << "Te quedan disponibles : " << w.litros_turno << " litros" << endl;
    cout << "Acumulaste:   " << w.kilos_turno << " Kilos" << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/ 3" << endl;
    cout << "Favor de Gus:       " << w.pollos_hermanos << "/ 3" << endl;
}

void pedirNombres(Jugador &j1, Jugador &j2) {
    char confirmacion;
    do {
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << "¿Nombre del jugador 1? ";
        cin >> j1.nombre;
        cout << "¿Nombre del jugador 2? ";
        cin >> j2.nombre;
        cout << "¿Confirmar nombres? (S/N) ";
        cin >> confirmacion;
        cin.ignore();
    } while (confirmacion != 'S' && confirmacion != 's');
}

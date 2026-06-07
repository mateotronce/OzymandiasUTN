#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>

using namespace std;





void juego() {


    Jugador w = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Jugador g = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    pedirNombres(w, g);

    bool continua;
    bool primer_pasada;
    bool victoria = false;

    for (int i = 1; i <= 6 && !victoria; i++) {
        EstadoDia dia = {};
        cout.flush();
        system("clear"); 


        mod_cartas(dia);

        // Turno jugador 1
        continua = true;
        primer_pasada = true;
        reset_turno(w, dia);
        mostrarEstadisticasSimples(w,dia);
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
        mostrarEstadisticasSimples(g,dia);
        while (continua) {
            condicionesJuego(g, dia, continua, primer_pasada, i);
        }

        // Victoria inmediata: se verifica al terminar el dia completo
        if (w.plata_banco >= 737000 || g.plata_banco >= 737000) {
            victoria = true;
            menuFinal(g,w);
        }

        if (dia.danger_activo) {
            cout << "Hoy uno de los 2 tiene que pagar (50k o lo que haya en el banco menor a ese monto)" << endl;

            if (w.plata_turno > g.plata_turno) {
                cout << "Perdiste : " << g.nombre << endl;
                if (g.plata_banco > 50000) {
                    g.plata_banco -= 50000;
                    w.plata_banco += 50000;
                }
                else {
                    w.plata_banco += g.plata_banco;
                    g.plata_banco = 0;
                }
            }
            else {
                cout << "Perdiste : " << w.nombre << endl;
                if (w.plata_banco > 50000) {
                    w.plata_banco -= 50000;
                    g.plata_banco += 50000;
                }
                else {
                    g.plata_banco += g.plata_banco;
                    w.plata_banco = 0;
                }
            }

        }


        if (!victoria) {

            cout << "\n------------------------" << endl;
            cout << "Estadisticas del turno para el dia " << i << endl; 
            cout << "------------------------" << endl;

            mostrar_estadisticas(w,dia);
            cout << "\n" << endl;
            mostrar_estadisticas(g,dia);
        }

        if (!victoria && i < 6) {
            cout << "\nPresiona Enter para continuar al dia " << i + 1 << "..." << endl;
            cin.get();
        }else if(i == 6){
                menuFinal(g,w);
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
        if (dia.saul_activo) {
            cout << "\nLa DEA te encontro... pero tu abogado Saul goodman estaba atento, la dea te saca todo lo ganado en el turno, pero por un tecnisismo legal ganas un bono de 50k que va a tu banco. Suertudo...\n" << endl;
            j.plata_banco += 50000;
        }
        else {
        cin.get();
        cout << "\nFin: La DEA te encontro, perdes todo lo del turno.\n" << endl;
        j.plata_turno = 0;
        j.kilos_turno = 0;
        j.cant_allanado += 1;
        continua = false;
        }
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
            j.cant_dia_plantado += 1;
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
            j.cant_dia_plantado +=1;
        }
    }

    if (continua) {
        turno(j, dia);
        mostrarEstadisticasSimples(j,dia);
    }
    // A1A CAR WASH HITO busco mayor ganancia de dinero en un solo dia
    if(j.plata_turno > j.plata_turno_max){
        j.plata_turno_max = j.plata_turno;
    }
    
}


void reset_turno(Jugador &j, EstadoDia &dia) {
    j.kilos_turno = 0;
    j.litros_turno = dia.litros_metalamina;
    j.plata_turno = 0;
    j.dea = 0;
    j.pollos_hermanos = 0;
}


void mostrar_estadisticas(Jugador &w, EstadoDia &d) {
    cout << "\nInformacion del turno de " << w.nombre << ":" << endl;
    cout << "Litros disponibles: " << w.litros_turno << endl;
    cout << "Plata generada:     $" << w.plata_turno << endl;
    cout << "Kilos acumulados:   " << w.kilos_turno << endl;
    cout << "Plata en banco:     $" << w.plata_banco << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/" << d.dea_limite << endl;
    cout << "Favor de Gus:       " << w.pollos_hermanos << "/ 3" << endl;
}

void mostrarEstadisticasSimples(Jugador &w, EstadoDia &d) {
    cout << "Te quedan disponibles : " << w.litros_turno << " litros" << endl;
    cout << "Acumulaste:   " << w.kilos_turno << " Kilos" << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/" << d.dea_limite << endl;
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

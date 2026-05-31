#include "funciones.h"
#include<iostream>
#include <cstdlib>
#include <string>  
using namespace std;


void lanzarDados(int resultado[3]){
    for (int i = 0; i < 3; i++){
        resultado[i] = (rand() % 6) + 1;
    }
}

string simbolo_dado(int valor){
    string cristal1 = "◊";
    string cristal2 = "◈";
    string pollo = "<°)";
    string dea = "[D]";

    switch (valor)
    {
    case 1:
        return cristal1;
        break;  
    case 2:
        return cristal1;
        break;
    case 3:
        return cristal1;
        break;
    case 4:
        return cristal2;
        break;
    case 5:
        return dea;
        break;
    case 6:
        return pollo;
        break;
    default:
        return "?";
    }
}

void modificadorJugador(Jugador &j , EstadoDia &d ,int dado){

    switch (dado)
    {
    case 4:

        if (j.litros_turno - 5 < 0){
            cout << "No tienes litro soficientes para generar cristal azul, pierdes los litros que te quedaban" << endl;
            j.litros_turno = 0;
        }
        else {
            j.kilos_turno += 2;
            j.litros_turno -= 5;
            j.plata_turno += 50000;
        }
        break;


    case 5:
        j.dea += 1;

        break;
        
    case 6:

        if (j.litros_turno - 2 < 0){
            cout << "No pudiste ganarte el favor de gus.Te quedas sin litros" << endl;
            j.litros_turno = 0;
        }
        else {
            j.litros_turno -= 2;        
            j.pollos_hermanos += 1;
        }

        if (j.pollos_hermanos == 3) {
            j.dea = 0;
            j.plata_turno += 100000;
            j.pollos_hermanos = 0;
            cout << "Ganaste el favor de gus" << endl;
        }

        break;

    default:

        if (j.litros_turno - 3 < 0) {
            cout << "\nNo tenes litros suficientes para crear cristal blanco. Perdes los litros que te quedan" << endl;
            j.litros_turno = 0;
        }
        else {
            j.kilos_turno += 1;
            j.litros_turno -= 3;
            j.plata_turno += 15000;
        }
        break;

    }



}
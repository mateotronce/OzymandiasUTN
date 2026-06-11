#include "funciones.h"
#include<iostream>
#include <cstdlib>
#include <string>  
using namespace std;


int lanzarDados(){
    return (rand() % 6) + 1;
}


string simbolo_dado(int valor){
    string cristal1 = "[CRISTAL COMUN]";
    string cristal2 = "[CRISTAL AZUL]";
    string pollo = "[POLLO]";
    string dea = "[DEA]";

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

        if (j.litros_turno - d.litros_cristal_azul < 0){
            cout << "No tienes litro soficientes para generar cristal azul, pierdes los litros que te quedaban" << endl;
            j.litros_turno = 0;
        }
        else {
            j.kilos_turno += d.kilos_cristal_azul;
            j.litros_turno -= d.litros_cristal_azul;
            j.plata_turno += d.plata_cristal_azul;
            j.kilos_azul_total += d.kilos_cristal_azul;
        }
        break;


    case 5:
        j.dea += 1;

        break;
        
    case 6:

        if (j.litros_turno < 2) {
            cout << "\nNo tenes litros suficientes para guardar el favor de Gus." << endl;
        } else {
            char guardar;
            cout << "\n¿Guardar sello de Pollos Hermanos? (cuesta 2L) (S/N): ";
            cin >> guardar;
            cin.ignore(1000, '\n');
            if (guardar == 'S' || guardar == 's') {
                j.litros_turno -= 2;
                j.pollos_hermanos += 1;
                if (j.pollos_hermanos == 3) {
                    j.dea = 0;
                    j.plata_turno += 100000;
                    j.pollos_hermanos = 0;
                    j.favor_gus_total += 1;
                    cout << "Ganaste el favor de Gus! +$100.000 y DEA reseteada." << endl;
                }
            }
        }

        break;

    default:

        if (j.litros_turno - d.litros_cristal_blanco < 0) {
            cout << "\nNo tenes litros suficientes para crear cristal blanco. Perdes los litros que te quedan" << endl;
            j.litros_turno = 0;
        }
        else {
            j.kilos_turno += d.kilos_cristal_blanco;
            j.litros_turno -= d.litros_cristal_blanco;
            j.plata_turno += d.plata_cristal_blanco;
        }
        break;

    }



}

#include<iostream>
#include "funciones.h"
#include <ctime>
using namespace std;


// Descripcion de todas las cartas que se muestra al comienzo de cada dia.

void carta_la_mosca(){

    cout << "La carta del dia es: La Mosca" << endl << endl;
    cout << "Efecto: El proceso se vuelve ineficiente y torpe. Cada cara de Cristal Azul obtenida durante este dia sufre una penalizacion:"  << endl;
    cout << "su pureza se degrada por completo, otorgando solo 1 Kilo y $10.000 en la Cuenta Temporal (rindiendo exactamente igual que un Cristal Comun),"  << endl;
    cout << "pero su costo de Metilamina se mantiene en 5 Litros." << endl << endl;

}

void carta_mike(){

    cout << "La carta del dia es: Mike Ehrmantraut" << endl << endl;
    cout << "Efecto: Tienes un margen de error mayor con la ley. Durante este dia, el sistema anula por completo el primer simbolo de la DEA obtenido en cada turno." << endl;
    cout << "Esto significa que la redada de Hank no se activara al acumular 3 placas, sino que necesitarás recibir 4 simbolos de la DEA en el mismo turno para perder tu producción. "<< endl << endl;

}

void carta_ding(){

    cout << "La carta del dia es: Ding" << endl << endl;
    cout << "Efecto: La presión en la calle se duplica. Durante este día, la cuota mínima de producción requerida "<< endl;
    cout << "para desbloquear el botón de Plantarse sube de 4 a 8 Kilos en total."  << endl << endl;

}

void carta_science(){

    cout << "La carta del dia es: ¡Science, Bitch!" << endl << endl;
    cout << "Efecto: El laboratorio opera a máxima capacidad. Ambos jugadores inician sus" << endl;
    cout << "respectivos turnos con el tanque de combustible expandido a 28 Litros de Metilamina (en lugar de los 20 habituales)," << endl;
    cout << "dándoles mucho más oxígeno para cocinar lotes enormes." << endl << endl;
}

void carta_saul(){

    cout << "La carta del dia es: Better Call Saul" << endl << endl;
    cout << "Efecto: Si la DEA te atrapa (acumulas las 3 placas de la DEA)," << endl;
    cout << "sigues perdiendo de inmediato la producción y el botín acumulado en tu Cuenta Temporal;" << endl;
    cout << "sin embargo, Saul interviene en la comisaría y encuentra una trampa legal que te salva de la quiebra absoluta," << endl;
    cout << "otorgándote un bono consuelo de $50.000 que va directo a tu Banco Total. " << endl << endl;

}


void carta_danger(){

    cout << "La carta del dia es: " << "I Am The Danger" << endl << endl;
    cout << "Efecto: Ambos químicos juegan sus turnos normalmente intentando maximizar ganancias. Sin embargo, al finalizar el Día," << endl;
    cout << "el sistema compara el dinero que cada uno logró asegurar en su Cuenta Temporal durante esta ronda." << endl;
    cout << "El jugador que haya generado más dinero, le roba $50.000 directo del Banco Total al perdedor." << endl << endl;
}

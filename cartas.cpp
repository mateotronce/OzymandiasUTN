#include<iostream>
#include "funciones.h"


using namespace std;

void mod_cartas(EstadoDia &e) {

    srand(time(nullptr));

    int carta = lanzarDados();

    switch (carta)
    {
    case 1:
        // La mosca
        cout << "La carta del dia es: La Mosca" << endl;
        e.kilos_cristal_azul = 1;
        e.plata_cristal_azul = 10000;
        break;
    
    case 2:
        /* MIke */
        cout << "La carta del dia es: Mike Ehrmantraut" << endl;
        e.dea_limite = 4;
        break;

    case 3:
        /* ding */
        cout << "La carta del dia es: Ding" << endl;

        e.kilos_minimos = 8;
        break;

    case 4:
        /* Science  */
        cout << "La carta del dia es: ¡Science, Bitch!" << endl;

        e.litros_metalamina = 28;
        break;
    
    case 5:
        /* saul */
        cout << "La carta del dia es: Better Call Saul" << endl;

        e.saul_activo = true;
        break;
    
    case 6:
        /* I am the danger */

        cout << "La carta del dia es: " << "I Am The Danger" << endl;

        e.danger_activo = true;
        break;
    

    default:
        break;
    }    


}

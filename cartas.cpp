#include<iostream>
#include "funciones.h"

using namespace std;

void mod_cartas(EstadoDia &e)
{

    int carta = lanzarDados();

    switch (carta)
    {
    case 1:
        // La mosca
        carta_la_mosca();
        e.kilos_cristal_azul = 1;
        e.plata_cristal_azul = 15000;
        break;

    case 2:
        /* MIke */
        carta_mike();
        e.dea_limite = 4;
        break;

    case 3:
        /* ding */
        carta_ding();
        e.kilos_minimos = 8;
        break;

    case 4:
        /* Science  */
        carta_science();
        e.litros_metalamina = 28;
        break;

    case 5:
        /* saul */
        carta_saul();
        e.saul_activo = true;
        break;

    case 6:
        /* I am the danger */
        carta_danger();
        e.danger_activo = true;
        break;

    default:
        break;
    }
}

void probarCarta(EstadoDia &e, int numeroDeCarta)
{

    switch (numeroDeCarta)
    {
    case 1:
        // La mosca
        carta_la_mosca();
        e.kilos_cristal_azul = 1;
        e.plata_cristal_azul = 15000;
        break;

    case 2:
        /* MIke */
        carta_mike();
        e.dea_limite = 4;
        break;

    case 3:
        /* ding */
        carta_ding();
        e.kilos_minimos = 8;
        break;

    case 4:
        /* Science  */
        carta_science();
        e.litros_metalamina = 28;
        break;

    case 5:
        /* saul */
        carta_saul();
        e.saul_activo = true;
        break;

    case 6:
        /* I am the danger */
        carta_danger();
        e.danger_activo = true;
        break;

    default:
        break;
    }
}

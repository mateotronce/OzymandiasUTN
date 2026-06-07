#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>  

using namespace std; 


struct Jugador
{
    float litros_turno;
    float plata_turno;
    float plata_turno_max;
    float plata_banco;
    float plata_final_banco;
    int favor_gus_total;
    int cant_dia_plantado;
    int cant_allanado;
    int dea;
    int kilos_turno;
    int pollos_hermanos;
    int kilos_azul_total;
    bool tirada_perfecta = false;
    string nombre;
};


struct EstadoDia
{
    float litros_metalamina = 20;
    int kilos_minimos = 4;
    int dea_limite = 3;
    int litros_cristal_blanco = 3;
    int kilos_cristal_blanco = 1;
    int plata_cristal_blanco = 15000;
    int litros_cristal_azul = 5;
    int kilos_cristal_azul = 2;
    int plata_cristal_azul = 50000;
    bool la_mosca = false;
    bool mike = false;
    bool ding = false;
    bool science = false;
    bool saul_activo = false;
    bool danger_activo = false;
};



bool salir();

void pedirNombres(Jugador &j1, Jugador &j2);

void creditos();


int lanzarDados();

string simbolo_dado(int valor);

void turno(Jugador &j, EstadoDia &dia);

void reset_turno (Jugador &j, EstadoDia &dia);

void mostrar_estadisticas (Jugador &w, EstadoDia &d) ;

void mostrarEstadisticasSimples (Jugador &w , EstadoDia &d);

void modificadorJugador(Jugador &j , EstadoDia &d ,int dado);

void juego();

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia);

void mod_cartas(EstadoDia &e);

void carta_la_mosca();
void carta_mike();
void carta_ding();
void carta_science();
void carta_saul();
void carta_danger();

void menuFinal(Jugador &g, Jugador &w);

#endif // FUNCIONES_H_INCLUDED

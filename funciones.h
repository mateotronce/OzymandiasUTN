#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>  

using namespace std; 


struct Jugador
{
    float litros_turno;
    float plata_turno;
    float plata_banco;
    int dea;
    int kilos_turno;
    int pollos_hermanos;
    string nombre;
};


struct EstadoDia
{
    float litros_metalamina = 20;
    int kilos_minimos = 4;
    int dea_limite = 3;
    bool cristal_azul_degradado = false;
    bool saul_activo = false;
    bool danger_activo = false;
};



bool salir();

void pedirNombres(Jugador &j1, Jugador &j2);

void creditos();


void lanzarDados(int resultado[3]);

string simbolo_dado(int valor);

void turno(Jugador &j, EstadoDia &dia);

void reset_turno (Jugador &j, EstadoDia &dia);

void mostrar_estadisticas (Jugador &w) ;

void mostrarEstadisticasSimples (Jugador &w);

void modificadorJugador(Jugador &j , EstadoDia &d ,int dado);

void juego();

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia);

#endif // FUNCIONES_H_INCLUDED

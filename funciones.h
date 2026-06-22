#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

using namespace std;


struct Jugador
{
    int litros_turno;
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
    int kilosTotales;
    int contLanzamientos = 1;
    bool tirada_perfecta = false;
    string nombre;
};

struct EstadoDia
{
    int litros_metalamina = 20;
    int kilos_minimos = 4;
    int dea_limite = 3;
    int litros_cristal_blanco = 3;
    int kilos_cristal_blanco = 1;
    float plata_cristal_blanco = 15000;
    int litros_cristal_azul = 5;
    int kilos_cristal_azul = 2;
    float plata_cristal_azul = 50000;
    bool la_mosca = false;
    bool mike = false;
    bool ding = false;
    bool science = false;
    bool saul_activo = false;
    bool danger_activo = false;
};

struct Puntaje{
    string nombre;
    float dineroFinal;
};

void limpiarPantalla();
void pausar();


void pedirNombres(Jugador &j1, Jugador &j2);

int lanzarDados();

void turno(Jugador &j, EstadoDia &dia);

void dibujarDados(int dados[3]);

void resetearTurno(Jugador &j, EstadoDia &dia);

void mostrarPuntuacionParcial(Jugador &j1, Jugador &j2);
void mostrar_estadisticas (Jugador &j, EstadoDia &d, float plataGanada);

void mostrarEstadisticasSimples (Jugador &j, EstadoDia &d);

void modificadorJugador(Jugador &j , EstadoDia &d , int dado);

void juego(Puntaje puntajes[5]);

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia);

void mod_cartas(EstadoDia &e);

void carta_la_mosca();
void carta_mike();
void carta_ding();
void carta_science();
void carta_saul();
void carta_danger();

void menuFinal(Jugador &g, Jugador &w, Puntaje puntajes[5]);

void evaluarYAgregarAlRanking(Puntaje puntajes[5], string nombreGanador, float dineroGanador);


void estadisticas(const Puntaje Puntajes[5]);
void creditos();
bool salir();

#endif // FUNCIONES_H_INCLUDED

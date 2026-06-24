#include <iostream>
#include "funciones.h"

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Presione Enter para continuar...";
        cin.ignore(1000, '\n');
    #endif
}

void pedirNombres(Jugador &j1, Jugador &j2)
{
    char confirmacion;
    do
    {
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << "Nombre del jugador 1? ";
        getline(cin, j1.nombre);
        cout << "Nombre del jugador 2? ";
        getline(cin, j2.nombre);
        cout << "Confirmar nombres? (S/N) ";
        cin >> confirmacion;
        cin.ignore();
    }
    while (confirmacion != 'S' && confirmacion != 's');
}

void mostrarPuntuacionParcial(Jugador &j1, Jugador &j2)
{
    cout << "=========================================================================" << endl;
    cout << "                      ESTADO ACTUAL DE LA PARTIDA                        " << endl;
    cout << "=========================================================================" << endl;
    cout << j1.nombre <<": $" << j1.plata_banco << "\t\t\t" << j2.nombre <<": $" << j2.plata_banco << endl;
    cout << "CRISTAL TOTAL: " << j1.kilosTotales << " kg." << "\t\t\t" << "CRISTAL TOTAL: " << j2.kilosTotales << " kg." << endl;
    cout << "=========================================================================" << endl << endl;
}

void resetearTurno(Jugador &j, EstadoDia &dia)
{
    j.kilos_turno = 0;
    j.litros_turno = dia.litros_metalamina;
    j.plata_turno = 0;
    j.dea = 0;
    j.pollos_hermanos = 0;
    j.contLanzamientos = 1;
}

void mostrarEstadisticasSimples(Jugador &j, EstadoDia &d)
{
    cout << "Te quedan disponibles : " << j.litros_turno << " lts." << endl;
    cout << "Acumulaste:   " << j.kilos_turno << " kg." << endl;
    cout << "Plata acumulada hasta ahora: $" << j.plata_turno << endl;
    cout << "Sospecha de la DEA: " << j.dea << "/" << d.dea_limite << endl;
    cout << "Favor de Gus:       " << j.pollos_hermanos << "/3" << endl << endl;
}

void mostrar_estadisticas(Jugador &j, EstadoDia &d, float plataGanada)
{
    cout << "Informacion del turno de " << j.nombre << ":" << endl;
    cout << "Litros disponibles: " << j.litros_turno << endl;
    cout << "Plata generada:     $" << plataGanada << endl;
    cout << "Kilos acumulados:   " << j.kilos_turno << endl;
    cout << "Plata en banco:     $" << j.plata_banco << endl;
    cout << "Sospecha de la DEA: " << j.dea << "/" << d.dea_limite << endl;
    cout << "Favor de Gus:       " << j.pollos_hermanos << "/3" << endl;
}

void evaluarYAgregarAlRanking(Puntaje ranking[5], string nombreJugador, float dineroJugador)
{
    // Evaluar si el puntaje del ultimo ganador es mas grande que el del ultimo del top 5
    if (dineroJugador > ranking[4].dineroFinal)
    {

        // Si el puntaje es mas grande piso el valor que tenia antes
        ranking[4].nombre = nombreJugador;
        ranking[4].dineroFinal = dineroJugador;

        // Metodo de burbuja para ordenar de mayor a menor
        for (int j = 0; j < 5; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (ranking[i].dineroFinal < ranking[i + 1].dineroFinal)
                {
                    Puntaje aux = ranking[i + 1];
                    ranking[i + 1] = ranking[i];
                    ranking[i] = aux;
                }
            }
        }
    }
}

void estadisticas(const Puntaje puntajes[5])
{
    limpiarPantalla();
    cout << "=========================================" << endl;
    cout << " ESTADISTICAS                            " << endl;
    cout << "=========================================" << endl;
    cout << " NOMBRE            | DINERO              " << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "- " << puntajes[i].nombre << "\t\t\t";

        // Si no tiene dinero el puesto esta libre
        if (puntajes[i].dineroFinal == 0)
        {
            cout << "---" << endl;
        }
        else
        {
            cout << "$" << puntajes[i].dineroFinal << endl;
        }
    }
    cout << "=========================================" << endl;
    pausar();
}

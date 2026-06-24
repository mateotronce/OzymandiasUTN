#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

void juego(Puntaje puntajes[5])
{

    limpiarPantalla();

    Jugador w = {};
    Jugador g = {};

    pedirNombres(w, g);

    bool continua;
    bool primer_pasada;
    bool victoria = false;

    for (int i = 1; i <= 6 && !victoria; i++)
    {
        EstadoDia dia = {};
        cout.flush();
        limpiarPantalla();

        mod_cartas(dia);
        //1-Mosca 2-Mike 3-Ding 4-Science 5-Saul 6-Danger
        //probarCarta(dia,5);

        mostrarPuntuacionParcial(w,g);

        // Turno jugador 1
        continua = true;
        primer_pasada = true;
        resetearTurno(w, dia);
        mostrarEstadisticasSimples(w, dia);

        float w_banco_antes = w.plata_banco;

        while (continua)
        {
            condicionesJuego(w, dia, continua, primer_pasada, i);
        }

        float w_ganado_dia = w.plata_banco - w_banco_antes;

        cout << "=========================================================================" << endl;
        cout << "Turno de " << g.nombre << endl;
        cout << "=========================================================================" << endl;
        cout << "Presiona Enter cuando estes listo" << endl;
        cin.get();

        cout.flush();
        limpiarPantalla();

        // Turno jugador 2
        continua = true;
        primer_pasada = true;
        resetearTurno(g, dia);
        mostrarEstadisticasSimples(g, dia);

        float g_banco_antes = g.plata_banco;

        while (continua)
        {
            condicionesJuego(g, dia, continua, primer_pasada, i);
        }

        float g_ganado_dia = g.plata_banco - g_banco_antes;

        // Victoria inmediata: se verifica al terminar el dia completo
        if (w.plata_banco >= 737000 || g.plata_banco >= 737000)
        {
            victoria = true;
            menuFinal(g, w, puntajes);
        }
        // Carta I am the danger
        if (dia.danger_activo)
        {
            separadorTematico("GUS");
            cout << "Hoy el que menos cocino tiene que afrontar consecuencias. 50k o todo lo del banco." << endl;
            // Si el Jugador 1 saco mas ganancias:
            if (w_ganado_dia > g_ganado_dia)
            {
                cout << g.nombre << " quedo expuesto. Gus no tolera al eslabon debil." << endl;

                if (g.plata_banco > 50000)
                {
                    g.plata_banco -= 50000;
                    w.plata_banco += 50000;
                }
                else
                {
                    w.plata_banco += g.plata_banco;
                    g.plata_banco = 0;
                }
            }
            // Si el Jugador 2 saco mas ganancias:
            else if (g_ganado_dia > w_ganado_dia)
            {
                cout << w.nombre << " quedo expuesto. Gus no tolera al eslabon debil." << endl;
                if (w.plata_banco > 50000)
                {
                    w.plata_banco -= 50000;
                    g.plata_banco += 50000;
                }
                else
                {
                    g.plata_banco += w.plata_banco;
                    w.plata_banco = 0;
                }
            }
            // Si hay un empate:
            else
            {
                cout << "Ambos cocinaron igual. Gus acepta el empate." << endl;
            }
        }

        if (!victoria)
        {
            cout << "=========================================================================" << endl;
            cout << "Estadisticas del turno para el dia " << i << endl;
            cout << "=========================================================================" << endl;

            mostrar_estadisticas(w, dia, w_ganado_dia);
            cout << "-------------------------------------------------------------------------" << endl;
            mostrar_estadisticas(g, dia, g_ganado_dia);
        }

        if (!victoria && i < 6)
        {
            separadorTematico("DIA");
            cout << "Presiona Enter para continuar al dia " << i + 1 << "..." << endl;
            cin.get();
        }

        else if (i == 6)
        {
            menuFinal(g, w, puntajes);
        }
    }
}

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia)
{
    if (primer_pasada)
    {
        cout << "=========================================================================" << endl;
        cout << "Turno de " << j.nombre << " - Dia: " << num_dia << endl;
        cout << "=========================================================================" << endl;
        cout << "Presiona Enter para tirar los dados" << endl;
        cin.get();
        primer_pasada = false;
    }
    else if (j.dea >= dia.dea_limite)
    {
        separadorTematico("DEA");
        mostrarMensajeAleatorio("sirenas_msgs");

        if (dia.saul_activo)
        {
            separadorTematico("SAUL");
            mostrarMensajeAleatorio("saul_msgs");

            j.plata_turno = 0;
            j.kilos_turno = 0;
            j.cant_allanado += 1;
            j.plata_banco += 50000;
            continua = false;
        }
        else
        {
            cin.get();
            mostrarMensajeAleatorio("dea_msgs");
            j.plata_turno = 0;
            j.kilos_turno = 0;
            j.cant_allanado += 1;
            continua = false;
        }
    }
    else if (j.kilos_turno < dia.kilos_minimos && j.litros_turno >= 3)
    {
        cout << "La cuota minima todavia no esta cubierta. Seguis cocinando." << endl;
        cout << "Presiona Enter para tirar los dados" << endl;
        cin.get();
    }
    else if (j.litros_turno < 3)
    {
        separadorTematico("LAB");
        mostrarMensajeAleatorio("lab_msgs");

        cin.get();

        separadorTematico("GUS");

        if (j.kilos_turno < dia.kilos_minimos)
        {
            mostrarMensajeAleatorio("gus_fail");

            continua = false;
            j.plata_turno = 0;
            j.kilos_turno = 0;
        }
        else
        {
            mostrarMensajeAleatorio("gus_ok");

            if (j.plata_turno > j.plata_turno_max)
            {
                j.plata_turno_max = j.plata_turno;
            }
            j.plata_banco += j.plata_turno;
            j.kilosTotales += j.kilos_turno;
            j.plata_turno = 0;
            j.cant_dia_plantado += 1;
            continua = false;
        }
    }
    else
    {
        int valor;

        do
        {
            cout << "Siempre se puede cocinar mas. La pregunta es si vale el riesgo." << endl;
            cout << "1) Seguir cocinando." << endl << "2) Plantarse y cobrar." << endl;
            cin >> valor;
            cin.ignore();

            if(cin.fail() || valor < 1 || valor > 2 )
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: ingresar solo un numero! (1 o 2)" << endl << endl;
                valor = 0;
            }
        }
        while(valor < 1 || valor > 2);

        if (valor == 2)
        {
            continua = false;
            cout << "Guardas el delantal. Se acreditan $" << j.plata_turno << " a tu banco." << endl;
            if (j.plata_turno > j.plata_turno_max)
            {
                j.plata_turno_max = j.plata_turno;
            }
            j.plata_banco += j.plata_turno;
            j.kilosTotales += j.kilos_turno;
            j.cant_dia_plantado += 1;
        }
    }

    if (continua)
    {
        turno(j, dia);

        //Dados: 1 a 3 = COMUN, 4 = AZUL, 5 = DEA, 6 = POLLOS.
        //probarDados(j, dia, 6, 6, 6);

        j.contLanzamientos++;
        mostrarEstadisticasSimples(j, dia);
    }
}

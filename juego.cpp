#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;



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

void animarPuntos(int cantidad, int delay_ms) {
    for (int i = 0; i < cantidad; i++) {
        cout << "." << flush;
        usleep(delay_ms * 1000);
    }
    cout << "\n";
}

void separadorTematico(const string& tipo) {
    if (tipo == "DEA") {
        cout << "\n  *** [ D . E . A . ] ***\n" << endl;
    } else if (tipo == "GUS") {
        cout << "\n  === [ POLLOS HERMANOS ] ===\n" << endl;
    } else if (tipo == "LAB") {
        cout << "\n  --- [ LABORATORIO ] ---\n" << endl;
    } else if (tipo == "SAUL") {
        cout << "\n  +++ [ BETTER CALL SAUL ] +++\n" << endl;
    } else if (tipo == "DIA") {
        cout << "\n  ~~~ [ NUEVO DIA ] ~~~\n" << endl;
    }
}

string msgAleatorio(const string msgs[], int n) {
    return msgs[rand() % n];
}



void juego() {

    Jugador w = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Jugador g = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    pedirNombres(w, g);

    bool continua;
    bool primer_pasada;
    bool victoria = false;

    for (int i = 1; i <= 6 && !victoria; i++) {
        EstadoDia dia = {};
        cout.flush();
        limpiarPantalla();

        mod_cartas(dia);

        // Turno jugador 1
        continua = true;
        primer_pasada = true;
        reset_turno(w, dia);
        mostrarEstadisticasSimples(w, dia);
        while (continua) {
            condicionesJuego(w, dia, continua, primer_pasada, i);
        }

        cout << "\n--- Turno de " << g.nombre << " ---" << endl;
        cout << "Presiona Enter cuando estes listo" << endl;
        cin.get();

        cout.flush();
        limpiarPantalla();

        // Turno jugador 2
        continua = true;
        primer_pasada = true;
        reset_turno(g, dia);
        mostrarEstadisticasSimples(g, dia);
        while (continua) {
            condicionesJuego(g, dia, continua, primer_pasada, i);
        }

        // Victoria inmediata: se verifica al terminar el dia completo
        if (w.plata_banco >= 737000 || g.plata_banco >= 737000) {
            victoria = true;
            menuFinal(g, w);
        }

        if (dia.danger_activo) {
            separadorTematico("GUS");
            cout << "Hoy el que menos cocino tiene que afrontar consecuencias. 50k o todo lo del banco.\n" << endl;

            if (w.plata_turno > g.plata_turno) {
                cout << g.nombre << " quedo expuesto. Gus no tolera al eslabon debil." << endl;
                if (g.plata_banco > 50000) {
                    g.plata_banco -= 50000;
                    w.plata_banco += 50000;
                } else {
                    w.plata_banco += g.plata_banco;
                    g.plata_banco = 0;
                }
            } else {
                cout << w.nombre << " quedo expuesto. Gus no tolera al eslabon debil." << endl;
                if (w.plata_banco > 50000) {
                    w.plata_banco -= 50000;
                    g.plata_banco += 50000;
                } else {
                    g.plata_banco += g.plata_banco;
                    w.plata_banco = 0;
                }
            }
        }

        if (!victoria) {
            cout << "\n------------------------" << endl;
            cout << "Estadisticas del turno para el dia " << i << endl;
            cout << "------------------------" << endl;

            mostrar_estadisticas(w, dia);
            cout << "\n" << endl;
            mostrar_estadisticas(g, dia);
        }

        if (!victoria && i < 6) {
            separadorTematico("DIA");
            cout << "Presiona Enter para continuar al dia " << i + 1 << "..." << endl;
            cin.get();
        } else if (i == 6) {
            menuFinal(g, w);
        }
    }
}

void condicionesJuego(Jugador &j, EstadoDia &dia, bool &continua, bool &primer_pasada, int num_dia) {

    if (primer_pasada) {
        cout << "\n --------------------------------------- \n" << endl;
        cout << "Turno de " << j.nombre << " - Dia: " << num_dia << endl;
        cout << "\n --------------------------------------- \n" << endl;

        cout << "Presiona Enter para tirar los dados";
        animarPuntos(3, 400);
        cin.get();
        primer_pasada = false;
    }
    else if (j.dea >= dia.dea_limite) {
        separadorTematico("DEA");

        const string sirenas[] = {
            "Rojo y azul destella en la ventana. Las sirenas se acercan",
            "Un sedan sin logos estaciona enfrente. Dos tipos de traje bajan lentamente",
            "Escuchas el radio de un agente federal. Estan muy cerca"
        };
        cout << msgAleatorio(sirenas, 3);
        animarPuntos(4, 600);

        if (dia.saul_activo) {
            separadorTematico("SAUL");
            const string saul_msgs[] = {
                "Justo cuando todo parecia perdido, Saul Goodman entra con su maletin.\n'Mi cliente no sabe nada, agente.' Por un tecnicismo perdiste lo del turno,\npero el estado te debe 50k. Saul sonrie.",
                "Saul aparece de la nada. 'Llamenme.' Dos llamadas y un fax despues,\nla DEA se va con las manos vacias. Perdiste lo del turno,\npero Saul nego un bono de 50k. No preguntes como.",
                "La DEA entra. Saul ya estaba adentro.\n'Todo lo que ven aqui es propiedad de Madrigal Electromotive.' Se van.\nCosto lo del turno, pero el estado reintegra 50k por error de procedimiento."
            };
            cout << msgAleatorio(saul_msgs, 3) << "\n" << endl;
            j.plata_turno = 0;
            j.kilos_turno = 0;
            j.cant_allanado += 1;
            j.plata_banco += 50000;
            continua = false;
        } else {
            cin.get();
            const string dea_msgs[] = {
                "Hank Schrader entra primero. Detras, seis agentes mas.\nTodo lo del turno, confiscado. Fin.",
                "La DEA arrasa el lab. No queda nada. El turno termina en cero.",
                "Agentes por todas partes. En segundos, todo lo que cocinaste\ndesaparece en bolsas de evidencia."
            };
            cout << "\n" << msgAleatorio(dea_msgs, 3) << "\n" << endl;
            j.plata_turno = 0;
            j.kilos_turno = 0;
            j.cant_allanado += 1;
            continua = false;
        }
    }
    else if (j.kilos_turno < dia.kilos_minimos && j.litros_turno >= 3) {
        cout << "\nLa cuota minima todavia no esta cubierta. Seguis cocinando." << endl;
        cout << "Presiona Enter para tirar los dados";
        animarPuntos(3, 300);
        cin.get();
    }
    else if (j.litros_turno < 3) {
        separadorTematico("LAB");

        const string lab_msgs[] = {
            "Los ultimos litros de metilamina se agotan. El generador se apaga.\nSilencio absoluto. Afuera, el gravel cruje bajo unos pasos lentos",
            "El lab queda a oscuras. Sin materia prima, no hay cocina.\nAlguien gira el picaporte de la puerta",
            "La ultima gota cae. El extractor se detiene.\nEl lab queda en un silencio que pesa"
        };
        cout << msgAleatorio(lab_msgs, 3);
        animarPuntos(4, 700);
        cin.get();

        separadorTematico("GUS");

        if (j.kilos_turno < dia.kilos_minimos) {
            const string gus_fail[] = {
                "Gus entra. Revisa los numeros. Te mira fijo, sin parpadear.\n'Esto no es suficiente.' Perdes todo lo de hoy.",
                "Gus inspecciona el producto en silencio. Cierra el cuaderno.\n'No alcanza.' Todo el turno, perdido.",
                "Gus ve los kilos. No dice nada. Solo hace un gesto con la cabeza.\nLos hombres de Mike se llevan todo."
            };
            cout << "\n" << msgAleatorio(gus_fail, 3) << "\n" << endl;
            continua = false;
        } else {
            const string gus_ok[] = {
                "Gus revisa el producto. Asiente, apenas. 'Bien hecho.'\nLa plata se transfiere al banco.",
                "Gus toca la bolsa, la mira. Silencio. Luego: 'Aceptable.'\nLa transferencia se efectua.",
                "Gus recorre el lab con la mirada. 'La cuota se cumplio.'\nLos numeros aparecen en tu banco."
            };
            cout << "\n" << msgAleatorio(gus_ok, 3) << "\n" << endl;
            j.plata_banco += j.plata_turno;
            j.plata_turno = 0;
            j.cant_dia_plantado += 1;
            continua = false;
        }
    }
    else {
        int valor;
        cout << "\nSiempre se puede cocinar mas. La pregunta es si vale el riesgo." << endl;
        cout << "1) Seguir cocinando" << endl << "2) Plantarse y cobrar\n" << endl;
        cin >> valor;
        cin.ignore();
        if (valor == 2) {
            continua = false;
            cout << "Guardas el delantal. Se acreditan $" << j.plata_turno << " a tu banco.\n" << endl;
            j.plata_banco += j.plata_turno;
            j.plata_turno = 0;
            j.cant_dia_plantado += 1;
        }
    }

    if (continua) {
        turno(j, dia);
        mostrarEstadisticasSimples(j, dia);
    }
    // A1A CAR WASH HITO busco mayor ganancia de dinero en un solo dia
    if (j.plata_turno > j.plata_turno_max) {
        j.plata_turno_max = j.plata_turno;
    }
}


void reset_turno(Jugador &j, EstadoDia &dia) {
    j.kilos_turno = 0;
    j.litros_turno = dia.litros_metalamina;
    j.plata_turno = 0;
    j.dea = 0;
    j.pollos_hermanos = 0;
}


void mostrar_estadisticas(Jugador &w, EstadoDia &d) {
    cout << "\nInformacion del turno de " << w.nombre << ":" << endl;
    cout << "Litros disponibles: " << w.litros_turno << endl;
    cout << "Plata generada:     $" << w.plata_turno << endl;
    cout << "Kilos acumulados:   " << w.kilos_turno << endl;
    cout << "Plata en banco:     $" << w.plata_banco << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/" << d.dea_limite << endl;
    cout << "Favor de Gus:       " << w.pollos_hermanos << "/ 3" << endl;
}

void mostrarEstadisticasSimples(Jugador &w, EstadoDia &d) {
    cout << "Te quedan disponibles : " << w.litros_turno << " litros" << endl;
    cout << "Acumulaste:   " << w.kilos_turno << " Kilos" << endl;
    cout << "Sospecha de la DEA: " << w.dea << "/" << d.dea_limite << endl;
    cout << "Favor de Gus:       " << w.pollos_hermanos << "/ 3" << endl;
}

void pedirNombres(Jugador &j1, Jugador &j2) {
    char confirmacion;
    do {
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << "¿Nombre del jugador 1? ";
        cin >> j1.nombre;
        cout << "¿Nombre del jugador 2? ";
        cin >> j2.nombre;
        cout << "¿Confirmar nombres? (S/N) ";
        cin >> confirmacion;
        cin.ignore();
    } while (confirmacion != 'S' && confirmacion != 's');
}

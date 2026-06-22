#include <iostream>
#include "funciones.h"
#include <ctime>

using namespace std;


int main()
{
    srand(time(0));
    //Inicializacion del vector de puntajes
    Puntaje puntajes[5] = {
        {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}
    };
    //Vector de prueba para probar ordenamiento
    // Puntaje puntajes[5] = {
    //     {"Walter", 800000}, {"Jesse", 750000}, {"Tuco", 50000}, {"Saul", 450000}, {"Kim", 50000}
    // };

    int opcion;
    setlocale(LC_ALL, "Spanish");

    do{

    limpiarPantalla();

    cout << "OZYMANDIAS" << endl;
    cout << "---------------------------------" << endl;
    cout << "Menu principal" << endl;
    cout << "---------------------------------" << endl;
    cout << "1 - Jugar" << endl;
    cout << "2 - Estadisticas" << endl;
    cout << "3 - Creditos" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - Salir" << endl;
    cout <<"Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore(1000, '\n');

    switch(opcion){
        case 1:
            juego(puntajes);
            break;
        case 2:
            estadisticas(puntajes);
            break;
        case 3:
            creditos();
            break;
        case 0:
            if(salir()== false){
                opcion = -1;
            }
            break;
        default:
            limpiarPantalla();
            cout << "Ingrese opcion valida" << endl;
            cin.clear();
            cin.ignore();
            pausar();
            break;
        }
    }
    while(opcion != 0);

    return 0;
}

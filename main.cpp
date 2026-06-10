#include <iostream>
#include "funciones.h"

using namespace std;


int main()
{
    //Inicializacion del vector de puntajes
    Puntaje puntajes[5] = {
        {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}
    };
    //Vector de prueba para probar ordenamiento
   /* Puntaje puntajes[5] = {
        {"Walter", 800000}, {"Jesse", 750000}, {"Tuco", 50000}, {"Saul", 450000}, {"Kim", 50000}
    };*/


    int opcion;
    setlocale(LC_ALL, "Spanish");

    do{

    system("cls");

    cout << "Menu principal" << endl;
    cout << "--------------" << endl;
    cout << "1 - Jugar" << endl;
    cout << "2 - Estadisticas" << endl;
    cout << "3 - Creditos" << endl;
    cout << "--------------" << endl;
    cout << "0 - Salir" << endl;
    cout <<"Ingrese una opcion: ";
    cin >> opcion;

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
            system("cls");
            cout << "Ingrese opcion valida" << endl;
            system("pause");
            break;


    }


    }while(opcion != 0);



    return 0;
}

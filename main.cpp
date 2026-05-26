#include <iostream>
#include "funciones.h"

using namespace std;


int main()
{
    int opcion;

    do{

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
            //Juego();
            break;
        case 2:
            //Estadisticas();
            break;
        case 3:
            //Creditos();
            break;
        case 0:
            if(salir()== false){
                opcion = -1;
            }
            break;
        default:
            system("cls");
            cout << "Ingrese opcion valida" << endl;
            break;


    }


    }while(opcion != 0);


    
    return 0;
}

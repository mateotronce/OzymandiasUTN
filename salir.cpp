#include <iostream>
#include "funciones.h"
using namespace std;


bool salir(){

    system("cls");
    char confirmacion;

    cout << "Seguro que desea salir? S/N ";
    cin >> confirmacion;

    if(confirmacion == 'S' || confirmacion == 's'){
        cout << endl << "Gracias por jugar OZYMANDIAS!" << endl;
        return true;
    }
    else{
        return false;
    }
}

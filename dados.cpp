#include "funciones.h"
#include <cstdlib>
#include <string>  
using namespace std;


void lanzarDados(int resultado[3]){
    for (int i = 0; i < 3; i++){
        resultado[i] = (rand() % 6) + 1;
    }
}

string simbolo_dado(int valor){
    string cristal1 = "◊";
    string cristal2 = "◈";
    string pollo = "<°)";
    string dea = "[D]";

    switch (valor)
    {
    case 1:
        return cristal1;
        break;  
    case 2:
        return cristal1;
        break;
    case 3:
        return cristal1;
        break;
    case 4:
        return cristal2;
        break;
    case 5:
        return pollo;
        break;
    case 6:
        return dea;
        break;
    default:
        return "?";
    }
}
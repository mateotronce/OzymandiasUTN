#include<iostream>
#include "funciones.h"
#include<cstdlib>
#include <ctime>

using namespace std;



int main () {
    srand(time(nullptr));


    bool continua = true;


    cout << "-----Lista simbolos-----" << endl 
         << "Cristal comun = ◊" << endl 
         << "Cristal azul  = ◈" << endl
         << "DEA = [D]" << endl 
         << "Pollos Hermanos = <°)" << endl
         << "------------------------" << endl;

    EstadoDia dia = {};

    //Loop jugable
    Jugador w = {0,0,0,0,0}; //walter

    
    bool primer_pasada = true;

    for (int i = 1; i <= 6 ; i ++){
        continua = true;
        primer_pasada = true;

        //carta

//        mod_carta(dia);

        reset_turno(w, dia);


        //accion jugador 1

        while (continua)
        {

            if (primer_pasada) {
                cout << "\n --------------------------------------- \n" << endl;
                cout << "Comienza el dia: " << i << endl;
                cout << "\n --------------------------------------- \n" << endl;
                primer_pasada = false;
            }
            else if (w.dea >= dia.dea_limite) {
                cout << "\n Fin: La dea te encontro, piedes todo \n" << endl;
                w = Jugador{0,0,0,0,0,0};
                continua = false;
            }
            else if (w.kilos_turno < 4 && w.litros_turno >= 3) {
                cout << "No te podes plantar , presiona enter para tirar los dados:" << endl;
                cin.get();
            }
            else if(w.litros_turno < 3) {
                if (w.kilos_turno < 4 ){
                    cout << "Gus entra al laboratorio apagado pr falta de sumistro y ve que no lograste la cuota, te descarta todo el producto y te saca la ganancia del dia. Pierdes todo lo de hoy \n" << endl;
                    continua = false;   
                }    
                else{
                    cout << "Gus entra al laboratorio apagado por falta de sumistro y ve que lograste la cuota. Se pasa la plata acumulada a tu cuenta de banco \n" << endl;
                    w.plata_banco += w.plata_turno;
                    continua = false;
                }
            }
            else {
                int valor ;
                cout << "Tenes 2 opciones o seguis pruduciendo o dejas acá " << endl;
                cout << "1) Seguir" << endl << "2) Parar \n" << endl; 
                cin >> valor;
                cin.ignore();
                if (valor == 2) {
                    continua = false;
                    cout << "Finalizas el turno, se suma a tu banco: " << w.plata_turno << endl;
                    w.plata_banco += w.plata_turno;
                    w.plata_turno = 0;
                }

            }

            if (continua) {
                turno(w, dia);
            }

            mostrar_estadisticas(w);

            
        }
        

        //accion jugador 2

        if (i < 6) {
            cout << "\nPresioná Enter para continuar al día " << i + 1 << "..." << endl;
            cin.get();
        }

    }

}

void reset_turno (Jugador &j, EstadoDia &dia) {

        j.kilos_turno = 0;
        j.litros_turno = dia.litros_metalamina;
        j.plata_turno = 0;
        
}

void mostrar_estadisticas (Jugador &w) {

        cout << "\nInformacion del turno: " << endl;
        cout << "Litros disponibles: " << w.litros_turno << endl;
        cout << "Plata generada: " << w.plata_turno << endl;
        cout << "Kilos acumulados: " << w.kilos_turno << endl;
        cout << "Plata en banco: " << w.plata_banco << endl; 
        cout << "Sospecha de la dea: " << w.dea << "/ 3" << endl;
        cout << "Favor de los pollos hermanos: " << w.pollos_hermanos << "/ 3" << endl;

}
#include <iostream>
#include "funciones.h"

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

void mostrarMensajeAleatorio(const string& tipo){
    if (tipo == "sirenas_msgs"){
        const string sirenas[] = {
            "Rojo y azul destella en la ventana. Las sirenas se acercan",
            "Un sedan sin logos estaciona enfrente. Dos tipos de traje bajan lentamente",
            "Escuchas el radio de un agente federal. Estan muy cerca"
        };

        cout << msgAleatorio(sirenas, 3) << endl;
    }
    else if(tipo == "saul_msgs"){
        const string saul_msgs[] = {
                "Justo cuando todo parecia perdido, Saul Goodman entra con su maletin.\n'Mi cliente no sabe nada, agente.' Por un tecnicismo perdiste lo del turno,\npero el estado te debe 50k. Saul sonrie.",
                "Saul aparece de la nada. 'Llamenme.' Dos llamadas y un fax despues,\nla DEA se va con las manos vacias. Perdiste lo del turno,\npero Saul nego un bono de 50k. No preguntes como.",
                "La DEA entra. Saul ya estaba adentro.\n'Todo lo que ven aqui es propiedad de Madrigal Electromotive.' Se van.\nCosto lo del turno, pero el estado reintegra 50k por error de procedimiento."
            };
        cout << msgAleatorio(saul_msgs, 3) << endl;
    }
    else if(tipo == "dea_msgs"){
        const string dea_msgs[] = {
                "Hank Schrader entra primero. Detras, seis agentes mas.\nTodo lo del turno, confiscado. Fin.",
                "La DEA arrasa el lab. No queda nada. El turno termina en cero.",
                "Agentes por todas partes. En segundos, todo lo que cocinaste\ndesaparece en bolsas de evidencia."
            };
        cout << "\n" << msgAleatorio(dea_msgs, 3) << "\n" << endl;
    }
    else if(tipo == "lab_msgs"){
        const string lab_msgs[] = {
            "Los ultimos litros de metilamina se agotan. El generador se apaga.\nSilencio absoluto. Afuera, el gravel cruje bajo unos pasos lentos",
            "El laboratorio queda a oscuras. Sin materia prima, no hay cocina.\nAlguien gira el picaporte de la puerta",
            "La ultima gota cae. El extractor se detiene.\nEl laboratorio queda en un silencio que pesa"
        };
        cout << msgAleatorio(lab_msgs, 3) << endl;
    }
    else if(tipo == "gus_fail"){
        const string gus_fail[] = {
                "Gus entra. Revisa los numeros. Te mira fijo, sin parpadear.\n'Esto no es suficiente.' Perdes todo lo de hoy.",
                "Gus inspecciona el producto en silencio. Cierra el cuaderno.\n'No alcanza.' Todo el turno, perdido.",
                "Gus ve los kilos. No dice nada. Solo hace un gesto con la cabeza.\nLos hombres de Mike se llevan todo."
            };
        cout << "\n" << msgAleatorio(gus_fail, 3) << "\n" << endl;
    }
    else if(tipo == "gus_ok"){
        const string gus_ok[] = {
                "Gus revisa el producto. Asiente, apenas. 'Bien hecho.'\nLa plata se transfiere al banco.",
                "Gus toca la bolsa, la mira. Silencio. Luego: 'Aceptable.'\nLa transferencia se efectua.",
                "Gus recorre el lab con la mirada. 'La cuota se cumplio.'\nLos numeros aparecen en tu banco."
            };
        cout << "\n" << msgAleatorio(gus_ok, 3) << "\n" << endl;
    }
}

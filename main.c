#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**13) Suponer un juego de cartas en el que en cada mano se reparten dos
cartas por jugador.
Un jugador gana la mano cuando la suma de sus cartas es mayor que las
del contrario y al hacerlo coloca todas las cartas (las de el y las de
su rival) en su pila de puntos. En caso de empate (y para simplificar)
siempre gana el jugador1.
Simular la ejecución del juego de tal manera que dada una pila MAZO
(con un numero de elementos múltiplo de cuatro) distribuya
las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar
las pilas auxiliares que crea conveniente. */

///funcion que suma los elementos de una pila y devuelve el resultado:
int sumaPila(Pila dada){
    int suma = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&dada)){
        suma = suma + tope(&dada);
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }
    /*printf("Suma de pila: %i \n",suma);*/
    return suma;
}

int main(){
    int r, i, puntos1, puntos2;
    Pila mazo, jug1, jug2, puntosJug1, puntosJug2;
    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);
    inicpila(&puntosJug1);
    inicpila(&puntosJug2);


    ///cargar mazo con 20 elementos aleatorios del 1 al 12:
    for(i=0;i<20;i++){
        r = 1 + rand()%12;
        apilar(&mazo, r);
    }

    while(!pilavacia(&mazo)){
        ///repartir 4 cartas entre jug1 y jug2:
        for(i=0;i<2;i++){
            apilar(&jug1, desapilar(&mazo));
            apilar(&jug2, desapilar(&mazo));
        }
        ///sumar cartas de ambos jugadores, comparar y apilar:
        if(sumaPila(jug1) < sumaPila(jug2)){
            while(!pilavacia(&jug1) || !pilavacia(&jug2)){
                apilar(&puntosJug1, desapilar(&jug1));
                apilar(&puntosJug1, desapilar(&jug2));
            }
        }else{
            while(!pilavacia(&jug2) || !pilavacia(&jug1)){
                apilar(&puntosJug2, desapilar(&jug1));
                apilar(&puntosJug2, desapilar(&jug2));
            }
        }

    }
    ///Calcular puntaje de cada jugador:
    puntos1 = sumaPila(puntosJug1);
    puntos2 = sumaPila(puntosJug2);

    ///Mostrar cartas y puntos de jugadores al finalizar el juego:
    printf("Puntos Jugador 1: ");
    mostrar(&puntosJug1);

    printf("Puntos Jugador 2: ");
    mostrar(&puntosJug2);

    printf("Puntos Jugador 1: %i\n",puntos1);
    printf("Puntos Jugador 2: %i\n\n",puntos2);
    if(puntos1 > puntos2){
        printf("GANADOR: JUGADOR 1\n\n");
    }else{
        printf("GANADOR: JUGADOR 2\n\n");
    }

    return 0;
}
fghjklçlkjgf

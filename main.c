#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/**UTN | Mar del Plata - Programación 1 - Laboratorio 1 Práctico 2 – Pilas avanzado*/

/*** 1)  Sumar los elementos de una pila (usar variables)***/
/*
int main()
{
    char control = 's';
    Pila pilita;
    inicpila(&pilita);
    int suma=0;

    while(control == 's'){
        leer(&pilita);
        printf("Continuar? S/N");
        fflush(stdin);
        scanf("%c", &control);
    }

    while(!pilavacia(&pilita))
    {
        suma= suma+ desapilar(&pilita);
    }
    printf("La suma de pilita es %i",suma);

    return 0;
}
*/

/**2)  Contar los elementos de una pila  - usar variables */
/*
int main(){

int i=0;
char control;
Pila pilita, pilota;
inicpila(&pilita);
inicpila(&pilota);

do{
    leer(&pilita);
    printf("Desea continuar? s/n");
    fflush(stdin);
    scanf("%c", &control);
}while(control=='s');

while(!pilavacia(&pilita)){
    apilar(&pilota, desapilar(&pilita));
    i++;
}

printf("La pila tiene %i elementos", i);


return 0;
}
*/

/**3)  Calcular el promedio de los valores de una pila
(usar variables) */
/*
int main(){
int i=0;
float promedio = 0;
Pila pilita;
inicpila(&pilita);
char control;
do{
    leer(&pilita);
    printf("Desea continuar? s/n");
    fflush(stdin);
    scanf("%c", &control);
}while(control=='s');

while(!pilavacia(&pilita)){
    promedio = promedio + desapilar(&pilita);
   i++;
}
promedio= (float)promedio/(float)i;

printf("El promedio de pilita es %.2f", promedio);

return 0;
}
*/

/**4)  Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables) */
/*
int main(){

int r, i;
Pila pilita, menor, aux;
inicpila(&pilita);
inicpila(&menor);
inicpila(&aux);

//cargar pila con elementos aleatorios:

for(i=0;i<20;i++){
    r = rand()%20;
    apilar(&pilita, r);
}

//encontrar menor elemento:

apilar(&menor, desapilar(&pilita));

while(!pilavacia(&pilita)){
    if(tope(&pilita) < tope(&menor)){
        apilar(&aux, desapilar(&menor));
        apilar(&menor, desapilar(&pilita));
    } else {
        apilar(&aux, desapilar(&pilita));
    }
}

//devolver elementos a pilita:

while(!pilavacia(&aux)){
    apilar(&pilita, desapilar(&aux));
}

//mostrar resultados al usuario:

printf("Pila con elementos aleatorios: /n");
mostrar(&pilita);
printf("Menor elemento de la pila: %i",tope(&menor));
return 0;
}
*/

/**5) Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
que se conserve el orden. (sin variables)**/
/*
int main(){

int i;
Pila ordenada, num, aux;
inicpila(&ordenada);
inicpila(&num);
inicpila(&aux);

//cargar pila ordenada de 1 a 10:
for(i=10;i>0;i=i-1){
    apilar(&ordenada, i);
}

//pedir numero al usuario:
printf("Cargar elemento en una pila ordenada: ");
mostrar(&ordenada);
leer(&num);

//recorrer ordenada y apilar num en posicion correcta:
while(!pilavacia(&ordenada) && !pilavacia(&num)){
    if(tope(&ordenada) < tope(&num)){
        apilar(&aux, desapilar(&ordenada));
    } else {
        apilar(&ordenada, desapilar(&num));
    }
}

while(!pilavacia(&aux)){
    apilar(&ordenada, desapilar(&aux));
}

//mostrar resultados al usuario:
printf("Pila ordenada con nuevo elemento: ");
mostrar(&ordenada);

return 0;
}
*/
/**6) Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
ordenación por selección. **/

/*
int main(){

int i, j, r;
Pila pilita, menor, ordenada, aux;
inicpila(&pilita);
inicpila(&menor);
inicpila(&ordenada);
inicpila(&aux);


//cargar pila con elementos aleatorios:
printf("Cargar una pila con elementos aleatorios. \n");
printf("Ingrese cantidad de elementos de la pila: ");
scanf("%i",&j);

for(i=0;i<j;i++){
    r = rand()%20;
    apilar(&pilita, r);
}

printf("Pila con %i elementos aleatorios desordenados: \n",j);
mostrar(&pilita);

//ordenar pilita:

while(!pilavacia(&pilita)){
    apilar(&menor, desapilar(&pilita));
    while(!pilavacia(&pilita)){
        if(tope(&pilita) < tope(&menor)){
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&pilita));
        } else {
            apilar(&aux, desapilar(&pilita));
        }
    }
    apilar(&ordenada, desapilar(&menor));
    while(!pilavacia(&aux)){
        apilar(&pilita, desapilar(&aux));
    }
}

//mostrar resultados al usuario:
printf("Pila ordenada: \n");
mostrar(&ordenada);




return 0;
}
*/

/**7) Determinar si un elemento buscado está dentro de una pila**/
/*
int main(){

int i,r;
Pila pilita, buscado, aux;

inicpila(&pilita);
inicpila(&buscado);
inicpila(&aux);

//cargar pila con elementos aleatorios del 1 al 15:

for(i=0;i<10;i++){
    r = rand()%15;
    apilar(&pilita, r);
}


//pedir elemento buscado al usuario:
printf("Buscar elemento en la pila: \n");
leer(&buscado);

//recorrer pilita hasta hallar el numero buscado
while(!pilavacia(&pilita) && tope(&pilita) != tope(&buscado)){
    apilar(&aux, desapilar(&pilita));
}

//mostrar resultado al usuario
if(pilavacia(&pilita)){
    printf("El numero %i no se encuentra en la pila",tope(&buscado));
}else{
    printf("El numero %i se encuntra en la pila", tope(&buscado));
}

return 0;
}
*/

/** 8) Eliminar un elemento de una pila **/
/*
int main(){
int i,r;
Pila pilita, buscado, aux, descarte;

inicpila(&pilita);
inicpila(&buscado);
inicpila(&aux);
inicpila(&descarte);

//cargar pila con elementos aleatorios del 1 al 15:

for(i=0;i<10;i++){
    r = rand()%15;
    apilar(&pilita, r);
}

//pedir elemento buscado al usuario:
printf("Elminar elemento en la pila: \n");
mostrar(&pilita);
leer(&buscado);

//recorrer pilita hasta hallar el numero buscado y desapilarlo

while(!pilavacia(&pilita)){
    if(tope(&pilita) == tope(&buscado)){
        apilar(&descarte, desapilar(&pilita));
    }else{
        apilar(&aux, desapilar(&pilita));
    }
}

while(!pilavacia(&aux)){
    apilar(&pilita, desapilar(&aux));
}

//mostrar pilita sin el numero buscado:

mostrar(&pilita);


return 0;
}
*/

/** 9) Verificar si una pila DADA es capicua**/
/*
int main(){

Pila dada, copia, invertida, auxDada, auxInvertida;

inicpila(&dada);
inicpila(&copia);
inicpila(&invertida);
inicpila(&auxDada);
inicpila(&auxInvertida);

//cargar dada:

apilar(&dada,1);
apilar(&dada,2);
apilar(&dada,3);
apilar(&dada,4);
apilar(&dada,3);
apilar(&dada,2);
apilar(&dada,1);

printf("Verificar si la pila DADA es capicua: \n");
mostrar(&dada);

copia = dada;

while(!pilavacia(&copia)){
    apilar(&invertida, desapilar(&copia));
}

while(!pilavacia(&dada) && !pilavacia(&invertida) && tope(&dada)==tope(&invertida)){
    apilar(&auxDada, desapilar(&dada));
    apilar(&auxInvertida, desapilar(&invertida));
}

if(pilavacia(&dada) && pilavacia(&invertida)){
    printf("La pila DADA es capicua");
}else{
    printf("La pila DADA no es capicua");
}

return 0;
}
*/

/** 10) Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos
repetidos), realizar un programa que calcule en la pila C la operacion de union. **/
/*
int main(){

int i;
Pila A,B,C;
inicpila(&A);
inicpila(&B);
inicpila(&C);

for(i=0;i<5;i++){ //cargar pila A
    apilar(&A,i);
}

for(i=5;i<10;i++){ //cargar pila B
    apilar(&B,i);
}

while(!pilavacia(&B)){
    apilar(&C, desapilar(&B));
}
while(!pilavacia(&A)){
    apilar(&C, desapilar(&A));
}

mostrar(&C);


return 0;
}
*/

/** 11) Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
el resultado en una pila tambien ordenada en forma creciente (ORDENADAFINAL)*/
/*
int main(){

Pila ordenada1, ordenada2, ordenadaFinal, aux, menor, copia1, copia2;
inicpila(&ordenada1);
inicpila(&ordenada2);
inicpila(&ordenadaFinal);
inicpila(&aux);
inicpila(&menor);
inicpila(&copia1);
inicpila(&copia2);

apilar(&ordenada1,2);
apilar(&ordenada1,4);
apilar(&ordenada1,5);
apilar(&ordenada1,6);
apilar(&ordenada1,8);

copia1 = ordenada1;

apilar(&ordenada2,1);
apilar(&ordenada2,3);
apilar(&ordenada2,4);
apilar(&ordenada2,6);
apilar(&ordenada2,7);

copia2 = ordenada2;

while(!pilavacia(&ordenada2)){
    apilar(&ordenada1, desapilar(&ordenada2));
}

while(!pilavacia(&ordenada1)){
    apilar(&menor, desapilar(&ordenada1));

    while(!pilavacia(&ordenada1)){
        if(tope(&ordenada1) < tope(&menor)){
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&ordenada1));
        }else{
            apilar(&aux, desapilar(&ordenada1));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&ordenada1, desapilar(&aux));
    }

    apilar(&ordenadaFinal, desapilar(&menor));
}

printf("ORDENADA1: \n");
mostrar(&copia1);
printf("ORDENADA2: \n");
mostrar(&copia2);
printf("ORDENADA FINAL: \n");
mostrar(&ordenadaFinal);
return 0;
}
*/

/**12) Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5. */

/*
int main(){

int i,r;
Pila origen, menor, aux;
inicpila(&origen);
inicpila(&menor);
inicpila(&aux);

for(i=0;i<15;i++){
    r = rand()%16;
    apilar(&origen, r);
}

















return 0;
}

*/

/**13) Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador.
Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al
hacerlo coloca todas las cartas (las de el y las de su rival) en su pila de puntos. En caso de
empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal
manera que dada una pila MAZO (con un numero de elementos múltiplo de cuatro) distribuya
las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar
las pilas auxiliares que crea conveniente. */

int main(){

int r,i,
Pila mazo, jug1, jug2, puntosJug1,puntosJug2;

inicpila(&mazo);
inicpila(&jug1);
inicpila(&jug2);
inicpila(&puntosJug1);
inicpila(&puntosJug2);
/*
int sumarPila(Pila dada){
    int suma = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&dada)){
        suma = suma + tope(&dada);
        apilar(&aux, desapilar(&dada));
    }
    return suma;
}
*/
//cargar mazo con 20 elementos aleatorios del 1 al 12
for(i=0;i<20;i++){
    r = 1 + rand()%12;
    apilar(&mazo, r);
}

//repartir cartas entre jug1 y jug2
while(!pilavacia(&mazo)){
    for(i=0;i<2;i++){
        apilar(&jug1, desapilar(&mazo));
        apilar(&jug2, desapilar(&mazo));

    }
}

mostrar(&jug1);
mostrar(&jug2);






return 0;
}




































































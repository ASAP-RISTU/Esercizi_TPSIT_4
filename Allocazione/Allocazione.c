//Creare un puntatore ad interi e a char e stampare il loro valore e il riferimento in memoria
//Davide Ristorto 25/11/2021
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *puntC;        //dichiarazione puntatori
    int *puntInt;

    puntInt = (int *) malloc(1*sizeof(int));       //allocazione dei puntatori
    puntC = (char *)malloc(1*sizeof(char));

    *puntInt = 5;       //assegnamento
    *puntC = 'A';

    printf("puntatore indirizzo intero: %d    valore: %d\n",puntInt, *puntInt); //stampa a video di indirizzo e valore
    printf("puntatore indirizzo char: %d    valore: %c",puntC, *puntC);

    return 0;
}

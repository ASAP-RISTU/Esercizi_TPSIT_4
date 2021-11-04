#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *puntC;        //dichiarazione puntatori
    int *puntInt;

    puntInt = (int *) malloc(1*sizeof(int));       //allocazione
    puntC = (char *)malloc(1*sizeof(char));

    *puntInt = 5;       //assegnamento
    *puntC = 'A';

    printf("puntatore indirizzo intero: %d    valore: %d\n",puntInt, *puntInt); //stampa a video di indirizzo e valore
    printf("puntatore indirizzo char: %d    valore: %c",puntC, *puntC);

    return 0;
}

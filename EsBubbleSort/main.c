#include <stdio.h>
#include <stdlib.h>
#define DIM 5

//fare un Bubble Sort senza usare [e]

void ordinaVettore(int vett[], int n) {
    int sup, i, a;

    for(sup = n - 1; sup > 0; sup--) {
        for(i = 0; i < sup; i++) {
            if(*(vett+i+1) < *(vett+i)) {        // vett è un puntatore, che punta all'inzio della pila del vettore; il +k serve per scorrere le celle
                a = *(vett+i+1);
                *(vett+i+1) = *(vett+i);
               *(vett+i) = a;
            }
        }
    }
}

void caricaVettore(int vett[], int n) {
    int k=0;

    for(k=0; k<n; k++) {
        printf("inserisci numero: ");
        scanf("%d",&*(vett+k));
    }
}

void stampa(int vett[], int n) {
    int k=0;

    for(k=0; k<n; k++) {
        printf("%d  ",*(vett+k));
    }
}

int main() {
    int vett[DIM];

    caricaVettore(vett,DIM);
    ordinaVettore(vett,DIM);
    stampa(vett,DIM);
    return 0;
}

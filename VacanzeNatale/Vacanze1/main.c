//es 1 vacanze di natale
//Considerate una sequenza di interi letti da input e definite una funzione C che listampa
//in modo tale che tutti i pari precedano i dispari, nello stesso ordine in cui vengono letti
//Davide Ristorto 27/12/2021

#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define DIM_MAX 50

int pila[DIM_MAX];
int top = -1;

int pilaPiena(){ // verifica se la pila è piena o può ricevere altri dati
    if(top == DIM_MAX)
        return 1;
    else
        return 0;
}

void push(int data){ //vengono inseriti i dati
    if(!pilaPiena()){
        top++;
        pila[top] = data;
    }
    else
        printf("ERRORE -> pila piena");
}

void ordinaPila(int vet[]){ //funzione per ordinare i dati come da consegna
    for(int k=0;k<DIM;k++){
        if(vet[k]%2==0){
            push(vet[k]);
        }
    }
    for(int k=0;k<DIM;k++){
        if(vet[k]%2!=0)
            push(vet[k]);
    }
}

int main()
{
    int vettore[DIM]; //vettore d'appoggio per prendere i dati
    for (int k=0;k<DIM;k++){
        printf("inserisci un valore: ");
        scanf("%d",&vettore[k]);
    }
    ordinaPila(vettore);
    for (int k=0;k<DIM;k++){
        printf("%d  ",pila[k]);
    }
    return 0;
}

//es 1 vacanze di natale
#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define DIM_MAX 50

int pila[DIM_MAX];
int top = -1;

int pilaPiena(){
    if(top == DIM_MAX)
        return 1;
    else
        return 0;
}

void push(int data){
    if(!pilaPiena()){
        top++;
        pila[top] = data;
    }
    else
        printf("ERRORE -> pila piena");
}

void ordinaPila(int vet[]){
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
    int vettore[DIM];
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

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void inverti(int v[],int dim) {
    int k=0;    //contatore
    int j=dim-1;    //secondo contatore che parte da min-1(ultima cella del vettore)
    int temp; //per caricare temporaneamente il valore del vettore
    for(k=0; k<dim/2; k++) {    //inzio del ciclo
        temp=*(v+k);
        *(v+k)=*(v+j);  //mette nella prima cella il valore dell ultima cella
        *(v+j)=temp;  //mette nell ultima cella temp che ha il valore della prima
        j--;
    }
}

void stampa(int v[],int dim){  //ciclo for per stampare il vettore
for(int k=0;k<dim;k++){
    printf("%d ", *(v+k));
}    
}

int main() {
    int n;
    printf("Quanti numeri da inserire: ");
    scanf("%d", &n);
    int *v=(int*)malloc(n*sizeof(int));
    
    for(int k=0; k<MAX; k++) {      //ciclo per caricare il vettore
        printf("inserisci valore: ");
        scanf("%d"(v+k));
    }
    inverti(v,MAX);
    stampa(v,MAX);

    return 0;
}

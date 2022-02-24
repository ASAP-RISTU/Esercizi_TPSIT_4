/*
1)Crea un programma che:
a)immetta il numero dei nodi inserendo da tastiera i valori per ogni nodo
b)stampi la lista dei valori inseriti
c)stampi la stessa lista cancellando l’ultimo nodo
Davide Ristorto 15/12/2021
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int num;
    struct nodo * next;
} Nodo;

void caricavett(int vett[], int n) { //presa in input dei valori numerici
    int k;
    for(k= 0; k < n; k++) {
        printf("cella[%d]: ", k);
        scanf("%d", &vett[k]);
    }
}

Nodo * crealista( int* v, int n) { //si crea un nuovo nodo
    Nodo * head=NULL;
    Nodo *r=(Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=head;
    for(int k=0; k< n; k++) {
        if(r==NULL)
            r=(Nodo*)malloc(sizeof(Nodo));

        r->num=*(v+k);
        if(head==NULL) {
            head= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        cur->next=NULL;
        r=NULL;
    }
    return head;
}

void stampaLista(Nodo*l)
{
    printf("%d\n",l-> num);
    if(l->next!=NULL)stampaLista(l->next);
}
//difficolta nel svolgere il punto C
int main() {
    int dim;
    printf("quanti numeri da inserire: ");
    scanf("%d", &dim);
    int vett=(int*)malloc(dim*sizeof(int));
    caricavett(vett, dim);
    Nodo * head;
    head= crealista(vett, dim);
    stampaLista(head);
    return 0;
}

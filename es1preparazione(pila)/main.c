//Usa una pila per l'inserimento dei dati e stampa solamente i numeri pari e li sommi stampando il risultato
//Davide Ristorto 05/03/2022

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10

typedef struct nodo { //dichiarazione della stuttura dati (pila)
    int cifra;
    struct nodo* next;
};

int isempty(struct nodo* head) { //funzione che controlla se la pila è vuota
    return (head == NULL) ? 1 : 0;
}

void push(struct nodo** head, struct nodo* element) { //funzione per inserire un elemento nella pila
    if (isempty(*head)) {
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
    return;
}

struct nodo* pop(struct nodo ** head) {  //funzione per estrarre un elemento dalla pila
    struct nodo* ret = *head;

    if(isempty(*head)) {
        return NULL;
    } else
        *head = ret->next;

    return ret;
}

int main() {

    struct nodo* pila = NULL;    //la pila
    struct nodo* elemento;
    int vett[MAX_NUM];          //vettore di appoggio
    int num,somma=0;            //elemento di input della pila  e somma finale
    int k=0;

    for(k=0; k<MAX_NUM; k++) { //la pila viene caricata con i valori interi inseriti da tastiera
        printf("inserisci un numero: ");
        scanf("%d",&num);
        elemento = (struct nodo*)malloc(sizeof(struct nodo)); //si crea un nuovo nodo
        elemento->cifra = num;

        push(&pila,elemento); //fase di push
    }

    for(k=0; k<MAX_NUM; k++) { //con la pop i nodi vengono rimossi dalla pila uno a nuo
        struct nodo* head = pop(&pila);
        vett[k] = head->cifra; //il vettore di appoggio viene caricato con i valori che erano stati inseriti nella pila
    }

    for(k=0; k<MAX_NUM; k++) {  //controllo se un numero è pari
        if(vett[k]%2==0)
            somma+=vett[k];
    }
    printf("la somma dei numeri pari inseriti nella pila e' %d",somma);

    return 0;
}

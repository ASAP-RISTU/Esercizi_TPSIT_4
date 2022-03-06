#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 5

typedef struct nodo {
    int valore;
    struct nodo* next;
};

int isempty(struct nodo* head) {
    return (head == NULL) ? 1 : 0;
}

void enqueue(struct nodo** head, struct nodo** tail, struct nodo* element) {

    if(isempty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;

    return;
}

struct nodo* dequeue(struct nodo** head,struct nodo** tail) {

    struct nodo* ret = *head;

    if(isempty(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head == NULL)
        *tail = NULL;

    return ret;
}

int main() {
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* appoggio;

    int vett[MAX_NUM];
    int num,somma=0;
    int k=0;

    for(k=0; k<MAX_NUM; k++) {
        appoggio = (struct nodo*) malloc(sizeof(struct nodo));
        printf("inserisci un numero da mettere nella coda: ");
        scanf("%d",&appoggio->valore);
        fflush(stdin);

        enqueue(&head,&tail,appoggio);
    }

    for(k=0; k<MAX_NUM; k++) {
        struct nodo* appoggio = dequeue(&head,&tail);
        vett[k] = appoggio->valore;
    }

    for(k=0; k<MAX_NUM; k++) {
        if(vett[k]%2!=0)
            somma+=vett[k];
    }

    printf("la somma dei numeri dispari della coda e': %d",somma);
    return 0;

}

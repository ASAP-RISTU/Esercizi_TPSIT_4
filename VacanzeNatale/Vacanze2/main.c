//es 2 delle vacanze
//Scrivere un programma che legga una sequenza di caratteri e li stampi in ordine inverso. Usa una pila.
//Davide Ristorto 28/12/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pila[20];
int top = -1;

int pilaPiena(){ //controllo che pila non si piena
    if(top == 20)
        return 1;
    else
        return 0;
}

void push(char data){
    if(!pilaPiena()){
        top++;
        pila[top] = data;
    }
    else
        printf("ERRORE -> pila piena");
}

int main()
{
    char stringa[20];
    printf("inserisci parola: ");
    gets(stringa);
    int dim;
    dim = strlen(stringa);
   for(int j=dim-1; j>=0;j--){  //si parte dal fondo della stringa
        push(stringa[j]);
    }
    printf("%s",pila);

    return 0;
}

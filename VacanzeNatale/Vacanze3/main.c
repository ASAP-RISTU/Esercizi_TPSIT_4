//esercizio 3
//scrivere la struttura e i prototipi di funzioni usate per gestire le i dati dei pazienti in ospedale
//Davide Ristorto 28/12/2021
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[256] ;
    char cognome[256] ;
    int matricola;
    int pressione[2]; // minima e massima
    int temperature[3]; // temperature della mattina e pomeriggio e sera
    float parcella; // in euro quello che deve al dottore
}Paziente;

void caricaDati(Paziente p){};

void stampaPressione(Paziente p){
printf("pressione 1: %d     pressione 2: %d",p.pressione[0],p.pressione[1]);
printf("temeratura 1: %d    temperatura 2: %d    temperatura 3: %d",
       p.temperature[0],p.temperature[1],p.temperature[2]);
}

float saldoTot(Paziente v[],int dim){return saldo;}

int main() {
    Paziente rossi;
    Paziente clinica[20];
    caricaDati(rossi);
    stampaPressione(rossi);
    float saldoTotale = saldoTotale(clinica,20);
    return 0;
}

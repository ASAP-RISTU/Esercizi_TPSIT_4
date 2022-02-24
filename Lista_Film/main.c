//dato un file csv con una serie di film e i loro dati, stamparli a terminale
//Davide Ristorto 14/10/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 30


typedef struct { //struttura con i campi dato dei singolo film

    char num[LUNG];
    char titolo[LUNG];
    char tipologia[LUNG];
    char anno[LUNG];
    char disp[LUNG];

} film;

void leggi(film v[], int n, char nomefilm[]) {   //funzione per leggere il file csv
    FILE *fp;
    int conta=0;
    char line[100];
    fp = fopen(nomefilm, "r");
    for(int i=0; i<n; i++) {
        fgets(line, 100, fp);
        char* pezzo = strtok(line, ","); //si usa la strtok per separare le stringe intervallate dalla virgola
        while(pezzo != NULL) {
            switch(conta) {
            case 0:
                strcpy((v+i)->num , pezzo);
                break;
            case 1:
                strcpy((v+i)->titolo, pezzo);
                break;
            case 2:
                strcpy((v+i)->tipologia, pezzo);
                break;
            case 3:
                strcpy((v+i)->anno, pezzo);
                break;
            case 4:
                strcpy((v+i)->disp, pezzo);
                break;
            }
            conta++;
            pezzo = strtok(NULL, ",");
        }
        conta=0;
    }
    fclose(fp);
}

void stampa(film v[],int n) {  //funzione per la stampa della lista dei film formattata
printf("\t%Numero \tTitolo  \tTipologia  \tAnno  \tDisponibilita' \n");
    for(int k=0; k<n; k++) {
        printf("\t%s \t%s  \t%s  \t%s  \t%s \n",(v+k)->num,(v+k)->titolo,(v+k)->tipologia,(v+k)->anno,(v+k)->disp);
    }
}

int main() {
    film catalogo[LUNG]; //vettore catalogo di tipo struttura film
    leggi(catalogo,LUNG,"listafilm.csv.txt");
    stampa(catalogo,LUNG);
    return 0;
}

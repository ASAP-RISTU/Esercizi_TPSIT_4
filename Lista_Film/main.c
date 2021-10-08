#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 30
#include <ctype.h>

typedef struct {        //inizializzazione struttura

    char num[LUNG];
    char titolo[LUNG];
    char tipologia[LUNG];
    char anno[LUNG];
    char disp[LUNG];

} film;

void leggi(film v[], int n, char nomefilm[]) {
    FILE *fp;
    int conta=0;
    char line[100];
    fp = fopen(nomefilm, "r");
    for(int i=0; i<n; i++) {
        fgets(line, 100, fp);
        char* pezzo = strtok(line, ",");
        while(pezzo != NULL) {
            switch(conta) {
            case 0:
                strcpy(v[i].num, pezzo);
                break;
            case 1:
                strcpy(v[i].titolo, pezzo);
                break;
            case 2:
                strcpy(v[i].tipologia, pezzo);
                break;
            case 3:
                strcpy(v[i].anno, pezzo);
                break;
            case 4:
                strcpy(v[i].disp, pezzo);
                break;
            }
            conta++;
            pezzo = strtok(NULL, ",");
        }
        conta=0;
    }
}

void stampa(film v[],int n) {

    for(int k=0; k<n; k++) {
        printf("%s %s  %s  %s  %s \n",v[k].num,v[k].titolo,v[k].tipologia,v[k].anno,v[k].disp);
    }
}

int main() {
    film catalogo[LUNG];
    leggi(catalogo,LUNG,"listafilm.csv.txt");
    stampa(catalogo,LUNG);
    return 0;
}

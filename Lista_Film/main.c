#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 30
#include <ctype.h>

typedef struct {

    char indice;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char disponibile[LUNG];

} film;

void caricaCatalogo(char file[],int n, film v[]) {
    FILE *fp;
    int k=0;
    char *token;


    fp=fopen(file,"r");

    if(fp!=NULL) {
        for(k=0; k<n; k++) {

            token = strtok(fp,",");

           v[k].indice= atoi(token);
            /*
                fscanf(fp,"%d",&v[k].indice);
                str=strtok(NULL,',');
                fgets(v[k].titolo,n,fp);
                str=strtok(NULL,',');
                fgets(v[k].genere,n,fp);
                str=strtok(NULL,',');
                fscanf(fp,"%d",&v[k].anno);
                str=strtok(NULL,',');
                fgets(v[k].disponibile,n,fp);
                */


        }
    }

}

void stampa(film v[],int n) {

    for(int k=0; k<n; k++) {
       // printf("%d %s  %s  %d  %s ",v[k].indice,v[k].titolo,v[k].genere,v[k].anno,v[k].disponibile);
        printf("%s\n" ,v[k].indice);
    }
}

int main() {
    film catalogo[LUNG];
    caricaCatalogo("listafilm.csv.txt",LUNG,catalogo);
    stampa(catalogo,LUNG);
    return 0;
}

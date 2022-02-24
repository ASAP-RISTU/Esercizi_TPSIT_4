/* struttura per memorizzare i dati degli studenti e i voti di ita,mate,info.
 e trovare la dicisplina con la media piu alta
Davide Ristorto 17/10/2021
*/

#include <stdio.h>
#include <stdlib.h>
#define LUNG 50
#define NClass 3



typedef struct {
    char nome[LUNG];
    char cognome[LUNG];
    float votoMate;
    float votoInfo;
    float votoIta;

} studente;

void inserisciDati(studente v[], int n) {
    int k=0;

    for(k=0; k<n; k++) {

        printf("inserisci il nome: ");
        scanf("%s",v[k].nome);
        fflush(stdin);

        printf("inserisci il cognome: ");
        scanf("%s",v[k].cognome);
        fflush(stdin);

        printf("inserisci il voto di matematica: ");
        scanf("%f",&v[k].votoMate);

        printf("inserisci il voto di informatica: ");
        scanf("%f",&v[k].votoInfo);

        printf("inserisci il voto di italiano: ");
        scanf("%f",&v[k].votoIta);

    }
}

void media(studente v[],int n) {
    int k;
    float mediaMate, mediaInfo,mediaIta;

    for(k=0; k<n; k++) {
        mediaMate=mediaMate+v[k].votoMate;
        mediaInfo=mediaInfo+v[k].votoInfo;
        mediaIta=mediaIta+v[k].votoIta;
    }
    mediaMate=mediaMate/n;
    mediaInfo=mediaInfo/n;
    mediaIta=mediaIta/n;

    if( mediaMate>mediaInfo && mediaMate>mediaIta){
        printf("la media piu alta della classe e' quella di matematica");
        }

    if( mediaMate<mediaInfo && mediaInfo>mediaIta){
        printf("la media piu alta della classe e' quella di informatica");}

     if(mediaIta>mediaMate && mediaIta>mediaInfo){
        printf("la media piu alta della classe e' quella di italiano");
        }
}

int main() {

    studente classe[NClass];

    inserisciDati(classe,NClass);
    media(classe,NClass);

    return 0;
}

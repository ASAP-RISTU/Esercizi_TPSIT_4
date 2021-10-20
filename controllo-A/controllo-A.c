#include <stdio.h>
#include <stdlib.h>
#define LUNG 100
#include <stdbool.h>

bool controllo(char v[]) {
    int k=0;    //contatore e indice
    bool ok=false;
    char trovare= 'A';  //carattere da trovare

    while(ok==false && k<10 && v[k]!='\n') {   // while che guarda che ok==false , che si guardino solo i primi 10 caratteri e se la stringa finisce prima si ferma il ciclo
        if(*(v+k)==trovare) {
            ok=true;        //se il carattere == trovare la variabile ok diventa true
        } else {
            k++;        // senno si incremneta il contatore
        }
    }
    return ok;

}

int main() {
    char stringa[LUNG];

    printf("inserisci stringa: "),
    scanf("%s",stringa);

    bool verifica;
    verifica=controllo(stringa);
    if(verifica==true)
        printf("nella stringa e' presente A nei primi 10 caratteri");
    else
     printf("nella stringa non e' presente A nei primi 10 caratteri");

    return 0;
}

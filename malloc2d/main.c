//Chiedere il numero di colonne e righe di una matrice e caricarla di numeri interi
//Davide Ristorto 4/11/2021

#include <stdio.h>
#include <stdlib.h>
#define NC 10
#define NR 10

void inserisciNum(int mat[][NC]) {
    int x,y;
    do {
        printf("metti cordinate x : ");         //chiede di inserire numeri finche non si inserisce 0
        scanf("%d",&x);
        printf("metti cordinate y : ");
        scanf("%d",&y);
        printf("numero da mettere: ");
        scanf("%d",&mat[y][x]);

    } while(mat[y][x]!=0);
}


int main() {

    int nr, nc;
    int i=0;
    printf("metti num colonne: ");      //chiedo num righe e colonne
    scanf("%d",&nc);
    printf("metti num righe: ");
    scanf("%d",&nr);

    int **mat = (int **)malloc(nr * sizeof(int*));   //allocazione puntatore di puntatori
    for(i=0; i<nr; i++) {
        mat[i] = (int*)malloc(nc * sizeof(int));
    }

    for(i=0; i<nr; i++) {
        for(int k=0; k<nc; k++) {
            mat[i][k]=0;
        }
    }
    for(i=0; i<nr; i++) {           //stampa
        for(int k=0; k<nc; k++) {
            printf("%d ",mat[i][k]);
        }
        printf("\n");
    }
    inserisciNum(mat);  //carica la matrie

    for(i=0; i<nr; i++) {
        for(int k=0; k<nc; k++) {
            printf("%d ",mat[i][k]);
        }
        printf("\n");
    }
    return 0;
}

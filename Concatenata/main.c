#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LUNG1 10
#define LUNG2 50

//Concatenare due stringhe senza strcat

void unisci(char *str1, char *str2)
{
    int n1=strlen(str1); //determinare lunghezza stringhe
    int n2=strlen(str2);
    for(int k=0; k< n2; k++)
    {
        *(str1+n1+k)= *(str2+k);
    }
    *(str1+n1+n2)='\0';  //ultimo carattere della stringa viene settato a \0
}

int main()
{

    char * str1= (char *) malloc(LUNG2 * sizeof(char)); //crea vettore caratteri di lunghezza LUNG
    char * str2= (char *) malloc(LUNG1 * sizeof(char));
    printf("prima stringa: ");
    scanf("%s", str1);
    printf("seconda stringa: ");
    scanf("%s", str2);
    unisci(str1, str2); //la stringa str1 viene modificata e unita alla seconda
    printf("stringa unita: %s", str1);

    return 0;
}

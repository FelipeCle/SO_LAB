#include<stdio.h>
#include<string.h>

int main(){
    char nomes[2][20]; // 2 Nomes , máximo de 20 caractreres.
    char temp [20];
    printf("Primeiro nome : ");
    scanf("%s",nomes[0]);
    printf("Segundo nome :");
    scanf("%s",nomes[1]);
    printf("\nNomes:\n");
    for (int i=0;i<2;i++){
        printf("%s\n",nomes[i]);
    }
    for(int j =0 ; j<1 ; j++){
        for (int k = j+1;k<2;k++){
            if (strcmp(nomes[j],nomes[k])>0){
                strcpy(temp,nomes[j]);
                strcpy(nomes[j],nomes[k]);
                strcpy(nomes[k],temp);
            }
        }

    }
    printf("Em ordem alfabética:\n");
    for(int i=0;i<2;i++){
        printf("%s\n",nomes[i]);
    }

    return 0;
}

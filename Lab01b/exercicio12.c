#include<stdio.h>
#include<string.h>

int main(){
    char string[20];
    char caractere ; 
    printf("Digite a string : ");
    scanf("%s",string);
    printf("Digite um caractere : ");
    scanf(" %c",&caractere);
    printf("Caractere a ser procurado :%c ",caractere);
    for(int i = 0 ; i <20 ; i++){
        if (caractere == string[i]){
            printf("\nCaractere encontrado na posição : %d\n",i+1);
        }
    }
        return 0;
}
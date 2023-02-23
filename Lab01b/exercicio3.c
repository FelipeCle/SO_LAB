#include <stdio.h>

int main()
{
    int numero;
    int linhas = 0 ;
    do{
        printf("Digite um número impar:");
        scanf("%d",&numero);
    }while(numero%2==0);
    for(int i = 1 ; i <=numero ; i++){
        for(int k=0;k<linhas;k++){
            printf(" ");
            
        }
        printf("%d ", i);
        for (int j = i + 1;j<=numero;j++){
            printf("%d ", j);
            
        }
        numero --;
        printf("\n");
        linhas +=2;
    }

    return 0;
}
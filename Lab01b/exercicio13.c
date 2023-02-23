#include <stdio.h>
#include <string.h>

int main()
{
    int i ;
    char str[100];
    printf("Digite uma string : ");
    scanf("%s",str);
    printf("Digite o índice do caracter que deseja remover :");
    scanf("%d",&i);
    strcpy(&str[i], &str[i + 1]);
    printf("%s\n", str);
}
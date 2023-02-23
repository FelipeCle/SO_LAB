#include <stdio.h>
#include <string.h>

int main()
{
    int i ;
    char str[100];
    char str1[100];
    char ch;
    printf("Digite uma string : ");
    scanf("%s",str);
    printf("Digite o índice onde o caracter deve ser inserido :");
    scanf("%d",&i);
    printf("Digite o caracter a ser inserido :");
    scanf(" %c",&ch);
    str1[i] = ch;
    for(int i = 0; i < 100; ) {
    char temp = str[i++];
    str1[i] = temp;
  }
    printf("%s", str1);    
    
}
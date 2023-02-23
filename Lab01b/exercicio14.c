#include <stdio.h>
#include <string.h>

int main()
{
    int i ;
    char str[100];
    char ch;
    printf("Digite uma string : ");
    scanf("%s",str);
    printf("Digite o índice onde o caracter deve ser inserido :");
    scanf("%d",&i);
    printf("Digite o caracter a ser inserido :");
    scanf(" %c",&ch);
    for (int j = 0 ; j<100 ; j++){
      if (str[j] == str[i]){
        str[j]= ch;
      }
    }
    printf("%s", str);    
    
}
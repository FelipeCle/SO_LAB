#include <stdio.h>

int main()
{
    float nota1 , nota2 , nota3, media_exercicios;
    float media_aproveitamento;
    printf("Primeira nota:");
    scanf("%f",&nota1);
    printf("Segunda nota:");
    scanf("%f",&nota2);
    printf("Terceira nota:");
    scanf("%f",&nota3);
    printf("Média das notas dos exercícios:");
    scanf("%f",&media_exercicios);
    media_aproveitamento = (nota1 + nota2*2 + nota3*3+media_exercicios)/7;
    printf("Media aproveitamento:%f",media_aproveitamento);
    if (media_aproveitamento>=9){
        printf("\nA");
    }else if((media_aproveitamento>=7.5)&&(media_aproveitamento<9)){
        printf("\nB");
    }else if((media_aproveitamento>=6)&&(media_aproveitamento<7.5)){
        printf("\nC");
    }else if((media_aproveitamento>=4)&&(media_aproveitamento<6)){
        printf("\nD");
    }else if(media_aproveitamento<4){
        printf("\nE");
    }

    return 0;
}
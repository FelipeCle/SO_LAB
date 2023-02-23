#include<stdio.h>
#include<string.h>


typedef struct{
    char Nome[20];
    int idade;
    float peso;
    float altura;
}Pessoa;

int main(){
    Pessoa pessoas[3]; // Considerando um máximo de 3 pessoas.
    for (int i=0 ; i<3 ; i++){
        printf("Nome da pessoa %d:",i+1);
        scanf("%s",pessoas[i].Nome);
    }
    //Setando dados aleatórios para teste do programa.
    pessoas[0].idade = 18 ;
    pessoas[0].peso = 80 ;
    pessoas[0].altura = 1.90;
    pessoas[1].idade = 15 ;
    pessoas[1].peso = 60 ;
    pessoas[1].altura = 1.7;
    pessoas[2].idade = 58 ;
    pessoas[2].peso = 77 ;
    pessoas[2].altura = 1.78;
    


    for (int i=0 ; i<3; i++){
        printf("\nNome\tIdade\tPeso\tAltura\n");
        printf("%s\t%d\t%.2f\t%.2f",pessoas[i].Nome,pessoas[i].idade,pessoas[i].peso,pessoas[i].altura);
    }
    return 0;
}
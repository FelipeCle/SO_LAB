#include <stdio.h>
#include <stdlib.h>


//Nó inicial da lista encadeada.
struct reg{
    int conteudo;
    struct reg *prox;
};

//Declaração da célula
typedef struct reg celula;

//Função para inserir elementos na lista

void insere(celula **listaEncadeada, int valor){
    celula *novaCelula = (celula *) malloc(sizeof(celula));
    novaCelula->conteudo = valor;
    novaCelula->prox = *listaEncadeada;
    *listaEncadeada = novaCelula;
}


//Função que imprime a lista.
void imprime(celula *listaEncadeada){
    if (listaEncadeada!=NULL){
        printf("%d \n",listaEncadeada->conteudo);
        imprime(listaEncadeada->prox);
    }
}


//Função que calcula a quantidade de memória que a celula ocupa.
int qtdeMemoria(celula *cel){
    int mem = sizeof(*cel);
    return mem;
}



//Função para remover um elemento , liberando memória quando ele é liberado.
void removeElemento(celula **listaEncadeada, int elemento){
    celula *atual = *listaEncadeada;
    celula *anterior = NULL;

    while (atual != NULL && atual->conteudo != elemento) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            *listaEncadeada = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        free(atual);
    }
}


int main() {
    //Criando a lista encadeada
    celula *listaEncadeada = NULL;
    //Criando três instâncias do objeto celula , com a função insere(Valores aleatórios).
    insere(&listaEncadeada, 0);
    insere(&listaEncadeada, 1);
    insere(&listaEncadeada, 2);
    //Função que imprime a lista
    imprime(listaEncadeada);
    //Quantidade de memoria ocupada pela lista.
    printf("Memoria utilizada por esta instância de célula: %d bytes\n", qtdeMemoria(listaEncadeada));
    //Removendo o elemento 2 , ulizando a função
    removeElemento(&listaEncadeada,2);
    imprime(listaEncadeada);
    //Calculando a quantidade máxima de elementos possíveis na lista, com base na memória do pc.
    double mem,memGb,max;
    //Recebe a quantidade de memória do pc
    printf("\nInforme qtdade de Memória disponivel(GB): "); 
    scanf("%lf", &mem);
    //Transforma de gb para bytes
    memGb = mem*1024*1024*1024;
    //Divide de a memoria do pc pela memória ocupada pela lista.
    printf("\nQuantidade máxima de elementos = | %.2lf | ",memGb/qtdeMemoria(listaEncadeada));

}
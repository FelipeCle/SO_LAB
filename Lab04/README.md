<h1 align="center"> Exercícios Lab04</h1>

**Nome dos Integrantes do Grupo:**
```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus Marques - 42130727
```

**Turma 04N11**



> Exercícios em c sobre memória.


**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc [NomeDoArquivo].c -o [NomeDoArquivo].out
```


### **Observação: todas as especificações abaixo aparecem no código e são facilmente identificadas por comentários**


**1. Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista);**
```
insere(&listaEncadeada, 0);
insere(&listaEncadeada, 1);
insere(&listaEncadeada, 2);
```

**2. Construa uma função que imprima todos os valores da lista;**
```
void imprime(celula *listaEncadeada){
    if (listaEncadeada!=NULL){
        printf("%d \n",listaEncadeada->conteudo);
        imprime(listaEncadeada->prox);
    }
}
```

**3. Calcule a quantidade de memória gasta por cada instância da célula;**
```
int qtdeMemoria(celula *cel){
    int mem = sizeof(*cel);
    return mem;
}
```

**4. Construa uma função que remove os elementos da lista;**

**5. Incremente sua função liberando a memória quando um elemento é liberado;**
```
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
```

**6. Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.**
```
double mem,memGb,max;
    //Recebe a quantidade de memória do pc
    printf("\nInforme qtdade de Memória disponivel(GB): "); 
    scanf("%lf", &mem);
    //Transforma de gb para bytes
    memGb = mem*1024*1024*1024;
    //Divide de a memoria do pc pela memória ocupada pela lista.
    printf("\nQuantidade máxima de elementos = | %.2lf | ",memGb/qtdeMemoria(listaEncadeada));
```

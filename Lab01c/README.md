<h1 align="center"> Exercícios Lab01b</h1>

**Nome dos Integrantes do Grupo:**
```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus - 42130727

```
**Turma 04N11**

> Exercícios em C.


**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc exercicio1.c -o exercicio1.out

```

**1) Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO. 
Quantas chamadas de sistemas foram realizadas?**

```
Existem duas chamadas de sistema ao SO no programa:

Linha 8: A chamada de sistema é feita pela função fopen() que é usada para abrir um arquivo para leitura. 
Esta chamada recebe dois argumentos, o nome do arquivo e o modo de abertura.
Linha 19: A chamada de sistema é feita pela função fclose() que é usada para fechar o arquivo aberto anteriormente. 
Esta chamada recebe um argumento que é o ponteiro para o arquivo aberto.

```
**2) Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO. 
Quantas chamadas de sistemas foram realizadas?**

```

Existem duas chamadas de sistema ao SO no programa:

Linha 9: in_file = fopen(argv[1], "r"); - esta chamada de sistema abre um arquivo para leitura.
Linha 15: out_file = fopen(argv[2], "w"); - esta chamada de sistema abre um arquivo para escrita.
Linha 25: fclose(in_file); - esta chamada de sistema fecha o arquivo aberto anteriormente.
Linha 26: fclose(out_file); - esta chamada de sistema fecha o arquivo aberto anteriormente.

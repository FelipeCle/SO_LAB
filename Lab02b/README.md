<h1 align="center"> Exercícios Lab02b</h1>

**Nome dos Integrantes do Grupo:**
```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus Marques - 42130727

```
**Turma 04N11**

> Exercícios em C.


**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc [NomeDoArquivo].c -o [NomeDoArquivo].out

```

**Considere o exemplo fornecido para troca de mensagens entre pai e filho. Altere o programa de modo que a alteração da variável value se reflita no processo pai, ou seja, o último print do programa deve apresentar o seguinte resultado: PARENT: value = 20**


No novo código, o processo pai cria um pipe usando a chamada de sistema "pipe". Ele então cria o processo filho usando a chamada de sistema "fork". O processo filho faz a alteração necessária na variável "value" e escreve o valor atualizado no pipe usando a chamada de sistema "write". O processo pai espera o processo filho usando a chamada de sistema "wait". Em seguida, ele lê o valor atualizado do pipe usando a chamada de sistema "read" e imprime o valor atualizado usando a função "printf".

Com a comunicação interprocesso por meio de pipes, a alteração da variável "value" no processo filho é refletida no processo pai.



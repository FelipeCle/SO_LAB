<h1 align="center"> Projeto 01 </h1>

**Turma 04N11**


> Jantar dos filósofos.



**Nome dos Integrantes do Grupo:**

```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus - 42130727

```

**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc proj1.c -o proj1.out

```

**Explicação do código:**

Este código implementa uma possível solução para o problema do jantar dos filósofos utilizando threads em C. O problema dos filósofos jantando é um exemplo de condição de corrida, que ocorre quando vários processos competem por recursos compartilhados.Os filósofos são tratados como theads e os garfos,recursos.

Neste código os filósofos(threads) vão ser submetidos a um loop infinito , alternando entre os estados de pensar e tentar comer. Na função "comer", o filósofo tenta pegar os garfos da esquerda e da direita. Se ele conseguir pegar ambos, ele come por um período de tempo fixo antes de devolver os garfos à mesa. Caso contrário, ele devolve qualquer garfo que tenha pegado e continua a pensar.

Embora o código funcione, ele não implementa uma solução ideal para o problema dos filósofos jantando, pois pode ocorrer um deadlock, em que cada filósofo pegou o garfo à sua esquerda e está esperando o garfo à sua direita, que está sendo segurado por outro filósofo.

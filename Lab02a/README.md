<h1 align="center"> Exercícios Lab02a</h1>

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
Utilizando o GCC, devemos utilizar o comando no terminal : gcc [NomeDoArquivo].c -o [NomeDoArquivo].out

```

>Exemplos das execuções realizadas para estes programas se encontram nos arquivos ".txt"

**1) 1 Rode o programa anterior para valores grandes de n. As mensagens sempre estarão ordenadas pelo valor de i?**

```
Ao rodar o programa anterior utilizando o stderr como streaming de saída, as mensagens sempre estarão ordenadas pelo valor de "i", mesmo para valores grandes de "n". Isso pode ser confirmado executando o programa para n = 100.

```
**2) O que acontece se o programa anterior escreve-se as mensagens
para sys.stdout, usando print, ao invés de para sys.stderr?**

```
Se o programa anterior escrever as mensagens para sys.stdout usando a função print, em vez de sys.stderr, o "i" não ficará totalmente em ordem todas as vezes, especialmente para valores grandes de "n". Isso ocorre porque a stdout é bufferizada, e isso pode causar problemas na hora de imprimir os dados. Para evitar esse problema, é possível usar a função fflush() para limpar o buffer e garantir que os dados sejam impressos corretamente. É importante ressaltar que, mesmo com o uso da fflush(), ainda pode haver casos em que o "i" não será impresso em ordem total, devido à natureza do buffer e do processo de impressão de dados.


<h1 align="center"> Exercícios Lab03 parte II</h1>

**Nome dos Integrantes do Grupo:**
```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus Marques - 42130727
```

**Turma 04N11**



> Exercícios em c sobre threads.


**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc [NomeDoArquivo].c -o [NomeDoArquivo].out
```

**Explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?**


Ao implementar este código sem a utilização de mutex , os valores de pi possuem algumas incoerências.Estes problemas ocorrem devido a condição de corrida , em que diferentes threads tentam acessar a mesma variável compartilhada de maneira simultânea.


**Implemente uma solução utilizando Mutex e comparece com a anterior. O que mudou? Por quê?**


Ao utilizar mutex , as threads acessam a variável compartilhada de forma sequencial e segura , obtendo-se assim resultados precisos.Ao variar o n , ou os números de threads , os resultados obtidos para esta implementação sempre vão estar corretos.



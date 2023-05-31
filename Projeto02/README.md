<h1 align="center"> Projeto 02 </h1>

**Turma 04N11**


> Contas bancarias.



**Nome dos Integrantes do Grupo:**

```
Victor Junqueira - 42123712
Felipe Cle - 42116082
Matheus - 42130727

```

**Como compilar o programa:**

```
Utilizando o GCC, devemos utilizar o comando no terminal : gcc main.c -o main.out

```

**Reqisitos do projeto:**

**1. A conta to pode receber mais de uma transferência simultânea**

**2. A conta from pode enviar mais de uma transferência simultânea**

Resolvido com a utilização de threads no código , ao chamar a rotina que possui transferências para ambas as contas.
![image](https://github.com/FelipeCle/SO_LAB/assets/94229656/599732bb-b7c3-4d27-92bc-2a7b8ebbb742)

**3. A conta from não pode enviar dinheiro se não tiver mais saldo**

A conta só transfere enquanto possui dinheiro

![image](https://github.com/FelipeCle/SO_LAB/assets/94229656/658c313a-c800-4847-96a8-e0b3220da925)


**4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode**
receber e a conta que recebia pode enviar;

Com as flags ambas as contas podem enviar e receber , onde caso uma deles zere a outra passa a transferir e vice-versa.

![image](https://github.com/FelipeCle/SO_LAB/assets/94229656/294649f1-9dd7-4e2c-a5b0-827f689f965b)


**5. Poderão ser realizadas até 100 transações simultâneas de transferência.**

São utilizadas 100 threads e no loop a rotina é chamada de 0 a 100 vezes.

![image](https://github.com/FelipeCle/SO_LAB/assets/94229656/6733e953-aa67-4359-a224-d4923f4ad140)

![image](https://github.com/FelipeCle/SO_LAB/assets/94229656/1796ff64-8a81-443c-91ba-376468b4d81a)

Também é utilizado uma mutex no código , garantindo a integridade e o funcionamento adequado das threads.




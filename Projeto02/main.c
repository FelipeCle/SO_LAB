#define _GNU_SOURCE
#include <malloc.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define FIBER_STACK 1024 * 64
int flag = 0;
struct c {
  int saldo;
};
typedef struct c conta;
conta from, to;
int valor;
pthread_mutex_t lock;

void *transferencia(void *arg) {
  int rc;
  rc = pthread_mutex_lock(&lock);
  if ((from.saldo >= valor) && (flag == 0)) {
    from.saldo -= valor;
    to.saldo += valor;
    if (from.saldo < 0) {
      to.saldo -= valor;
      from.saldo += valor;
    }

    if (from.saldo == 0) {
      flag = 1;
    }
  }

  if ((to.saldo >= valor) && (flag == 1)) {
    to.saldo -= valor;
    from.saldo += valor;
    if (to.saldo < 0) {
      from.saldo -= valor;
      to.saldo += valor;
    }
    if (to.saldo == 0) {
      flag = 0;
    }
  }

  printf("Transferência concluída com sucesso!\nSaldo de c1: $%d\nSaldo de c2: "
         "$%d\n",
         from.saldo, to.saldo);

  
  rc = pthread_mutex_unlock(&lock);
  return 0;
}

int main() {
  void *stack;
  int i;
  pthread_t threads[100];

  stack = malloc(FIBER_STACK);
  if (stack == NULL) {
    perror("malloc: could not allocate stack");
    exit(EXIT_FAILURE);
  }

  pthread_mutex_init(&lock, NULL);
  from.saldo = 100;
  to.saldo = 100;

  printf("Transferindo 1 para a conta c2\n");
  valor = 50;

  for (i = 0; i < 100; i++) {
    int rc = pthread_create(&threads[i], NULL, transferencia, NULL);
    if (rc != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  for (i = 0; i < 100; i++) {
    int rc = pthread_join(threads[i], NULL);
    if (rc != 0) {
      perror("pthread_join");
      exit(EXIT_FAILURE);
    }
  }

  pthread_mutex_destroy(&lock);
  free(stack);

  printf("Transferências concluídas e memória liberada.\n");

  return 0;
}

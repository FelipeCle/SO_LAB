#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FIBER_STACK 1024 * 64

struct c {
  int saldo;
};

typedef struct c conta;

conta from, to;
int valor;
pthread_mutex_t lock;

void* transferencia(void *arg) {
  int rc;

  rc = pthread_mutex_lock(&lock);
  if (rc != 0) {
    perror("pthread_mutex_lock");
    exit(EXIT_FAILURE);
  }

  if (from.saldo >= valor) {
    from.saldo -= valor;
    to.saldo += valor;
  }

  printf("Transferência concluída com sucesso!\n");
  printf("Saldo de c1: %d\n", from.saldo);
  printf("Saldo de c2: %d\n", to.saldo);

  rc = pthread_mutex_unlock(&lock);
  if (rc != 0) {
    perror("pthread_mutex_unlock");
    exit(EXIT_FAILURE);
  }

  return NULL;
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
  valor = 1;

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

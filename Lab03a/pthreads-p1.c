#include <locale.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n, m; 
int thread_count; 
float *y, **a, *x;

void *pth_math_vect(void *rank) {

  long my_rank = (long)rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  for (i = my_first_row; i <= my_last_row; i++) {
    y[i] = 0.0;
    for (j = 0; j < n; j++) {
      y[i] += a[i][j] * x[j];
    }
  }
  return NULL;
}

int main() {
  int value;
  printf("Digite a quantidade de linhas: ");
  scanf("%d", &n);
  printf("Digite a quantidade de colunas: ");
  scanf("%d", &m);
  printf("\n");
  // Criando o vetor
  x = (float *)malloc(n * sizeof(float));
  
  thread_count = m;
  pthread_t thread[m];
  
  // Criando as matrizes
  a = (float **)malloc(m * sizeof(float *));
  for (int i = 0; i < m; i++) {
    a[i] = (float *)malloc(n * sizeof(float));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("Digite o valor da linha %d e coluna %d da matriz: ", i, j);
      scanf("%f", &a[i][j]);
    }
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("Digite o valor da linha %d do vetor: ", i);
    scanf("%f", &x[i]);
  }

  y = (float *)malloc(n * sizeof(float));

  printf("\nResultados:\n\n");
  for (int i = 0; i < m; i++) {
    pthread_create(&thread[i], NULL, pth_math_vect, i);
  }
  for (int i = 0; i < m; i++) {
    pthread_join(thread[i], NULL);
  }
  
  for (int j = 0; j < n; j++) {
    printf("Linha %d: %f \n", j, y[j]);
  }
  
  free(y);
  return 0;
}

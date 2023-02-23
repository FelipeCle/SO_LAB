#include <stdio.h>

int main(void) {
  int tamanho, nmr, p = 1;
  printf("Digite o tamanho da matriz que voce deseja: ");
  scanf("%d", &tamanho);
  printf("\n");
  int matriz[tamanho][tamanho], matriz2[tamanho][tamanho];
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("Digite o %d numero: ", p);
      scanf("%d", &nmr);
      matriz[i][j] = nmr;
      matriz2[j][i] = nmr;
      p++;
    }
  }
  
  printf("\nSua Matriz: \n");
  for (int i = 0; i < tamanho; i++) {
    printf("\n  ");
    for (int j = 0; j < tamanho; j++) {
      printf(" %d", matriz[i][j]);
    }
  }

  printf("\n\nSua Matriz Transposta: \n");
  for (int i = 0; i < tamanho; i++) {
    printf("\n  ");
    for (int j = 0; j < tamanho; j++) {
      printf(" %d", matriz2[i][j]);
    }
  }
}

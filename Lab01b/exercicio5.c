#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool sair = true;
  int tamanho, nmr, p = 1;
  printf("Digite o tamanho da matriz que você deseja: ");
  scanf("%d", &tamanho);
  printf("\n");
  int matriz[tamanho][tamanho], matriz2[tamanho][tamanho];
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("Digite o %d número: ", p);
      scanf("%d", &nmr);
      matriz[i][j] = nmr;
      matriz2[j][i] = nmr;
      p++;
    }
  }

  printf("\nSua Matriz: ");
  for (int i = 0; i < tamanho; i++) {
    printf("\n\n  ");
    for (int j = 0; j < tamanho; j++) {
      printf("%d   ", matriz[i][j]);
    }
  }

  while (sair == true) {
    int escolha, indice, mult;
    printf("\n\nDigite 3 para sair");
    printf("\n\nDeseja multiplicar uma linha (1) ou uma coluna (2)? ");
    scanf("%d", &escolha);

    if (escolha == 1) {
      printf("\nQual linha voce deseja fazer a multiplicação? ");
      scanf("%d", &indice);
      indice--;
      printf("\nPor quanto voce quer multiplicar? ");
      scanf("%d", &mult);
      if (indice >= tamanho) {
        printf("\nlinha inválida!");
        break;
      }
      for (int i = 0; i < tamanho; i++) {
        matriz[indice][i] = matriz[indice][i] * mult;
      }
    }

    if (escolha == 2) {
      printf("\nQual coluna voce deseja fazer a multiplicação? ");
      scanf("%d", &indice);
      indice--;
      printf("\nPor quanto voce quer multiplicar? ");
      scanf("%d", &mult);
      if (indice >= tamanho) {
        printf("\ncoluna inválida!");
        break;
      }
      for (int i = 0; i < tamanho; i++) {
        matriz[i][indice] = matriz[i][indice] * mult;
      }
    }

    if (escolha == 3) {sair = false;}

    printf("\nSua Matriz: ");
  for (int i = 0; i < tamanho; i++) {
    printf("\n\n  ");
    for (int j = 0; j < tamanho; j++) {
      printf("%d   ", matriz[i][j]);
    }
  }
  }
}
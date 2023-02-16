#include <stdio.h>

#define MAX 100

int main() {
    int matriz[MAX][MAX];
    int n, i, j, menor, linha_menor;

    // lê a dimensão da matriz
    printf("Digite a dimensão da matriz: ");
    scanf("%d", &n);

    // lê os elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // encontra o menor elemento e sua linha
    menor = matriz[0][0];
    linha_menor = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                linha_menor = i;
            }
        }
    }

    // imprime a linha que contém o menor elemento
    printf("A linha que contém o menor elemento é a linha %d\n", linha_menor + 1);

    return 0;
}

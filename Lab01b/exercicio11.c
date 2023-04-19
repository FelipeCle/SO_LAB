#include <stdio.h>

void somMult(int m[][3], int nLin, int nCol, int L1, int L2) {
    int i;
    int som = 0, mult = 1;

    // soma - colocando o resultado na linha L2
    for (i = 0; i < nCol; i++) {
        som += m[L1][i];
        som += m[L2][i];
        m[L2][i] = som;
        som = 0;
    }

    // multiplicacao - colocando o resultado na linha L2
    for (i = 0; i < nCol; i++) {
        mult *= m[L1][i];
        mult *= m[L2][i];
        m[L2][i] = mult;
        mult = 1;
    }
}

int main() {
    int m[3][3] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9} };
    int nLin = 3;
    int nCol = 3;
    int L1 = 0;
    int L2 = 1;

    //matriz original
    printf("Matriz original:\n");
    int i, j;
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // matriz modificada - soma e multiplicacao
    somMult(m, nLin, nCol, L1, L2);
    printf("Matriz modificada:\n");
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}

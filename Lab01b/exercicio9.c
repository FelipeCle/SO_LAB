#include <stdio.h>

void subNeg(int m[][3], int lin, int col) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            if (m[i][j] < 0) {
                m[i][j] = -m[i][j];
            }
        }
    }
}

int main() {
    int m[2][3] = {{1, -2, 3}, {-4, 5, -6}};
    int i, j;
    
    printf("Matriz original:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    subNeg(m, 2, 3);
    
    printf("\nMatriz com números negativos substituídos pelo módulo:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

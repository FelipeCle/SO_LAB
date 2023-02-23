#include <stdio.h>

#define lin 2
#define col 3

void multL(int m[lin][col], int lin, int n) {
    for (int j=0 ;j<col ;j++) {
        m[lin][j] *= n;
    }
}

void multCol(int m[lin][col], int col, int n) {
    for (int i=0 ;i<lin ;i++) {
        m[i][col] *= n;
    }
}

int main() {
    int m[lin][col] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

    printf("Matriz original:\n");
    for (int i=0 ;i<lin ;i++) {
        for (int j = 0; j < col; j++) {
            printf("%d \n", m[i][j]);
          }
      }
  
    multL(m, 2, 4);

    printf("\nNova matriz com linha:\n");
    for (int i=0 ;i<lin ;i++) {
        for (int j=0 ;j<col ;j++) {
            printf("%d \n", m[i][j]);
        }
    }

    multCol(m, 0, 3);

    printf("\nNova matriz com coluna:\n");
    for (int i=0 ;i<lin ;i++) {
        for (int j=0 ;j<col ;j++) {
            printf("%d \n", m[i][j]);
        }
    }

    return 0;
}

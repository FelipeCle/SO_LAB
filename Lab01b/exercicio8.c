#include <stdio.h>

void transposta(int x[][3], int y[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            y[i][j] = x[j][i];
}
 
int main()
{
    int matriz[3][3] = { {1, 5, 1},  // MATRIZ TESTE
                    {8, 7, 3},
                    {9, 8, 0},
                    };
 
    int matriz_transposta[3][3];
    
    printf("Matriz original :\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        printf("%d ", matriz[i][j]);
        printf("\n");
    }
 
    transposta(matriz, matriz_transposta);
 
    printf("Printando a transposta: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        printf("%d ", matriz_transposta[i][j]);
        printf("\n");
    }
 
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> aecb1e8718123fc8e6a3987b86fa2328cc22e128

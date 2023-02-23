#include <stdio.h>

int main()
{
    int matriz[3][3] = { {1, 5, 1},  // MATRIZ TESTE
                    {8, 7, 3},
                    {9, 8, 0},
                    };
                    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        printf("%d ", matriz[i][j]);
        printf("\n");
    }
    int numero;
    printf("Digite o numero para multiplicar:");
    scanf("%d",&numero);
    
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
        matriz[i][j]=matriz[i][j]*numero;
        
            
        }
    }
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        printf("%d ", matriz[i][j]);
        printf("\n");
    }
 
}

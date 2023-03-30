/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   char minhaMatriz[4][4];
    // Inicializar a matriz com alguns valores
    minhaMatriz[0][0] = 'R' ;
    minhaMatriz[0][1] = '*';
    minhaMatriz[0][2] = '*';
    minhaMatriz[0][3] = '*';
    minhaMatriz[1][0] = '*';
    minhaMatriz[1][1] = 'B';
    minhaMatriz[1][2] = '*';
    minhaMatriz[1][3] = '*';
    minhaMatriz[2][0] = '*';
    minhaMatriz[2][1] = '*';
    minhaMatriz[2][2] = '*';
    minhaMatriz[2][3] = '*';
    minhaMatriz[3][0] = '*';
    minhaMatriz[3][1] = '*';
    minhaMatriz[3][2] = '*';
    minhaMatriz[3][3] = '*';
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ",minhaMatriz[i][j]);
        }
        printf("\n"); // Quebra de linha 
    }
    return 0;
}

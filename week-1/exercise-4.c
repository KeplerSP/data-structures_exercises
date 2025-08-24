/*
Construya la tabla de multiplicación de números del 1 al 10 (ej.: 1 x 1 = 1, 1 x 2 = 2, etc.).
*/
#include <stdio.h>

int main()
{
    printf("==== Tabla de multiplicación del 1 al 10 ====\n\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("Tabla del %d:\n", i);
        for (int j = 1; j <= 10; j++)
        {
            printf("%2d x %2d = %3d\n", i, j, i * j);
        }
        printf("\n");
    }

    return 0;
}

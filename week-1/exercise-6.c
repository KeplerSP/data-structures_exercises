/*
Calcule la serie de Fibonacci para un número entero no negativo informado por el usuario.
Ejemplo: si el usuario ingresa el número 9, el resultado sería: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.
*/

#include <stdio.h>

int main()
{
    int n;
    printf("¿Cuántos términos de la serie de Fibonacci quiere ver? ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("El número debe ser no negativo.\n");
        return 1;
    }

    int a = 0, b = 1, temp;

    printf("\nSerie de Fibonacci hasta el término %d:\n", n);

    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            printf("%d", a);
        }
        else
        {
            printf("%d, ", a);
        }

        temp = a + b;
        a = b;
        b = temp;
    }

    printf("\n");

    return 0;
}

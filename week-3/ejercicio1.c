#include <stdio.h>

int factores(int *vector[], int n, int *x)
{
    int cantidad = 0; // Cant. de factores encontrados

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            *vector = i;
            cantidad++;
        }
    }

    *x = cantidad;

    if (cantidad > 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 60; // Número de prueba
    int cantidadFactores;
    int *factoresArray[20]; // Array de tamaño 20 para almacenar los factores (ajusta el tamaño según sea necesario)

    // Llamamos a la función
    int resultado = factores(factoresArray, n, &cantidadFactores);

    // Mostrar los factores encontrados
    printf("Factores de %d: ", n);
    for (int i = 0; i < cantidadFactores; i++)
    {
        printf("%d ", *factoresArray[i]); // Desreferenciamos los punteros para imprimir el valor
    }
    printf("\n");

    // Mostrar la cantidad de factores
    printf("Cantidad de factores encontrados: %d\n", cantidadFactores);

    // Mostrar el resultado basado en la cantidad de factores
    if (resultado == 1)
    {
        printf("El número tiene más de 10 factores.\n");
    }
    else
    {
        printf("El número tiene 10 o menos factores.\n");
    }

    return 0;
}
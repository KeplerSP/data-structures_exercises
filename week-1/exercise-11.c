// Ordene un vector de 100 números enteros generados aleatoriamente.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void imprimirVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ordenarVector(int v[], int tam)
{
    int temp;
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                // Intercambio
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int vector[SIZE];

    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Llenar el vector con números aleatorios entre 0 y 999
    for (int i = 0; i < SIZE; i++)
    {
        vector[i] = rand() % 1000;
    }

    printf("Vector original:\n");
    imprimirVector(vector, SIZE);

    ordenarVector(vector, SIZE);

    printf("\nVector ordenado:\n");
    imprimirVector(vector, SIZE);

    return 0;
}

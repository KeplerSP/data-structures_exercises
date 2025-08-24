/*
Cree dos vectores de 50 posiciones con valores enteros aleatorios, ordene cada uno individualmente
y combínalos en un nuevo vector de 100 posiciones ya ordenado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 50
#define SIZE2 50
#define TOTAL_SIZE (SIZE1 + SIZE2)

// Función para imprimir un vector
void imprimirVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Función para comparar enteros (para qsort)
int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Función para fusionar dos vectores ordenados
void fusionarVectores(int v1[], int v2[], int combinado[])
{
    int i = 0, j = 0, k = 0;

    while (i < SIZE1 && j < SIZE2)
    {
        if (v1[i] < v2[j])
        {
            combinado[k++] = v1[i++];
        }
        else
        {
            combinado[k++] = v2[j++];
        }
    }

    // Agrega el resto del vector 1 (si queda)
    while (i < SIZE1)
    {
        combinado[k++] = v1[i++];
    }

    // Agrega el resto del vector 2 (si queda)
    while (j < SIZE2)
    {
        combinado[k++] = v2[j++];
    }
}

int main()
{
    int vector1[SIZE1], vector2[SIZE2], combinado[TOTAL_SIZE];

    srand(time(NULL)); // Inicializa la semilla aleatoria

    // Rellenar los vectores con números aleatorios (0-999)
    for (int i = 0; i < SIZE1; i++)
    {
        vector1[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE2; i++)
    {
        vector2[i] = rand() % 1000;
    }

    // Ordenar ambos vectores individualmente
    qsort(vector1, SIZE1, sizeof(int), comparar);
    qsort(vector2, SIZE2, sizeof(int), comparar);

    // Fusionar los vectores ordenados en uno nuevo también ordenado
    fusionarVectores(vector1, vector2, combinado);

    // Mostrar resultados
    printf("Vector 1 ordenado:\n");
    imprimirVector(vector1, SIZE1);

    printf("\nVector 2 ordenado:\n");
    imprimirVector(vector2, SIZE2);

    printf("\nVector combinado ordenado:\n");
    imprimirVector(combinado, TOTAL_SIZE);

    return 0;
}

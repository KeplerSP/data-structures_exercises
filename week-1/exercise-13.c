
/*
Haga un método que calcule el promedio de un alumno según el criterio del
curso y otro que indique el estado del alumno:
- Nota superior a 6-9 Aprobado
- Nota entre 4 y 6 —+ Verificación Suplementaria
- Nota inferior a 4 —+ Reprobado
*/
#include <stdio.h>
#include <stdlib.h>

// Calcula el promedio de un arreglo dinámico de notas
float calcularPromedio(float *notas, int cantidad)
{
    float suma = 0.0;
    for (int i = 0; i < cantidad; i++)
    {
        suma += notas[i];
    }
    return suma / cantidad;
}

// Muestra el estado del alumno según el promedio
void mostrarEstado(float promedio)
{
    if (promedio > 6.0)
    {
        printf("-> Aprobado\n");
    }
    else if (promedio >= 4.0)
    {
        printf("-> Verificación Suplementaria\n");
    }
    else
    {
        printf("-> Reprobado\n");
    }
}

int main()
{
    int cantidadNotas;
    printf("Ingrese la cantidad de notas del alumno: ");
    scanf("%d", &cantidadNotas);

    float *notas = calloc(cantidadNotas, sizeof(float));
    if (notas == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Ingreso de notas
    for (int i = 0; i < cantidadNotas; i++)
    {
        printf("Ingrese la nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    float promedio = calcularPromedio(notas, cantidadNotas);
    printf("\nPromedio: %.2f\n", promedio);
    mostrarEstado(promedio);

    // Liberar la memoria reservada
    free(notas);

    return 0;
}

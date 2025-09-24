#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Elaborar un programa para calcular el promedio de calificaciones de un estudiante.
Los datos disponibles son el nombre y las cuatro calificaciones de los exámenes.
La información requerida es el Nombre y las calificaciones.
La calificación final es obtenida al multiplicar las calificaciones 1, 2, 3 y 4
por los porcentajes 30%, 20%, 10% y 40%, respectivamente, y sumando los productos.
*/

float calcular_promedio(float c1, float c2, float c3, float c4)
{
    return c1 * 0.30f + c2 * 0.20f + c3 * 0.10f + c4 * 0.40f;
}

int main()
{
    char nombre[50];
    float cal1, cal2, cal3, cal4, promedio;
    int opcion;

    while (1)
    {
        printf("\n¿Qué desea hacer?:\n");
        printf("1. Calcular promedio\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %d", &opcion);
        getchar();

        if (opcion == 0)
        {
            printf("Saliendo del programa...\n");
            break;
        }
        else if (opcion == 1)
        {
            printf("Ingrese el nombre del estudiante: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = 0; // Eliminar salto de línea

            printf("Ingrese la calificación 1 (30%%): ");
            scanf("%f", &cal1);
            printf("Ingrese la calificación 2 (20%%): ");
            scanf("%f", &cal2);
            printf("Ingrese la calificación 3 (10%%): ");
            scanf("%f", &cal3);
            printf("Ingrese la calificación 4 (40%%): ");
            scanf("%f", &cal4);
            getchar();

            promedio = calcular_promedio(cal1, cal2, cal3, cal4);

            printf("\nNombre: %s\n", nombre);
            printf("Calificaciones: %.2f, %.2f, %.2f, %.2f\n", cal1, cal2, cal3, cal4);
            printf("Promedio final: %.2f\n", promedio);
        }
        else
        {
            printf("Opción inválida, intente de nuevo.\n");
        }
    }

    return 0;
}

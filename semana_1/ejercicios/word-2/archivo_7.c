#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// La velocidad de la luz es de 300,000 kilómetros por segundo. Elaborar un programa
// que lea un tiempo en segundos e imprima la distancia que recorre en dicho tiempo.

float calcular_distancia(float tiempo)
{
    float velocidad_luz = 300000.0f;
    return velocidad_luz * tiempo;
}

int main()
{
    float tiempo, distancia;
    int opcion;

    while (1)
    {
        printf("\n1. Calcular distancia recorrida por la luz\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 0)
        {
            printf("Saliendo del programa...\n");
            break;
        }
        else if (opcion == 1)
        {
            printf("Ingrese el tiempo en segundos: ");
            scanf("%f", &tiempo);

            distancia = calcular_distancia(tiempo);

            printf("La luz recorre %.2f km en %.2f segundos.\n", distancia, tiempo);
        }
        else
        {
            printf("Opción inválida. Intente nuevamente.\n");
        }
    }

    return 0;
}

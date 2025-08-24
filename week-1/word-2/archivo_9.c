#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Una temperatura en grados Centígrados (C) se puede convertir a su equivalente en Fahrenheit (F) con la fórmula:
F = (9/5) C + 32
Y de Fahrenheit a Centígrados con la fórmula: C = (F - 32)(5/9)
Elaborar un programa que lea una temperatura en grados centígrados y obtenga e
imprima la temperatura Fahrenheit equivalente.
*/

int main()
{
    int opcion;
    float celsius, fahrenheit;

    printf("Conversión de Temperaturas\n");
    printf("1. Centígrados a Fahrenheit\n");
    printf("2. Fahrenheit a Centígrados\n");
    printf("Seleccione una opción (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        // Convertir de Centígrados a Fahrenheit
        printf("Ingrese la temperatura en grados Centígrados: ");
        scanf("%f", &celsius);
        fahrenheit = (9.0 / 5.0) * celsius + 32;
        printf("Equivalente en Fahrenheit: %.2f°F\n", fahrenheit);
    }
    else if (opcion == 2)
    {
        // Convertir de Fahrenheit a Centígrados
        printf("Ingrese la temperatura en grados Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * (5.0 / 9.0);
        printf("Equivalente en Centígrados: %.2f°C\n", celsius);
    }
    else
    {
        printf("Opción no válida. Por favor seleccione 1 o 2.\n");
    }

    return 0;
}

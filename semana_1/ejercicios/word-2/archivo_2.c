#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
La famosa ecuación de Einstein para la conversión de una masa m en energía viene dada por la fórmula:
E=mc^2, donde c es la velocidad de la luz y su valor es: c=2.99792458x1010 cm/sg.
Elaborar un programa que lea una masa en gramos y obtenga la cantidad de energía producida
cuando la masa se convierte en energía.
Nota: Si la masa se da en gramos, la fórmula produce la energía en ergios.
*/

int main()
{
    double masa, energia;
    const double c = 2.99792458e10;

    printf("Ingrese la masa (en g): ");
    scanf("%lf", &masa);

    if (masa < 0)
    {
        printf("La masa no puede ser negativa.\n");
        return 1;
    }

    energia = masa * c * c;

    printf("La energía equivalente es: %.5e ergios\n", energia);

    return 0;
}

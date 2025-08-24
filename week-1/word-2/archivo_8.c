#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Hacer un programa que obtenga e imprima el valor de Y a partir de la ecuación:
Y = 3X^2 + 7X - 15
solicitando como dato de entrada el valor de X.
*/

int main()
{
    float x, y;

    printf("Sea la ecuación: Y = 3X^2 + 7X - 15");
    printf("\nIngrese el valor de X: ");
    scanf("%f", &x);

    y = (3 * x * x) + (7 * x) - 15;

    printf("El valor de Y es: %.2f\n", y);

    return 0;
}

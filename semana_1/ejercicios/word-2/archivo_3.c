#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
Elaborar un programa para convertir una medida dada en pies a sus equivalentes en:
a) yardas; b) pulgadas) centímetros, y d) metros;
donde (1 pie = 12 pulgadas, 1 yarda = 3 pies, 1 pulgada = 2,54 cm, 1m = 100 cm).
Leer el número de pies y mostrar por pantalla el número de yardas, pies, pulgadas, centímetros y metros.
*/

int main()
{
    float pies, yardas, pulgadas, centimetros, metros;

    printf("Ingrese la cantidad en pies: ");
    scanf("%f", &pies);

    yardas = pies / 3.0;
    pulgadas = pies * 12.0;
    centimetros = pulgadas * 2.54;
    metros = centimetros / 100.0;

    printf("\nEquivalencias:\n");
    printf("Yardas:      %.2f\n", yardas);
    printf("Pies:        %.2f\n", pies);
    printf("Pulgadas:    %.2f\n", pulgadas);
    printf("Centímetros: %.2f\n", centimetros);
    printf("Metros:      %.2f\n", metros);

    return 0;
}

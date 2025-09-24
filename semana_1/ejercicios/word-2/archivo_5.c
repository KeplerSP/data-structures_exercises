#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Elaborar un programa que calcule e imprima el costo de un terreno cuadrado o rectangular,
teniendo como datos la anchura y la longitud en metros, y el costo del metro cuadrado.
*/

int main()
{
    float ancho, largo, costo_m2, area, costo_total;

    printf("Ingrese el ancho del terreno (en m): ");
    scanf("%f", &ancho);

    printf("Ingrese el largo del terreno (en m): ");
    scanf("%f", &largo);

    printf("Ingrese el costo por metro cuadrado: ");
    scanf("%f", &costo_m2);

    area = ancho * largo;
    costo_total = area * costo_m2;

    printf("\nÁrea del terreno: %.2f m^2\n", area);
    printf("Costo total del terreno: %.2f\n", costo_total);

    return 0;
}

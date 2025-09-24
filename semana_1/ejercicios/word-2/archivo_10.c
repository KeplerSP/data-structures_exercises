#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Elaborar un programa que lea el artículo y su costo: la utilidad es el 150% y el impuesto es el 19%;
calcular e imprimir el artículo, la utilidad, el impuesto y precio de venta.
*/

int main()
{
    char articulo[50];
    float costo, utilidad, impuesto, precio_venta;

    printf("Ingrese el nombre del artículo: ");
    fgets(articulo, sizeof(articulo), stdin);

    articulo[strcspn(articulo, "\n")] = 0; // Elimina el salto de línea que fgets guarda

    printf("Ingrese el costo del artículo: ");
    scanf("%f", &costo);

    utilidad = costo * 1.5;

    impuesto = costo * 0.19;

    precio_venta = costo + utilidad + impuesto;

    printf("\n--- Detalles del artículo ---\n");
    printf("Artículo: %s\n", articulo);
    printf("Costo: $%.2f\n", costo);
    printf("Utilidad (150%%): $%.2f\n", utilidad);
    printf("Impuesto (19%%): $%.2f\n", impuesto);
    printf("Precio de venta: $%.2f\n", precio_venta);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Elabore un programa que calcule e imprima el costo de producción de un artículo,
teniendo como datos: la descripción y el número de unidades producidas.
El costo se calcula multiplicando el número de unidades producidas por un factor de costo
de materiales de 3.5 y sumándole al producto un costo fijo de 10000.
*/

float calcularCostoTotal(int unidades)
{
    float factor_costo_materiales = 3.5f;
    // float costo_fijo = 10000.0f;
    return (unidades * factor_costo_materiales) + 10000.0f;
}

int main()
{
    char descripcion[100];
    int unidades;
    float costo_total, costo_materiales, costo_fijo = 10000.0f;

    printf("Ingrese la descripción del artículo: ");
    fgets(descripcion, sizeof(descripcion), stdin); // permite leer espacios, a diferencia de scanf

    printf("Ingrese el número de unidades producidas: ");
    scanf("%d", &unidades);

    costo_total = calcularCostoTotal(unidades);
    costo_materiales = unidades * 3.5f;

    printf("\n--- Detalles de Producción ---\n");
    printf("Descripción: %s", descripcion);
    printf("Unidades producidas: %d\n", unidades);
    printf("Costo por materiales: %.2f\n", costo_materiales);
    printf("Costo fijo: %.2f\n", costo_fijo);
    printf("Costo total de producción: %.2f\n", costo_total);

    return 0;
}

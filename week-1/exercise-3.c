/*
Para cada producto informado (nombre, precio y cantidad), escriba el nombre
del producto comprado y el valor total a pagar, considerando que se ofrecen
descuentos según el número de unidades compradas:
- Hasta 10 unidades: valor total
- De 11 a 20 unidades: 10% de descuento
- De 21 a 50 unidades: 20% de descuento
- Más de 50 unidades: 25% de descuento.
*/
#include <stdio.h>

typedef struct
{
    char nombre[50];
    float precio;
} Producto;

float calcularDescuento(int cantidad, float total)
{
    if (cantidad <= 10)
        return total;
    else if (cantidad <= 20)
        return total * 0.9;
    else if (cantidad <= 50)
        return total * 0.8;
    else
        return total * 0.75;
}

int main()
{
    Producto productos[3] = {
        {"Yogurt", 3.5},
        {"Pescado", 7.0},
        {"Queso", 5.5}};

    printf("Productos Disponibles:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s - %.2f\n", (i + 1), productos[i].nombre, productos[i].precio);
    }

    int opcion, cantidad;
    printf("\nSeleccione un producto (1-3): ");
    scanf("%d", &opcion);

    printf("Ingrese la cantidad a comprar: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0)
    {
        printf("Cantidad inválida.\n");
        return 1;
    }

    Producto seleccionado;
    float totalSinDescuento, totalConDescuento;

    switch (opcion)
    {
    case 1:
    case 2:
    case 3:
        seleccionado = productos[opcion - 1];
        totalSinDescuento = seleccionado.precio * cantidad;
        totalConDescuento = calcularDescuento(cantidad, totalSinDescuento);

        printf("\nProducto: %s\n", seleccionado.nombre);
        printf("Cantidad: %d\n", cantidad);
        printf("Precio unitario: %.2f\n", seleccionado.precio);
        printf("Total sin descuento: %.2f\n", totalSinDescuento);
        printf("Total con descuento: %.2f\n", totalConDescuento);
        break;

    default:
        printf("Opción inválida.\n");
        return 1;
    }

    return 0;
}

/*
Calcule el retorno de una inversión financiera mes a mes, sin usar la fórmula de interés compuesto.
1. El usuario debe informar cuánto invertirá cada mes y cuál será la tasa de interés mensual.
2. El programa debe mostrar el saldo tras un año y preguntar si desea calcular el siguiente año.
Ejemplo: Inversión mensual = R$100,00, tasa de interés = 1% mensual.
Salida: Saldo tras 1 año: 1280.9328043328942
¿Desea procesar un año más? (S/N)
*/

#include <stdio.h>

int main()
{
    float inversion_mensual, tasa_interes, saldo = 0;
    char opcion;

    printf("Ingrese la inversión mensual: ");
    scanf("%f", &inversion_mensual);

    printf("Ingrese la tasa de interés mensual (en %): ");
    scanf("%f", &tasa_interes);

    // Pasamos la tasa de % a decimal
    tasa_interes = tasa_interes / 100;

    int anio = 1;

    do
    {
        for (int mes = 1; mes <= 12; mes++)
        {
            // Añadimos la inversión mensual a nuestro saldo
            saldo += inversion_mensual;

            // Aplicamos el interés al saldo total
            saldo += saldo * tasa_interes;
        }

        printf("Saldo tras %d año(s): %.10f\n", anio, saldo);

        printf("¿Desea procesar un año más? (S/N): ");
        scanf(" %c", &opcion);

        anio++;

    } while (opcion == 'S' || opcion == 's');

    return 0;
}

/*
Calcule la raíz cuadrada aproximada de un número entero informado por el usuario,
respetando un error máximo también informado. No utilice funciones predefinidas.
*/
#include <stdio.h>

float newton_sqrt(float numero, int iteraciones)
{
    // Casos especiales
    if (numero < 0)
    {
        printf("Error: No se puede calcular la raíz cuadrada de un número negativo\n");
        return -1;
    }

    if (numero == 0)
    {
        return 0;
    }

    // Aproximación inicial: la mitad del número
    float x = numero / 2.0f;

    // Aplicamos la fórmula de Newton las veces indicadas
    for (int i = 0; i < iteraciones; i++)
    {
        x = (x + numero / x) / 2.0f;
    }

    return x;
}

int main()
{
    float numero;
    int iteraciones;

    printf("=== CALCULADORA DE RAÍZ CUADRADA (Método de Newton) ===\n\n");

    printf("Ingresa el número: ");
    scanf("%f", &numero);

    printf("Ingresa el número de iteraciones (precisión): ");
    scanf("%d", &iteraciones);

    if (iteraciones <= 0)
    {
        printf("Error: El número de iteraciones debe ser mayor que 0\n");
        return 1;
    }

    float resultado = newton_sqrt(numero, iteraciones);

    if (resultado >= 0)
    {
        printf("\nResultado:\n");
        printf("La raíz cuadrada de %.6f es: %.6f\n", numero, resultado);
    }

    return 0;
}
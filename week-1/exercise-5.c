// Determine el número de dígitos de un número ingresado.

#include <stdio.h>

int main()
{
    int num_original, numero, contador = 0;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    num_original = numero;

    if (numero == 0)
    {
        contador = 1;
    }
    else
    {
        if (numero < 0)
        {
            numero *= -1;
        }

        while (numero > 0)
        {
            numero = numero / 10;
            contador++;
        }
    }

    printf("El número %d tiene %d dígitos.\n", num_original, contador);

    return 0;
}

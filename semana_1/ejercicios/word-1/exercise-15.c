/*
Lea un número decimal (hasta 3 dígitos) y muestre su equivalente en números romanos.
Use métodos para convertir cada dígito.
Pistas: 1=I, 5=V, 10=X, 50=L, 100=C, 500=D, 1000=M.
*/

#include <stdio.h>

// Convierte el dígito de las centenas a romano
void convertirCentenas(int n)
{
    switch (n)
    {
    case 1:
        printf("C");
        break;
    case 2:
        printf("CC");
        break;
    case 3:
        printf("CCC");
        break;
    case 4:
        printf("CD");
        break;
    case 5:
        printf("D");
        break;
    case 6:
        printf("DC");
        break;
    case 7:
        printf("DCC");
        break;
    case 8:
        printf("DCCC");
        break;
    case 9:
        printf("CM");
        break;
    }
}

// Convierte el dígito de las decenas a romano
void convertirDecenas(int n)
{
    switch (n)
    {
    case 1:
        printf("X");
        break;
    case 2:
        printf("XX");
        break;
    case 3:
        printf("XXX");
        break;
    case 4:
        printf("XL");
        break;
    case 5:
        printf("L");
        break;
    case 6:
        printf("LX");
        break;
    case 7:
        printf("LXX");
        break;
    case 8:
        printf("LXXX");
        break;
    case 9:
        printf("XC");
        break;
    }
}

// Convierte el dígito de las unidades a romano
void convertirUnidades(int n)
{
    switch (n)
    {
    case 1:
        printf("I");
        break;
    case 2:
        printf("II");
        break;
    case 3:
        printf("III");
        break;
    case 4:
        printf("IV");
        break;
    case 5:
        printf("V");
        break;
    case 6:
        printf("VI");
        break;
    case 7:
        printf("VII");
        break;
    case 8:
        printf("VIII");
        break;
    case 9:
        printf("IX");
        break;
    }
}

int main()
{
    int numero;

    printf("Ingrese un número decimal (0-999): ");
    scanf("%d", &numero);

    if (numero < 0 || numero > 999)
    {
        printf("Número fuera de rango.\n");
        return 1;
    }

    if (numero == 0)
    {
        printf("No hay representación romana para 0.\n");
        return 0;
    }

    int centenas = numero / 100;
    int decenas = (numero % 100) / 10;
    int unidades = numero % 10;

    convertirCentenas(centenas);
    convertirDecenas(decenas);
    convertirUnidades(unidades);

    printf("\n");

    return 0;
}

/*
Escriba un número por extenso aceptando números de hasta 9 dígitos, usando métodos
y vectores de cadenas (ejemplo: unidades = {“cero”, “uno”, “dos”, ..., “nueve”}).
*/

#include <stdio.h>
#include <string.h>

// Vectores para números básicos
const char *unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
const char *especiales[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
const char *decenas[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
const char *centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

// Función que convierte un número de 0 a 999 a texto
void convertirGrupo(int n, char *resultado)
{
    resultado[0] = '\0'; // limpiar resultado

    if (n == 0)
    {
        strcat(resultado, "cero");
        return;
    }

    if (n == 100)
    {
        strcat(resultado, "cien");
        return;
    }

    int c = n / 100;        // Obtener las centenas
    int d = (n % 100) / 10; // Obtener las decenas
    int u = n % 10;         // Obtener las unidades

    if (c > 0)
    {
        strcat(resultado, centenas[c]);
        strcat(resultado, " ");
    }

    if (d == 1)
    {
        strcat(resultado, especiales[u]);
    }
    else if (d == 2 && u > 0)
    {
        strcat(resultado, "veinti");
        strcat(resultado, unidades[u]);
    }
    else
    {
        if (d > 2)
        {
            strcat(resultado, decenas[d]);
            if (u > 0)
                strcat(resultado, " y ");
        }
        if (d != 1 && u > 0)
        {
            strcat(resultado, unidades[u]);
        }
    }
}

// Función para convertir todo el número (hasta 999,999,999)
void convertirNumero(long n, char *resultado)
{
    resultado[0] = '\0';

    if (n == 0)
    {
        strcat(resultado, "cero");
        return;
    }

    int millones = n / 1000000;       // separar en millones
    int miles = (n % 1000000) / 1000; // separar en miles
    int centenas = n % 1000;          // separar en centenas

    char textoGrupo[100];

    // Millones
    if (millones > 0)
    {
        convertirGrupo(millones, textoGrupo);
        strcat(resultado, textoGrupo);
        if (millones == 1)
            strcat(resultado, " millón ");
        else
            strcat(resultado, " millones ");
    }

    // Miles
    if (miles > 0)
    {
        if (miles == 1)
            strcat(resultado, "mil ");
        else
        {
            convertirGrupo(miles, textoGrupo);
            strcat(resultado, textoGrupo);
            strcat(resultado, " mil ");
        }
    }

    // Centenas
    if (centenas > 0)
    {
        convertirGrupo(centenas, textoGrupo);
        strcat(resultado, textoGrupo);
    }
}

int main()
{
    long numero;
    char resultado[500];

    printf("Ingrese un número (0 a 999999999): ");
    scanf("%ld", &numero);

    if (numero < 0 || numero > 999999999)
    {
        printf("Número fuera de rango.\n");
        return 1;
    }

    convertirNumero(numero, resultado);

    printf("Número por extenso:\n%s\n", resultado);

    return 0;
}

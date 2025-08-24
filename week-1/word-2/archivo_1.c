#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
La fuerza de atracción entre dos masas, ml y m2 separadas por una distancia d, está dada por la fórmula:
F = (G*m1*m2) / d^2
Donde G es la constante de gravitación universal, G=6.673x10-8 cm3/g.seg2
Elaborar un programa que lea la masa de dos cuerpos y la distancia entre ellos y, a continuación,
obtenga la fuerza gravitacional entre ella. La salida debe ser en dinas; una dina es igual a gr.cm/seg2
*/

int main()
{
    double m1, m2, d, F;
    const double G = 6.673e-8; // Constante de gravitación universal en cm^3/(g*seg^2)

    // Entrada de datos
    printf("Ingrese la masa del primer cuerpo (g): ");
    scanf("%lf", &m1);

    printf("Ingrese la masa del segundo cuerpo (g): ");
    scanf("%lf", &m2);

    printf("Ingrese la distancia entre los cuerpos (cm): ");
    scanf("%lf", &d);

    if (d == 0)
    {
        printf("La distancia no puede ser cero.\n");
        return 1;
    }

    F = (G * m1 * m2) / (d * d);

    // Salida de resultados
    printf("La fuerza de atracción gravitacional entre las masas es: %.10e dinas\n", F);

    return 0;
}

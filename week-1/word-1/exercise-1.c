/*
Determine las raíces de una ecuación de 2º grado: ax² + bx + c = 0
(recordar que el discriminante Δ = b² – 4ac, y que la raíz r = (–b ± √Δ)/2a).
*/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float discri, raiz1, raiz2;

    printf("Sea la ecuacion: ax^2 + bx + c = 0\nIndicar:\n");
    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("c = ");
    scanf("%f", &c);

    // Calculo de la discriminante
    discri = pow(b, 2) - (4 * a * c);
    float denominador = 2 * a;

    if (discri < 0)
    {
        printf("No tiene resultado en los reales");
    }
    else if (discri == 0)
    {
        printf("\nTiene 2 raices reales e iguales\n");
        raiz1 = raiz2 = -b / (2 * a);
        printf("Raiz 1: %.2f\n", raiz1);
        printf("Raiz 2: %.2f\n", raiz2);
    }
    else
    {
        printf("\nTiene 2 raices reales y diferentes\n");
        float raiz = sqrt(discri);

        raiz1 = (-b + raiz) / denominador;
        raiz2 = (-b - raiz) / denominador;

        printf("Raiz 1: %.2f\n", raiz1);
        printf("Raiz 2: %.2f\n", raiz2);
    }

    return 0;
}
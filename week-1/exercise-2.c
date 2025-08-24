#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
    float z;
} Punto;

void setCoordinates(Punto *p)
{
    float x, y, z;
    printf("x: ");
    scanf("%f", &x);

    printf("y: ");
    scanf("%f", &y);

    printf("z: ");
    scanf("%f", &z);

    p->x = x; // p->x = (*p).x
    p->y = y;
    p->z = z;
}

float calculateDistance(Punto p1, Punto p2)
{
    float a, b, c; // diferencias al cuadrado

    a = pow((p1.x - p2.x), 2);
    b = pow((p1.y - p2.y), 2);
    c = pow((p1.z - p2.z), 2);

    return sqrt(a + b + c);
}

int main()
{
    Punto punto1;
    Punto punto2;

    float distancia;

    printf("WELCOME!\nTo calculate the distance bewtween 2 points in a 3D space, please set their respetive coordinates:\n");

    printf("Point 1:\n");
    setCoordinates(&punto1);

    printf("Point 2:\n");
    setCoordinates(&punto2);

    printf("\nAll right! Lets calculate that mf distance...");

    distancia = calculateDistance(punto1, punto2);

    printf("\nThe distance between those points is %.2f u", distancia);

    return 0;
}
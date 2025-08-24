/*
Lea del usuario un tiempo en segundos y muéstrelo en horas, minutos y segundos.
Utilice cinco métodos: lectura de datos, escritura, obtención de horas, minutos y segundos.
*/
#include <stdio.h>

// 1. Función para leer los segundos del usuario
int leerSegundos()
{
    int segundos;
    printf("Ingrese el tiempo en segundos: ");
    scanf("%d", &segundos);
    return segundos;
}

// 2. Función para obtener la cantidad de horas
int obtenerHoras(int totalSegundos)
{
    return totalSegundos / 3600;
}

// 3. Función para obtener la cantidad de minutos restantes (sin contar horas)
int obtenerMinutos(int totalSegundos)
{
    return (totalSegundos % 3600) / 60;
}

// 4. Función para obtener los segundos restantes (sin contar horas ni minutos)
int obtenerSegundos(int totalSegundos)
{
    return totalSegundos % 60;
}

// 5. Función para mostrar el tiempo en formato h:m:s
void mostrarTiempo(int horas, int minutos, int segundos)
{
    printf("Tiempo convertido: %02d horas, %02d minutos, %02d segundos\n", horas, minutos, segundos);
}

int main()
{
    int totalSegundos = leerSegundos();

    int horas = obtenerHoras(totalSegundos);
    int minutos = obtenerMinutos(totalSegundos);
    int segundos = obtenerSegundos(totalSegundos);

    mostrarTiempo(horas, minutos, segundos);

    return 0;
}

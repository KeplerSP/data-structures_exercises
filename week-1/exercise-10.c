/*
Lea una matriz 3x3 que representa un tablero de tres en raya (gato) e indique
qué jugada debería hacerse para ganar (si es posible) o al menos evitar una derrota.
*/
#include <stdio.h>

void mostrarGuiaCoordenadas()
{
    printf("Guía de coordenadas del tablero:\n\n");
    printf("   0     1     2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 3; j++)
        {
            printf("(%d,%d)", i, j);
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("  -------+--------+--------\n");
    }
    printf("\n");
    printf("Ingrese el contenido de cada casilla según las coordenadas mostradas.\n");
    printf("Use 'X', 'O' o '-' para vacío.(use solo mayuscula)\n\n");
}

void imprimirTablero(char tablero[3][3])
{
    printf("\nTablero actual:\n\n");
    printf("   0   1   2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 3; j++)
        {
            char mostrar = tablero[i][j] == ' ' ? '-' : tablero[i][j];
            printf(" %c ", mostrar);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("  ---+---+---\n");
    }
}

int buscarLinea(char tablero[3][3], char jugador, int *fila, int *columna)
{
    int i, j;

    // Revisar filas
    for (i = 0; i < 3; i++)
    {
        int cuentaJugador = 0, cuentaVacio = 0, colVacia = -1;
        for (j = 0; j < 3; j++)
        {
            if (tablero[i][j] == jugador)
                cuentaJugador++;
            else if (tablero[i][j] == ' ')
            {
                cuentaVacio++;
                colVacia = j;
            }
        }
        if (cuentaJugador == 2 && cuentaVacio == 1)
        {
            *fila = i;
            *columna = colVacia;
            return 1;
        }
    }

    // Revisar columnas
    for (j = 0; j < 3; j++)
    {
        int cuentaJugador = 0, cuentaVacio = 0, filaVacia = -1;
        for (i = 0; i < 3; i++)
        {
            if (tablero[i][j] == jugador)
                cuentaJugador++;
            else if (tablero[i][j] == ' ')
            {
                cuentaVacio++;
                filaVacia = i;
            }
        }
        if (cuentaJugador == 2 && cuentaVacio == 1)
        {
            *fila = filaVacia;
            *columna = j;
            return 1;
        }
    }

    // Diagonal principal
    int cuentaJugador = 0, cuentaVacio = 0, posVacia = -1;
    for (i = 0; i < 3; i++)
    {
        if (tablero[i][i] == jugador)
            cuentaJugador++;
        else if (tablero[i][i] == ' ')
        {
            cuentaVacio++;
            posVacia = i;
        }
    }
    if (cuentaJugador == 2 && cuentaVacio == 1)
    {
        *fila = posVacia;
        *columna = posVacia;
        return 1;
    }

    // Diagonal secundaria
    cuentaJugador = 0;
    cuentaVacio = 0;
    posVacia = -1;
    for (i = 0; i < 3; i++)
    {
        if (tablero[i][2 - i] == jugador)
            cuentaJugador++;
        else if (tablero[i][2 - i] == ' ')
        {
            cuentaVacio++;
            posVacia = i;
        }
    }
    if (cuentaJugador == 2 && cuentaVacio == 1)
    {
        *fila = posVacia;
        *columna = 2 - posVacia;
        return 1;
    }

    return 0;
}

int main()
{
    char tablero[3][3];
    int i, j;

    mostrarGuiaCoordenadas();

    // Ingreso del tablero por coordenadas usando '-', 'X' o 'O'
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            char entrada;
            do
            {
                printf("Contenido en (%d,%d): ", i, j);
                scanf(" %c", &entrada);
                if (entrada != 'X' && entrada != 'O' && entrada != '-')
                {
                    printf("Entrada inválida. Use 'X', 'O' o '-'.\n");
                }
            } while (entrada != 'X' && entrada != 'O' && entrada != '-');

            // Convertir '-' a espacio para lógica interna
            tablero[i][j] = (entrada == '-') ? ' ' : entrada;
        }
    }

    imprimirTablero(tablero);

    int fila, columna;

    // Intentar ganar con 'X'
    if (buscarLinea(tablero, 'X', &fila, &columna))
    {
        printf("\nJugada para GANAR: fila %d, columna %d\n", fila, columna);
        return 0;
    }

    // Intentar bloquear a 'O'
    if (buscarLinea(tablero, 'O', &fila, &columna))
    {
        printf("\nJugada para BLOQUEAR: fila %d, columna %d\n", fila, columna);
        return 0;
    }

    // Buscar primera posición libre
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (tablero[i][j] == ' ')
            {
                printf("\nJugada recomendada (primer espacio libre): fila %d, columna %d\n", i, j);
                return 0;
            }
        }
    }

    printf("\nNo hay jugadas posibles. El tablero está lleno.\n");
    return 0;
}

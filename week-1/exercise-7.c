/*
Determine la salida del siguiente programa:
for (int i = 2; i <= 8; i = i + 2) {
    for (int j = i; j <= 4; j++) {
        for (int k = 1; k <= j; k = k + i) {
            print(i + ", " + j + ", " + k);
        }
    }
}
*/

#include <stdio.h>

int main()
{
    for (int i = 2; i <= 8; i = i + 2)
    {
        for (int j = i; j <= 4; j++)
        {
            for (int k = 1; k <= j; k = k + i)
            {
                printf("%d, %d, %d", i, j, k);
            }
        }
    }
}
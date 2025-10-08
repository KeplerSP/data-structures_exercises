#include "lista_enlazada.h"
#include <stdio.h>

#include <iostream>
using namespace std;

//* ---------------------------------
//*     UTILIZAMOS NUESTRA LISTA
//* ---------------------------------

int main() {
    Lista lista;
    lista.insertarInicio(1);
    lista.insertarInicio(1);
    lista.insertarInicio(2);
    lista.insertarInicio(5);
    lista.insertarInicio(7);
    printf("---Lista Normal---");
    lista.imprimir();

    int buscar = 1;
    printf("\nEl numero '%d' aparece %d veces en la LinkedList.\n", buscar, lista.countOccurrences(buscar));

    // Revertir la lista
    lista.header = lista.reverseList(lista.header);

    printf("\n---Lista revertida---");
    lista.imprimir();
    return 0;
}

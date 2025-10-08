#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
//* ---------------------------------
//*     DEFINIMOS NUESTRA LISTA
//* ---------------------------------

#include <iostream>
using namespace std;

// Crear un Nodo es equivalente a añadir un elemento a la lista
struct Nodo {
    // Cada nodo contiene un valor característico, y una referencia a otro nodo
    int num;     /// Valor o dato característico
    Nodo* next;  /// Referencia(dirección) hacia otro nodo

    Nodo(int x) {
        /// Cada nodo creado requiere guardar un dato
        num = x;
        next = nullptr;
    }
};

// Las listas enlazadas son un conjunto(o cadena) de nodos, y se recorren desde el nodo header
struct Lista {
    Nodo* header;  // direccion del primer nodo
    int tam;

    // Constructor
    Lista() {
        // Cuando creamos nuestra lista, el primer nodo aún no existe
        header = nullptr;
        tam = 0;
    }

    // Métodos
    void imprimir();  // Ver todos los elementos de mi lista

    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void AdicionaAPosicion(int dato, int posicion);

    int retirarDeInicio();  // retorna elemento eliminado
    int RetiraDePosicion(int posicion);

    //* Métodos personalizados: Rema Thareja exercises
    int countOccurrences(int target);
    Nodo* reverseList(Nodo* head);

    // Destructor
    // ~Lista() { liberar(); }
};

#endif

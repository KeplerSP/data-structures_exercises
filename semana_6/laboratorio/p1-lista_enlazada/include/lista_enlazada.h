#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
//* ---------------------------------
//*     DEFINIMOS NUESTRA LISTA
//* ---------------------------------

#include <iostream>
using namespace std;

// Crear un Nodo es equivalente a añadir un elemento a la lista enlazada
struct Nodo {
    int dato;
    Nodo* sig;

    // constructor
    Nodo(int v) {
        dato = v;
        sig = nullptr;
    }
};

// Las listas enlazadas son un conjunto(o cadena) de nodos, y se recorren desde el nodo header
struct Lista {
    Nodo* cabeza;  // direccion del primer nodo
    int tam;       // cantidad de elementos de la lista

    // Constructor
    Lista() {
        // Cuando creamos nuestra lista, el primer nodo aún no existe
        cabeza = nullptr;
        tam = 0;
    }

    // Métodos
    void insertarInicio(int valor);
    int retirarDeInicio();
    void insertarFinal(int valor);
    void eliminar(int valor);
    Nodo* buscar(int valor);
    void imprimir();
    void liberar();
    int tamano();
    void AdicionaAPosicion(int dato, int posicion);
    int RetiraDePosicion(int posicion);
    void AdicionarEnOrden(int dato);
    void Concatenar(Lista* b);
    void Invertir();

    // Destructor
    ~Lista() { liberar(); }
};

#endif

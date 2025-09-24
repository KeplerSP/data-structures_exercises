#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
using namespace std;

// Nodo con constructor
struct Nodo {
    int dato;
    Nodo* sig;

    Nodo(int v) {
        dato = v;
        sig = nullptr;
    }
};

// Lista enlazada simple
struct Lista {
    Nodo* cabeza; //almacena la direccion de tipo nodo
    int tam;

    // Constructor
    Lista() {
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

#include "cola_array_int.h"

#include <algorithm>  // para swap

ColaArrayInt::ColaArrayInt(int capacidad_inicial) {
    if (capacidad_inicial <= 0) capacidad_inicial = 1;
    datos = new int[capacidad_inicial];
    n = 0;
    cap = capacidad_inicial;
    head = 0;
    tail = 0;
}

ColaArrayInt::ColaArrayInt(const ColaArrayInt& o) {
    datos = new int[o.cap];
    n = o.n;
    cap = o.cap;
    head = 0;
    tail = n;
    for (int i = 0; i < n; ++i) {
        datos[i] = o.datos[(o.head + i) % o.cap];
    }
}

ColaArrayInt& ColaArrayInt::operator=(ColaArrayInt o) {
    swap(datos, o.datos);
    swap(n, o.n);
    swap(cap, o.cap);
    swap(head, o.head);
    swap(tail, o.tail);
    return *this;
}

ColaArrayInt::~ColaArrayInt() {
    delete[] datos;
}

bool ColaArrayInt::empty() const { return n == 0; }
int ColaArrayInt::size() const { return n; }
int ColaArrayInt::capacity() const { return cap; }

void ColaArrayInt::clear() {
    n = 0;
    head = 0;
    tail = 0;
}

void ColaArrayInt::reservar(int m) {
    if (m <= cap) return;
    int* nd = new int[m];
    for (int i = 0; i < n; ++i) {
        nd[i] = datos[(head + i) % cap];
    }
    delete[] datos;
    datos = nd;
    cap = m;
    head = 0;
    tail = n;
}

void ColaArrayInt::push(int x) {
    /*Se verifica que si el numero de elementos es igual a la capacidad, se agranda el arreglo*/
    if (n == cap) reservar(cap * 2);
    /*como inicialmente el numero de elementos es 0, este se va a ingresar en el primer elemento del arreglo y
    se incrementa el n en 1 para que se situe en el siguiente elemento del arreglo*/
    datos[n] = x;
    n++;
}

void ColaArrayInt::pop() {
    /*Si la lista esta vacia se hace manda un mensaje que la cola esta vacia*/
    if (empty()) throw runtime_error("pop() en cola vacia");
    /*En caso exista elementos en la cola, este se agregara al final utilizando un
    bucle for que inicializa en 0 , o en el head que siempre se mantendra ahi. y de ahi
    va iterando hasta el numero de elementos -1. para que se pueda hacer el intercambio
    de valores de [i+1] a [i] y tambien para que este no llegue al ultimo valor del arreglo
    dado que el siguiente de este seria un valor basura. finalizando se hace el decremento
    del numero de elementos*/
    for (int i = head; i < n - 1; i++) {
        datos[i] = datos[i + 1];
    }
    n--;
}

int& ColaArrayInt::front() {
    if (empty()) throw runtime_error("front() en cola vacia");

    /*Dado que el front es la cabeza o 0 del arreglo siempre se mostrara el valor en ese indice.*/
    return datos[head];
}

const int& ColaArrayInt::front() const {
    if (empty()) throw runtime_error("front() en cola vacia");
    return datos[head];
}

int& ColaArrayInt::back() {
    if (empty()) throw runtime_error("back() en cola vacia");
    /*Aca se senala que el ultimo sera el valor que esta situado en el indice del numero de elementos -1, dado que
    el numero de elementos excede al indice del arreglo y el -1 nos situa en el ultimo indice del arreglo*/
    return datos[n - 1];
}

const int& ColaArrayInt::back() const {
    if (empty()) throw runtime_error("back() en cola vacia");
    return datos[n - 1];
}

void ColaArrayInt::imprimir() const {
    for (int i = head; i < n; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

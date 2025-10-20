#include <iostream>
using namespace std;

struct Nodo {
    Nodo* next;
    int value;

    Nodo(int x) {
        value = x;
        next = nullptr;
    }
};

struct Lista {
    Nodo* header = new Nodo(0);  // nodo header (un nodo 'vacio')
    Nodo* tail;
    int tam;

    Lista() {
        tail = nullptr;
        tam = 0;
    }

    // Métodos
    void imprimir();
    void insertInicio(int x);
    void insertarFinal(int x);

    int eliminarInicio();
    int eliminarFinal();
    int eliminarEnPosicion(int pos);  // eliminar el nodo de la posición 'n' y retornarlo
    Lista* concatList(Lista* lista1, Lista* lista2);
    void appendList(Lista* l2);
};

void Lista::imprimir() {
    Nodo* temp = header->next;  // los datos inician reales desde el segundo nodo
    cout << "\nTamaño de la lista: " << tam << endl;
    while (temp != nullptr) {
        cout << (*temp).value << ", ";
        temp = (*temp).next;
    }
    cout << "\n";
}

void Lista::insertInicio(int x) {
    Nodo* newNodo = new Nodo(x);
    if (header->next == nullptr) {
        // insertamos el primer nodo de la lista
        header->next = newNodo;
        tail = newNodo;  // tail = head porque solo hay un nodo
        ++tam;
        return;
    }
    // agregamos el nuevo nodo al inicio de la lista
    newNodo->next = header->next;
    header->next = newNodo;
    ++tam;
}

void Lista::insertarFinal(int x) {
    if (header->next == nullptr) {
        // no hay elementos
        Lista::insertInicio(x);
        return;
    }
    Nodo* newNodo = new Nodo(x);
    tail->next = newNodo;
    tail = newNodo;
    ++tam;
}

// Funcion para crear una lista como resultado de concatenar 2 listas ordenadas
Lista* concatList(Lista* lista1, Lista* lista2) {
    Nodo* aux1 = lista1->header->next;
    Nodo* aux2 = lista2->header->next;

    Lista* lista3 = new Lista();

    // Si se apunta a un nullptr significa que una lista se quedo sin elementos
    while (aux1 && aux2) {
        if (aux1->value < aux2->value) {
            lista3->insertarFinal(aux1->value);
            aux1 = aux1->next;
        } else {
            lista3->insertarFinal(aux2->value);
            aux2 = aux2->next;
        }
    }

    // Verificamos qué lista se quedo sin elementos
    while (aux1) {
        // significa que aux2 se quedo sin elementos
        lista3->insertarFinal(aux1->value);
        aux1 = aux1->next;
    }

    while (aux2) {
        // significa que aux1 se quedo sin elementos
        lista3->insertarFinal(aux2->value);
        aux2 = aux2->next;
    }

    return lista3;
}

// Función para agregar los elementos de una lista dentro de otra, de forma ordenada
void Lista::appendList(Lista* l2) {
    Nodo* t = header;             // header de la lista1
    Nodo* p1 = header->next;      // ptr al primer elemento de la lista 1
    Nodo* p2 = l2->header->next;  // ptr al primer elemento de la lista 2

    while (p1 && p2) {
        if (p1->value <= p2->value) {
            t->next = p1;
            t = t->next;
            p1 = p1->next;
            ++tam;
        } else {
            // p2 > p1
            t->next = p2;
            t = t->next;
            p2 = p2->next;
            ++tam;
        }
    }

    // agregamos los elementos faltantes
    if (p1) {
        while (p1) {
            t->next = p1;
            t = t->next;
            p1 = p1->next;
        }
    }

    if (p2) {
        while (p2) {
            t->next = p2;
            t = t->next;
            p2 = p2->next;
        }
    }
}

int main() {
    Lista lista;
    lista.insertInicio(125);
    lista.insertInicio(120);
    lista.insertInicio(100);
    lista.insertInicio(7);
    lista.insertInicio(2);
    lista.imprimir();

    Lista lista2;
    lista2.insertInicio(50);
    lista2.insertInicio(22);
    lista2.insertInicio(11);
    lista2.insertInicio(5);
    lista2.insertInicio(4);
    lista2.insertInicio(3);

    cout << "\nNueva lista 3: ";
    Lista* lista3 = concatList(&lista, &lista2);
    lista3->imprimir();
    
    cout << "\nLista concatenada: " << endl;
    lista.appendList(&lista2);
    lista.imprimir();

    return 1;
}
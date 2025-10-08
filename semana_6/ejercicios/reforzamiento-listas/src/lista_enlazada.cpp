#include "lista_enlazada.h"
//* -------------------------------------------------
//*     IMPLEMENTAMOS LA LÓGICA DE NUESTRA LISTA
//* -------------------------------------------------

void Lista::insertarInicio(int valor) {
    Nodo* newNodo = new Nodo(valor);  // Crear un nodo
    newNodo->next = header;           // Hacer que apunte al anterior header
    header = newNodo;                 // Convertirlo en el header
    tam++;                            // aumentar tamaño de la lista
}

void Lista::insertarFinal(int valor) {
    Nodo* newNodo = new Nodo(valor);  // creo mi nuevo nodo final

    if (header == nullptr) {
        header = newNodo;
        tam++;
        return;
    }
    Nodo* aux = header;  // ptr auxiliar

    // recorremos cada nodo hasta llegar al último
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    aux->next = newNodo;
    tam++;
}

void Lista::AdicionaAPosicion(int dato, int posicion) {
    if (posicion >= tam) {
        printf("\nIngrese una posición valida. La lista inicia en la poisición 0");
        return;
    }
    if (posicion == 0) {
        Lista::insertarInicio(dato);
        return;
    }
    if (posicion == tam - 1) {
        Lista::insertarFinal(dato);
        return;
    }

    // Creamos el nuevo nodo
    Nodo* newNodo = new Nodo(dato);
    Nodo* aux = header;

    // Recorremos hasta llegar a un nodo anterior a donde quiero insertar el nuevo nodo
    for (int i = 1; i <= posicion - 1; i++) {
        aux = aux->next;
    }

    newNodo->next = aux->next;
    aux->next = newNodo;
    tam++;
}

int Lista::retirarDeInicio() {
    if (tam == 0) {
        cout << "Lista vacia! No es posible eliminar elementos" << endl;
        return -1;
    }
    int value = header->num;  // guardar temporalmente el valor que voy a eliminar
    Nodo* aux = header;       // guardar la dirección del nodo a eliminar

    header = header->next;
    delete aux;
    tam--;

    return value;
}

int Lista::RetiraDePosicion(int posicion) {
    // Sea 'n' la posicion del nodo a eliminar ; n = posicion
    if (posicion == 0) {
        return Lista::retirarDeInicio();
    }

    int value;
    Nodo* aux1 = header;  // nodo en la posición 0

    for (int i = 1; i <= posicion - 1; i++) {
        aux1 = aux1->next;  // obtenemos el nodo de la posicion n-1
    }

    Nodo* aux2 = aux1->next;  // nodo que queremos eliminar
    aux1->next = aux2->next;  // funciona incluso si el nodo 'n' era el último

    value = aux2->num;
    delete aux2;
    tam--;

    return value;
}

void Lista::imprimir() {
    Nodo* temp = header;
    cout << "\nTamaño de la lista: " << tam << endl;
    while (temp != nullptr) {
        cout << (*temp).num << ", ";
        temp = (*temp).next;
    }
}

//* Ejercicio 2 y 21:
// Write a program to print the total number of occurrences of a given item in the linked list.
// Write a program to count the number of occurrences of a given value in a linked list.
int Lista::countOccurrences(int target) {
    int count = 0;
    Nodo* aux = header;

    while (aux != nullptr) {
        if (aux->num == target) {
            count++;
        }
        aux = aux->next;
    }

    return count;
}

//* Ejercicio 15 y 33
// Write a program to reverse a linked list using recursion.
// Write a program to create a singly linked list and reverse the list by interchanging the links and not the data
Nodo* Lista::reverseList(Nodo* head) {
    // Caso base: lista vacía o un solo nodo
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Llamada recursiva: revertir el resto de la lista
    Nodo* nuevoHeader = reverseList(head->next);

    // Invertir los enlaces
    head->next->next = head;  // El siguiente nodo ahora apunta al actual
    head->next = nullptr;     // El nodo actual apunta a nullptr

    return nuevoHeader;  // Retornar el nuevo header (último nodo original)
}

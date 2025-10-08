#include "lista_enlazada.h"
//* ---------------------------------
//*     UTILIZAMOS NUESTRA LISTA 
//* ---------------------------------

int main() {
    // Creamos la lista 'lista1'
    Lista* lista1 = new Lista();
    lista1->insertarInicio(1);
    lista1->insertarInicio(2);
    
    // Creamos la lista 'lista2'
    Lista* lista2 = new Lista();
    lista2->insertarInicio(3);

    lista1->Concatenar(lista2);
    lista1->imprimir();

    // Creamos la lista 'lista3'
    Lista lista3;
    lista3.insertarInicio(1);
    lista3.insertarInicio(2);
    lista3.Invertir();

    // lista.insertarInicio(11); //modo de uso "."
    // lista.insertarInicio(9);
    // lista.insertarInicio(7); //modo de uso "."
    // lista.insertarInicio(5);
    // cout<<"Antes de agregar el 8"<<endl;
    // lista.imprimir();

    // lista.AdicionarEnOrden(8);
    // lista.imprimir();

    // Nodo* encontrado = lista.buscar(30);
    // if (encontrado)
    //     cout << "Encontrado: " << encontrado->dato << endl;
    // else
    //     cout << "No encontrado\n";

    return 0;
}

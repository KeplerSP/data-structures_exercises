#include "lista_enlazada.h"

void ListaCircularDoblementeEnlazada::append(const std::string & title) {
    Node *n = new Node(title);
    if (!head) {
        n->next=n;
        n->prev=n;
        head=n;
        current=head;
        return;
    }
    Node*t=head;
    while(t->next!=head){
        t=t->next;
    }
    n->next=t->next;
    n->prev=t;
    t->next=n;
    head->prev=n;
}



void ListaCircularDoblementeEnlazada::move_left() {
    if (!current)
        return;
    
    Node *prev = current->prev;
    
    if (prev) 
        current = prev;
}

void ListaCircularDoblementeEnlazada::move_right() {
    if (current && current -> next) 
        current = current -> next;
}

const char *ListaCircularDoblementeEnlazada::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaCircularDoblementeEnlazada::~ListaCircularDoblementeEnlazada() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}
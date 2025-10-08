#include "lista_enlazada.h"

void ListaDoblementeEnlazada::append(const std::string & title) {
    Node *n = new Node(title);
    if (!head && !cola){
        head=n;
        cola=n;
        current=head;
        return;
    }
    Node* t=head;
    while(t->next){
        t=t->next;
    }
    n->prev=t;
    t->next=n;
    cola=n;
}

Node *ListaDoblementeEnlazada::find_prev(Node *node) {
    if (!head || head == node) 
        return nullptr;
    Node *t = head;
    
    while (t && t -> next != node) 
        t = t -> next;

    return t;
}

void ListaDoblementeEnlazada::move_left() {
    if (!current)
        return;
    
    Node *prev = find_prev(current);
    
    if (prev) 
        current = prev;
}

void ListaDoblementeEnlazada::move_right() {
    if (current && current -> next) 
        current = current -> next;
}

const char *ListaDoblementeEnlazada::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}
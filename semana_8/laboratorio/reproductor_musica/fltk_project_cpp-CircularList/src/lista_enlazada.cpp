#include "lista_enlazada.h"

void ListaCircularEnlazada::append(const std::string & title) {
    Node *n = new Node(title);
    if (!head) {
        head = n;
        n->next = head;
        current = head;
        return;
    }
    Node *t = head;
    while (t && t->next!=head){
        t = t->next;
    } 
    n->next=t->next;
    t->next=n;
}

Node *ListaCircularEnlazada::find_prev(Node *node) {
    if (!head || head == node) 
        return nullptr;
    Node *t = head;
    
    while (t && t -> next != node) 
        t = t -> next;

    return t;
}

void ListaCircularEnlazada::move_left() {
    if (!current)
        return;
    
    Node *prev = find_prev(current);
    
    if (prev) 
        current = prev;
}

void ListaCircularEnlazada::move_right() {
    if (current && current -> next) 
        current = current -> next;
}

const char *ListaCircularEnlazada::title_cstr() const {
    static std::string empty = "No songs";
    return current ? current -> song.c_str() : empty.c_str();
}

ListaCircularEnlazada::~ListaCircularEnlazada() {
    Node *t = head;
    while (t) {
        Node *nx = t -> next;
        delete t;
        t = nx;
    }
    head = current = nullptr;
}
#include <iostream>
using namespace std;

/*
usuarios
    │
    ├── Persona(id=1) → amigos: 2 → 3 → NULL
    ├── Persona(id=2) → amigos: 1 → 4 → NULL
    └── Persona(id=3) → amigos: 1 → NULL
*/

struct NodoAmigo {
    int idAmigo;      // identificador del amigo
    NodoAmigo* next;  // siguiente amigo en la lista
};

struct Persona {
    int id;             // ID del usuario
    NodoAmigo* amigos;  // lista enlazada de amigos
    Persona* next;      // siguiente persona en el sistema
};

struct TipoOrkut {
    Persona* usuarios;  // Lista de adyacencia -> contiene a todas las personas registradas
};


Persona* buscarPersona(TipoOrkut* o, int id);
Persona* crearPersona(int id);
void insertarPersona(TipoOrkut* o, Persona* nueva);
void agregarAmigo(Persona* p, int idAmigo);

void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut);

int main() {
    return 1;
}

void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut) {
    // 1. Buscar Amigo1
    Persona* p1 = buscarPersona(pOrkut, Amigo1);

    // 2. Buscar Amigo2
    Persona* p2 = buscarPersona(pOrkut, Amigo2);
    if (p2 == nullptr) {
        p2 = crearPersona(Amigo2);
        insertarPersona(pOrkut, p2);
    }

    // 3. Crear enlaces de amistad mutua
    agregarAmigo(p1, Amigo2);
    agregarAmigo(p2, Amigo1);
}

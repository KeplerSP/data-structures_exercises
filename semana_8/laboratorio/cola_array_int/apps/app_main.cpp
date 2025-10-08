#include "cola_array_int.h"

int main() {
    // Se Declara una cola de 4 elementos
    ColaArrayInt Q(4);
    // 10 , 20 , 30
    Q.push(10);
    Q.push(20);
    Q.push(30);
    // 20, 30
    Q.pop();
    // 20, 30 ,50
    Q.push(50);
    Q.imprimir();
    // 30, 50
    Q.pop();
    Q.imprimir();
    return 0;
}

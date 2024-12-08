#include "nota.h"

Nota::Nota() : producto(0), desempeno(0), conocimiento(0), promedio(0) {}

Nota::Nota(double producto, double desempeno, double conocimiento) 
    : producto(producto), desempeno(desempeno), conocimiento(conocimiento) {
    calcularPromedio();
}

void Nota::calcularPromedio() {
    promedio = (producto * 0.3) + (desempeno * 0.4) + (conocimiento * 0.3);
}

#ifndef NOTA_H
#define NOTA_H

#include <string>
using namespace std; 

class Nota {
private:
    double producto;
    double desempeno;
    double conocimiento;
    double promedio;

    void calcularPromedio();

public:
    Nota();
    Nota(double producto, double desempeno, double conocimiento);

    double getProducto() const { return producto; }
    double getDesempeno() const { return desempeno; }
    double getConocimiento() const { return conocimiento; }
    double getPromedio() const { return promedio; }

    std::string toString() const {
        return "Producto: " + std::to_string(producto) + ", Desempeño: " + std::to_string(desempeno) + ", Conocimiento: " + std::to_string(conocimiento) + ", Promedio: " + std::to_string(promedio);
    }
};

#endif

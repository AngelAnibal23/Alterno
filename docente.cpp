#include "docente.h"
#include <iostream>
#include <fstream>

Docente::Docente(const string& id, const string& nombre, const string& apellido, const string& dni)
    : Persona(id, nombre, apellido, dni) {}

void Docente::agregarCurso(const string& curso) {
    if (cursos.size() < 3) {
        cursos.push_back(curso);
    } else {
        cout << "El docente solo puede dictar 3 cursos como máximo." << endl;
    }
}

void Docente::mostrarCursos() const {
    cout << "Cursos dictados por " << getNombre() << " " << getApellido() << ":" << endl;
    for (const string& curso : cursos) {
        cout << "- " << curso << endl;
    }
}

void Docente::registrarNotas(const string& curso, const string& estudianteId, const Nota& nota, int unidad) {
    ofstream archivo("notas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << estudianteId << "," << curso << ","
                << (unidad == 1 ? "Unidad1" : "Unidad2") << ","
                << nota.getProducto() << "," << nota.getDesempeno() << ","
                << nota.getConocimiento() << "," << nota.getPromedio() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo para registrar notas." << endl;
    }
}

#include "estudiante.h"
#include <iostream>

Estudiante::Estudiante(const string& id, const string& nombre, const string& apellido, const string& dni)
    : Persona(id, nombre, apellido, dni) {}

void Estudiante::mostrarNotas() const {
    cout << "Notas del estudiante: " << getNombre() << " " << getApellido() << endl;
    for (const auto& curso : cursos) {
        cout << "Curso: " << curso << endl;
        const auto& notas = notasPorCurso.at(curso);
        for (size_t i = 0; i < notas.size(); ++i) {
            cout << "  Unidad " << (i + 1) << ": " << notas[i].toString() << endl;
        }
    }
}

void Estudiante::registrarNota(const string& curso, int unidad, const Nota& nota) {
    if (notasPorCurso.count(curso) && unidad >= 1 && unidad <= 2) {
        notasPorCurso[curso][unidad - 1] = nota;
    } else {
        cout << "Curso o unidad no válidos." << endl;
    }
}

void Estudiante::agregarCurso(const string& curso) {
    cursos.push_back(curso);
    notasPorCurso[curso] = {Nota(), Nota()};
}

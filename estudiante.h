#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include "nota.h"
#include <vector>
#include <unordered_map>

class Estudiante : public Persona {
private:
    std::vector<std::string> cursos;
    std::unordered_map<std::string, std::vector<Nota>> notasPorCurso;

public:
    Estudiante(const std::string& id, const std::string& nombre, const std::string& apellido, const std::string& dni);

    void agregarCurso(const std::string& curso);
    void registrarNota(const std::string& curso, int unidad, const Nota& nota);
    void mostrarNotas() const;
};

#endif

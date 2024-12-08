#ifndef DOCENTE_H
#define DOCENTE_H

#include "persona.h"
#include "nota.h"
#include <vector>
#include <string>

class Docente : public Persona {
private:
    std::vector<std::string> cursos;

public:
    Docente(const std::string& id, const std::string& nombre, const std::string& apellido, const std::string& dni);

    void agregarCurso(const std::string& curso);
    void mostrarCursos() const;
    void registrarNotas(const std::string& curso, const std::string& estudianteId, const Nota& nota, int unidad);
};

#endif

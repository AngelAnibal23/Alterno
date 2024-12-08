#include "persona.h"

Persona::Persona(const string& id, const string& nombre, const string& apellido, const string& dni)
    : id(id), nombre(nombre), apellido(apellido), dni(dni) {}

string Persona::getId() const {
    return id;
}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getApellido() const {
    return apellido;
}

string Persona::getDni() const {
    return dni;
}

void Persona::setId(const string& newId) {
    id = newId;
}

void Persona::setNombre(const string& newNombre) {
    nombre = newNombre;
}

void Persona::setApellido(const string& newApellido) {
    apellido = newApellido;
}

void Persona::setDni(const string& newDni) {
    dni = newDni;
}

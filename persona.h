#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string id;
    string nombre;
    string apellido;
    string dni;

public:
    Persona(const string& id, const string& nombre, const string& apellido, const string& dni);

    string getId() const;
    string getNombre() const;
    string getApellido() const;
    string getDni() const;

    void setId(const string& newId);
    void setNombre(const string& newNombre);
    void setApellido(const string& newApellido);
    void setDni(const string& newDni);
};

#endif

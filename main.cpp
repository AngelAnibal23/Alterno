#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "docente.h"
#include "estudiante.h"
#include "nota.h"
#include "persona.h"

using namespace std;

void login(const string& usuario, const string& contrasena, bool& loginValido, string& tipoUsuario) {
    ifstream archivoUsuarios("usuarios.txt");
    string line;
    while (getline(archivoUsuarios, line)) {
        stringstream ss(line);
        string user, pass, tipo;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, tipo);
        if (user == usuario && pass == contrasena) {
            loginValido = true;
            tipoUsuario = tipo;  // Establece el tipo de usuario (docente o estudiante)
            return;
        }
    }
    loginValido = false;
}

Docente cargarDocente(const string& codigo) {
    ifstream archivoDocentes("docentes.txt");
    string line;
    while (getline(archivoDocentes, line)) {
        stringstream ss(line);
        string id, nombre, apellido, dni, curso1, curso2, curso3;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, dni, ',');
        getline(ss, curso1, ',');
        getline(ss, curso2, ',');
        getline(ss, curso3);

        if (id == codigo) {
            Docente docente(id, nombre, apellido, dni);
            docente.agregarCurso(curso1);
            docente.agregarCurso(curso2);
            docente.agregarCurso(curso3);
            return docente;
        }
    }
    return Docente("", "", "", "");  // Retorna un docente vacío si no se encuentra
}

Estudiante cargarEstudiante(const string& codigo) {
    ifstream archivoEstudiantes("estudiantes.txt");
    string line;
    while (getline(archivoEstudiantes, line)) {
        stringstream ss(line);
        string id, nombre, apellido, dni, curso1, curso2, curso3;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, dni, ',');
        getline(ss, curso1, ',');
        getline(ss, curso2, ',');
        getline(ss, curso3);

        if (id == codigo) {
            Estudiante estudiante(id, nombre, apellido, dni);
            estudiante.agregarCurso(curso1);
            estudiante.agregarCurso(curso2);
            estudiante.agregarCurso(curso3);
            return estudiante;
        }
    }
    return Estudiante("", "", "", "");  // Retorna un estudiante vacío si no se encuentra
}

int main() {
    string usuario, contrasena;
    bool loginValido = false;
    string tipoUsuario;

    cout << "Ingrese su codigo de usuario: ";
    cin >> usuario;
    cout << "Ingrese su DNI: ";
    cin >> contrasena;

    login(usuario, contrasena, loginValido, tipoUsuario);

    if (loginValido) {
        cout << "Login exitoso!" << endl;

        // Dependiendo del tipo de usuario, carga los datos correspondientes
        if (tipoUsuario == "docente") {
            Docente docente = cargarDocente(usuario);
            // Aquí podrías agregar las acciones que el docente puede hacer, como registrar notas
            cout << "Bienvenido Docente: " << docente.getNombre() << endl;
            docente.mostrarCursos();  // Muestra los cursos del docente
            // Mostrar menú de acciones para el docente
            // Por ejemplo: registrar notas, ver estudiantes, etc.
        } else if (tipoUsuario == "estudiante") {
            Estudiante estudiante = cargarEstudiante(usuario);
            // Aquí podrías agregar las acciones que el estudiante puede hacer, como ver sus notas
            cout << "Bienvenido Estudiante: " << estudiante.getNombre() << endl;
            estudiante.mostrarNotas();  // Muestra las notas del estudiante
            // Mostrar menú de acciones para el estudiante
            // Por ejemplo: ver notas, consultar profesores, etc.
        } else {
            cout << "Tipo de usuario no reconocido." << endl;
        }

    } else {
        cout << "Login fallido. Verifique sus credenciales." << endl;
    }

    return 0;
}

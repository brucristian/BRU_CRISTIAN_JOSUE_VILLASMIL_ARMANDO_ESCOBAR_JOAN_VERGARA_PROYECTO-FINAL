/**
 * @file estudiantecontroller.h
 * @brief Controlador para gestionar las operaciones CRUD de los estudiantes.
 * 
 * Este archivo contiene las funciones encargadas de manejar el registro,
 * búsqueda, recarga, eliminación y consulta de estudiantes dentro del
 * archivo binario "estudiantes.dat".
 */

#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include "../model/estudiante.h"
#include "../utils/filemanager.h"
#include "../utils/validaciones.h"


using namespace std;

/**
 * @brief Busca un estudiante en el archivo binario por su ID.
 * 
 * Esta función recorre el archivo "estudiantes.dat" y retorna el
 * registro del estudiante cuyo ID coincida con el proporcionado.
 * 
 * @param id Identificación del estudiante a buscar.
 * @return Estudiante Estructura con los datos del estudiante encontrado.
 */
Estudiante buscarEstudiante(long long id) {
    vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("data/estudiantes.dat");
    Estudiante e;

    for (Estudiante &p : estudiantes) {
        if (p.id == id) {
            e = p;
            break;
        }
    }

    return e;
}

/**
 * @brief Registra un nuevo estudiante en el archivo binario.
 * 
 * Verifica que el ID no esté duplicado y que el saldo inicial sea
 * mayor o igual a 5000. Si cumple las condiciones, crea el registro
 * del estudiante y lo guarda en el archivo.
 * 
 * @param id Identificación del estudiante.
 * @param name Nombre del estudiante.
 * @param grado Grado del estudiante.
 * @param saldo Saldo inicial del estudiante.
 * @return true Si el registro se realizó correctamente.
 * @return false Si el ID ya existe, el saldo es insuficiente.
 */

bool registroEstudiante(long long &id, char name[50], int &grado, double &saldo) {
    vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("data/estudiantes.dat");

    if (!estudiantes.empty()) {
        for (Estudiante &e : estudiantes) {
            if (id == e.id)
                return false;  
        }
    }

    
    if (saldo < 5000)
        return false;

    Estudiante e;
    e.grado = grado;
    e.id = id;
    strcpy(e.name, name);
    e.monto = saldo;

    return writeBinaryFile("data/estudiantes.dat", e);
}

/**
 * @brief Realiza una recarga al saldo de un estudiante.
 * 
 * Verifica que el monto sea válido (entre 0 y 500000) y que el estudiante exista.
 * Luego actualiza el saldo del registro correspondiente en el archivo binario.
 * 
 * @param id Identificación del estudiante.
 * @param recarga Monto de recarga a aplicar.
 * @return true Si la recarga se realizó correctamente.
 * @return false Si el monto es inválido o el estudiante no existe.
 */

bool recargaEstudiante(long long id, double recarga) {
    Estudiante e;

 
    if (recarga > 500000 || recarga < 0) {
        cout << "\n==============================================" << endl;
        cout << "           Monto de recarga no válido         " << endl;
        cout << "==============================================" << endl;
        return false;
    }

    if (existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
        e = buscarEstudiante(id);
    } else {
        return false;
    }

    return updateBinaryFile("data/estudiantes.dat", e, e.monto + recarga);
}

/**
 * @brief Elimina un registro de estudiante del archivo binario.
 * 
 * Busca el estudiante por su ID y, si existe, elimina su registro
 * del archivo `estudiantes.dat`.
 * 
 * @param id Identificación del estudiante a eliminar.
 * @return true Si el registro se eliminó correctamente.
 * @return false Si el estudiante no existe.
 */

bool eliminarEstudiante(long long id) {
    Estudiante e;

    
    if (existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
        e = buscarEstudiante(id);
    } else {
        return false;
    }

    return deleteOnBinaryFile("data/estudiantes.dat", e);
}
/**
 * @brief Muestra la información de un estudiante por consola.
 * 
 * Busca el estudiante en el archivo y, si existe, imprime sus datos.
 * Si no se encuentra, muestra un mensaje de error.
 * 
 * @param id Identificación del estudiante a consultar.
 */

void consultarEstudiante(long long id){ 
    Estudiante e;

    if (existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
    e = buscarEstudiante(id);

       cout << "\n==============================================\n";
       cout << "           DATOS DEL ESTUDIANTE              \n";
       cout << "==============================================\n";
       cout << "| Cedula       | Nombre            | Grado | Saldo  |\n";
       cout << "----------------------------------------------\n";
       cout << "| " << e.id 
            << " | " << setw(16) << left << e.name 
            << " | " << setw(5) << left << e.grado 
            << " | " << setw(6) << right << e.monto 
            << " |\n";
        cout << "==============================================\n";
    } else {
      cout << "\n==============================================" << endl;
      cout << "ERROR: No hay registros con la cedula [" << id << "]" << endl;
      cout << "==============================================" << endl;
    }

}       

#endif

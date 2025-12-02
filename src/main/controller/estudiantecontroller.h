/**
 * @file estudiantecontroller.h
 * @brief Controlador para gestionar las operaciones CRUD de los estudiantes.
 * 
 * Este archivo contiene las funciones encargadas de manejar el registro,
 * búsqueda, recarga, eliminación y consulta de estudiantes dentro del
 * archivo binario `estudiantes.dat`.
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
#include "../utils/getters.h"
#include "../model/compra.h"
#include "../utils/messages.h"

using namespace std;


/**
 * @brief Busca un estudiante en el archivo binario por su ID.
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



bool restarSaldo(long long id, double valorDeCompra) {
    if(!existsById<long long, Estudiante>("data/estudiantes.dat",id)) { 
        studentNotFoundError();
        return false;
    }
    Estudiante e = buscarEstudiante(id);

    double nuevoSaldo = e.monto - valorDeCompra;


    return updateBinaryFile<Estudiante, double>("data/estudiantes.dat", e, nuevoSaldo);
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

vector<int> registroEstudiante(long long &id, char name[50], int &grado, double &saldo) {
	
	vector<int> error; 	
    vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("data/estudiantes.dat");

    bool exist = existsById<long long, Estudiante>("data/estudiantes.dat", id);
    if (!estudiantes.empty() && exist) {
        duplicateIDError(id);

        error.push_back(1);
    }

    if(grado < 1 || grado > 12) {
        negativeQuantityError("REGISTRO");
        error.push_back(3);
    }
    
    if(saldo<5000) {
        invalidInitialAmountError();

		error.push_back(4);
	}
    

    Estudiante e;
    e.grado = grado;
    e.id = id;
    strcpy(e.name, name);
    e.monto = saldo;

    if(!error.empty())
        return error;

    if(!writeBinaryFile<Estudiante>("data/estudiantes.dat", e)) {
      registrationError("registrar");

        error.push_back(5);
    }

    return error;
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

vector<int> recargaEstudiante(long long id, double recarga) {
	vector <int> error;
    Estudiante e;

 
    if (recarga > 500000 || recarga < 0) {
        invalidRechargeAmountError();

        error.push_back(2);
    }

    if (!existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
        studentNotFoundError();

        error.push_back(1); 
    }

    e = buscarEstudiante(id);
    if(!error.empty())
        return error;

    if(!updateBinaryFile<Estudiante, double>("data/estudiantes.dat", e, recarga + e.monto)) {

        registrationError("actualizar");

        error.push_back(3);
    }

    return error;
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
    	studentNotFoundError();

        return false;
    }
    
    writeCSVFile<Estudiante>(e);
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

void consultarEstudiante(long long id) {
    Estudiante e;
    vector<Compra> compras = readBinaryFile<Compra>("data/compras.dat");
    

     if (existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
        e = buscarEstudiante(id);
        
        
        cout << "\n=====================================================\n";
        imprimirConFormato("DATOS DEL ESTUDIANTE");
        cout << "\n=====================================================\n";
        cout << "| Cedula       | Nombre            | Grado | Saldo |\n";
        cout << "-----------------------------------------------------\n";
        cout << "| " << e.id 
             << " | " << setw(16) << left << e.name 
             << " | " << setw(5) << left << e.grado 
             << " | " << setw(6) << right << e.monto 
             << " |\n";
        cout << "=====================================================\n";

        cout << "\n=====================================================\n";
        imprimirConFormato("COMPRAS REALIZADAS");
        cout << "\n=====================================================\n";
        cout << "| Fecha      | Cedula             | Producto |  Valor |\n";
        cout << "-----------------------------------------------------\n";

        for(Compra c : compras){
            if(e.id == c.id){
                cout << "| " << c.fecha
                << " | " << setw(16) << left << c.id
                << " | " << setw(5) << left << c.name
                << " | " << setw(6) << right << c.valor
                << " |\n";
                cout << "=====================================================\n";

            }


        }
        return;
    }
    
    studentNotFoundError();
}
/**
 * @brief Muestra los estudiantes con saldo menor a 5000.
 * 
 * Esta función lee todos los registros de estudiantes almacenados 
 * en el archivo binario "/data/estudiantes.dat" y muestra en formato
 * tabular aquellos cuya cantidad de dinero (`monto`) es inferior a 5000.
 * 
 * Si no se encuentra ningún estudiante con saldo menor al valor indicado,
 * se muestra un mensaje de error.
 * 
 * @note Utiliza la función auxiliar imprimirConFormato() para mostrar
 * los títulos con un formato uniforme en consola.
 */

void buscarSaldoMenor() {
    vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("data/estudiantes.dat");

    if(estudiantes.empty()) {
        cout << "Aun no hay productos en el inventario."; return;
    }

    cout << "\n=======================================================\n";
    imprimirConFormato("ESTUDIANTES CON SALDO < 5000");
    cout << "\n=======================================================\n";
    cout << "| Cedula       | Nombre            | Grado | Saldo  |\n";
    cout << "-------------------------------------------------------\n";

    bool encontrado = false;
    for (Estudiante &e : estudiantes) {
        if (e.monto < 5000) {
            cout << "| " << e.id 
                 << " | " << setw(16) << left << e.name 
                 << " | " << setw(5) << left << e.grado 
                 << " | " << setw(6) << right << e.monto 
                 << " |\n";
            encontrado = true;
        }
    }
    cout<<"\n=======================================================\n";
    if (!encontrado) {
        cout << "\n=======================================================\n";
        imprimirConFormato("No hay registros menores a 5000");
        cout << "\n=======================================================\n";
    }
}

#endif

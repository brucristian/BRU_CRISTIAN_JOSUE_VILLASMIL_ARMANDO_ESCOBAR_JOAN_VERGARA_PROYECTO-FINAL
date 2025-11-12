#ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
#include "../controller/estudiantecontroller.h"
#include <iostream>

using namespace std;

//	estudiantes...

	void registrarEstudent () {
		system ("cls");
		bool validation = false;
		char fullName [50];
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("Digite la cedula"); 
			getChar ("Ingrese su nombre completo", fullName, 50);
			int section = getInt ("Digite su grado");	
			double initial = getDouble ("Ingrese el monto inicial");
			
			validation = registroEstudiante(id, fullName, section, initial);
			
		}while(!validation);	
		cout << "\nRegistro exitoso :)";
	}
	
	void RecargarBalance () {
		
		system("cls");
		bool validation = false;
		do {
			
			cout << "========== Recargar Saldo Estudiantil ==========";
			long long id = getNumberLong ("\nDigite su cedula");
			double recarga = getDouble ("Ingrese el monto que desea recargar a su saldo estudiantil");
			validation = recargaEstudiante (id, recarga);
			
		}while (!validation);
		
		cout << "Su dinero ha sido recargado con exito!";
	}	

#endif

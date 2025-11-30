#ifndef ESTUDIANTESVEWS_H
#define ESTUDIANTESVEWS_H
#include "../utils/getters.h"
#include "../controller/estudiantecontroller.h"
#include <iostream>
#include <vector>

using namespace std;

//	estudiantes...

	void getBadStudents1 (vector <int> &error, long long &id, char (&fullName) [50],int &section, double &initial){
		
		for (int i = 0; i < error.size(); i++){
			
			if (i == 1) {
				cout << "\nLa cedula del estudiante ingresado es incorrecta";
				id = getNumberLong ("\nDigite la cedula nuevamente");
				
			}else if (i == 2){
				cout << "\nEl mombre del estudiante ingresado es incorrecto";
				getChar ("\nIngrese el nombre nuevamente", fullName, 50);
				
			}else if (i == 3){
				cout << "\nEl grado es incorrecto";
				int value = getInt ("\nDigite el grado nuevamente");
				
			}else if (i == 4){
				cout << "\nEl monto inicial ingresado es invalido";
				double initial = getDouble ("\nIngrese el monto inicial nuevamente");
				
			}
		}
		error.clear();		
	} 
	
	void getBadStudents2 (vector <int> &error, long long &id, double recarga){
		
		for (int i = 0; i < error.size(); i++){
			
			if (i == 1) {
				cout << "\nLa cedula del estudiante ingresado es incorrecta";
				id = getNumberLong ("\nDigite la cedula nuevamente");
					
			}else {
				cout << "\nEl valor de la recargar es invalido"; 
				recarga = getDouble ("Ingrese el monto que desea recargar a su saldo estudiantil nuevamente");
				
			}
		}
		error.clear();		
	} 

	void registrarStudent() {
		system ("cls");
		char fullName [50];
		vector <int> error; 
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("\nDigite la cedula"); 
			getChar ("\nIngrese su nombre completo", fullName, 50);
			int section = getInt ("\nDigite su grado");	
			double initial = getDouble ("\nIngrese el monto inicial");
			
			error = registroEstudiante(id, fullName, section, initial);
			if (!error.empty()){
				getBadStudents1 (error, id, fullName, section, initial);
			}
			
		}while(!error.empty());
		cout << "\nRegistro exitoso :)";
	}
	
	void RecargarBalance () {
		
		system("cls");
		vector <int> validation;
		vector <int> error;
		do {
			
			cout << "========== Recargar Saldo Estudiantil ==========";
			long long id = getNumberLong ("\nDigite su cedula");
			double recarga = getDouble ("\nIngrese el monto que desea recargar a su saldo estudiantil");
			error = recargaEstudiante (id, recarga);
			if (!error.empty()) {
				getBadStudents2 (error, id, recarga);
			}
			
		}while (!error.empty());
		
		cout << "\nSu dinero ha sido recargado con exito!";
	}
	
	void eliminarStudent () {
		system("cls");
		bool validation = false;
		do {
			
			cout << "========== Eliminar Estudiante ==========";
			long long id = getNumberLong ("\nDigite la cedula");
			validation = eliminarEstudiante (id);
			
		}while (!validation);
		
		cout << "\nEstudiante eliminado con exito!";
	}	

#endif

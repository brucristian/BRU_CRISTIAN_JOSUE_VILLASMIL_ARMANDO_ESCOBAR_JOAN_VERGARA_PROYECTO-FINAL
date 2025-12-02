#ifndef ESTUDIANTESVEWS_H
#define ESTUDIANTESVEWS_H
#include "../utils/getters.h"
#include "../controller/estudiantecontroller.h"
#include <iostream>
#include <vector>

using namespace std;

//	estudiantes...

	void registrarStudent() {
		
		char fullName [50];
		vector<int> error = {5}; 
		long long id; int section; double initial;
		
		system ("cls");
		cout << "\n==================================================\n";
        cout << "||              Registrar Estudiante            ||\n";
        cout << "==================================================\n";

		do {			

			for(int &number : error) {
				if(number == 5)
					error = {1, 2, 3, 4};
			}
			
			for(int &number : error) {
				switch(number) {
					case 1:
						id = getNumberLong ("\nDigite la cedula"); break;
					case 2:
						getChar ("\nIngrese su nombre completo", fullName, 50); break;
					case 3:
						section = getInt ("\nDigite su grado");	break;
					case 4:
						initial = getDouble ("\nIngrese el monto inicial"); break;
				}
			}
			
			error = registroEstudiante(id, fullName, section, initial);
			
		}while(!error.empty());
		cout << "\n==================================================\n";
        imprimirConFormato("        Registro exitoso                    \n");
        cout << "==================================================\n";

	}
	
	void RecargarBalance () {
		
		system("cls");
		vector <int> error = {3};
		long long id; double recarga;

		cout << "\n==================================================\n";
        cout << "||           Recargar Saldo Estudiantil         ||\n";
        cout << "==================================================\n";

		do {

			for(int &number : error) {
				if(number == 3)
					error = {1, 2};
			}

			for(int &number : error) {
				switch(number) {
					case 1:
						id = getNumberLong ("\nDigite su cedula"); break;
					case 2:
						recarga = getDouble ("\nIngrese el monto que desea recargar a su saldo estudiantil"); break;
				}
			}

			error = recargaEstudiante (id, recarga);
			
		} while (!error.empty());
		
		cout << "\n==================================================\n";
        imprimirConFormato("       Su dinero ha sido recargado con exito!      \n");
        cout << "==================================================\n";

	}
	
	void eliminarStudent () {
		system("cls");
		bool validation = false;
		do {
			
		cout << "\n==================================================\n";
        cout << "||               Eliminar Estudiante           ||\n";
        cout << "==================================================\n";

			long long id = getNumberLong ("\nDigite la cedula");
			validation = eliminarEstudiante (id);
			
		}while (!validation);
		
		cout << "\n==================================================\n";
        imprimirConFormato ("            Estudiante eliminado con exito!       \n");
        cout << "==================================================\n";

	}

	void consultStudent() {
		system("cls");
		cout << "\n==================================================\n";
        cout << "||             Consultar Estudiante             ||\n";
        cout << "==================================================\n";

		long long id = getNumberLong ("\nDigite la cedula del estudiante");
		consultarEstudiante(id);
		
	}

#endif
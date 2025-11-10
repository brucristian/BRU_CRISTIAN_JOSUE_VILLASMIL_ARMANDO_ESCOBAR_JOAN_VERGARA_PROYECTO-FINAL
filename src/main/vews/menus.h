#ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
#include "../controller/estudiantecontroller.h"
#include <iostream>

using namespace std;


//	menu
	int menuPricipal () {

		system("cls");
			cout << "========== Bienvenidos al Menu Principal para nameproyect ==========";
	
			cout << "1.- Registrar estudiante"
			<< "2.- Agregar producto al inventario"
			<< "3.- Realizar compra"
			<< "4.- Recargar saldo del estudiante"
			<< "5.- Eliminar estudiante"
			<< "6.- consultas"
			<< "7.- Salir";
			int op = getInt ("Digite una opcion"); 
				
	}


//	estudiantes...
	
	char registrarEstudent () {
		system ("cls");
		bool validation = false;
		char fullName [50];
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("Digite la cedula"); 
			getChar ("Ingrese su nombre completo", fullName, 50);
			int section = getInt ("cual es su grado/semestre");	
			double initial = getDouble ("Ingrese el monto inicial");
			
			validation = registroEstudiante(id, fullName, section, initial);
			
		}while(!validation);	
	}
	
	double RecargarBalance () {
		
	}	

	char consultas () {
		system("cls");
		bool validation = false;
		char op [1];
		
		do{
			cout << "========== Consultas ==========";
		
			cout << "A.- Consultar estudiante"
			<< "B.- Inventario de los productos"
			<< "C.- Estudiantes con saldo menor a $5.000"
			<< "D.- Generar archivo.txt con los estudiantes eliminados";
			getChar ("opcion",op,1);
		
		}while (!validation);
	}






#endif

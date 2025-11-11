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
	
			cout << "\n1.- Registrar estudiante"
			<< "\n2.- Agregar producto al inventario"
			<< "\n3.- Realizar compra"
			<< "\n4.- Recargar saldo del estudiante"
			<< "\n5.- Eliminar estudiante"
			<< "\n6.- consultas"
			<< "\n7.- Salir";
			int op = getInt ("\nDigite una opcion");
			return op; 
				
	}


//	estudiantes...
	
	void registrarEstudent () {
		system ("cls");
		bool validation = false;
		char fullName [50];
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("\nDigite la cedula"); 
			getChar ("\nIngrese su nombre completo", fullName, 50);
			int section = getInt ("\ncual es su grado/semestre");	
			double initial = getDouble ("\nIngrese el monto inicial");
			
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

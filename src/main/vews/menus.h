 #ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
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

	char menuSecundario() {
		char op;
		system("cls");
		cout << "a.- Consultar un estudiante"
		<< "\nb.- Listar todos los productos en inventario"
		<< "\nc.- Estudiantes con saldo menor a $5000"
		<< "\nd.- Generar archivo de retiros.txt con los estudiantes eliminados"
		<< "\nDigite una opcion: "; cin >> op;

		return op;
	}

#endif
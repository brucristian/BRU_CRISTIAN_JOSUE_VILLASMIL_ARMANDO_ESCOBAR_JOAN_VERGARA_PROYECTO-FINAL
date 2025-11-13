#ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
#include "../controller/productocontroller.h"
#include <iostream>

using namespace std;

	void registrarProducto () {
		system ("cls");
		bool validation = false;
		char fullName [50];
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("Digite el codigo del producto"); 
			getChar ("Ingrese el nombre del producto", fullName, 50);
			double value = getDouble ("Digite el valor del producto");	
			int disponible = getInt ("Ingrese la cantidad stock del producto");
			
			validation = agregarProducto(id, fullName, value, disponible);
			
		}while(!validation);
		
		cout << "\nRegistro exitoso)";
	}

		

#endif

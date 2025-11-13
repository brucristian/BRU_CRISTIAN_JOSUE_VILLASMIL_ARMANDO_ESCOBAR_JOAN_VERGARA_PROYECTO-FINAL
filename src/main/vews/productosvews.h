#ifndef PRODUCTOSVEWS_H
#define PRODUCTOSVEWS_H
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
			
			long long id = getNumberLong ("\nDigite el codigo del producto"); 
			getChar ("\nIngrese el nombre del producto", fullName, 50);
			double value = getDouble ("\nDigite el valor del producto");	
			int disponible = getInt ("\nIngrese la cantidad stock del producto");
			
			validation = agregarProducto(id, fullName, value, disponible);
			
		}while(!validation);
		
		cout << "\nRegistro exitoso)";
	}

		

#endif

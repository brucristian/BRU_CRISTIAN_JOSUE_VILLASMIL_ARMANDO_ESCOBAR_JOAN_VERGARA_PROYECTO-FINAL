#ifndef PRODUCTOSVEWS_H
#define PRODUCTOSVEWS_H
#include "../utils/getters.h"
#include "../controller/productocontroller.h"
#include <iostream>

using namespace std;

	void registrarProducto () {
		vector<int> error = {5};
		long long id; double value; int disponible; char fullName [50];

		system ("cls");
		cout << "========== Registrar Producto ==========";
		do {			
			for(int &number : error) {
				if(number == 5) 
					error = {1, 2, 3, 4};
			}
			
			for(int &number : error) {
				switch(number) {
					case 1:
						id = getNumberLong ("\nDigite el codigo del producto"); break;
					case 2:
						getChar ("\nIngrese el nombre del producto", fullName, 50); break;
					case 3:
						value = getDouble ("\nDigite el valor del producto"); break;
					case 4:
						disponible = getInt ("\nIngrese la cantidad stock del producto"); break;
				}
			}
			
			error = agregarProducto(id, fullName, value, disponible);
			
		}while(!error.empty());
		
		cout << "\nRegistro exitoso)";
	}

		

#endif

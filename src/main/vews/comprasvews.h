#ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
#include "../controller/compracontroller.h"
#include <iostream>

using namespace std;

	void buy () {
		
		system("cls");
		bool validation = false;
		
		do {
			
			cout << "========== Compras ==========";
			
			long long cedula = getDouble ("Ingrese su cedula");
			long long id = getNumberLong ("\nIngrese el codigo del producto");
			validation = compra (cedula, id);
			
		}while (!validation);
		
		cout << "\nSu compra a sido realizada con exito";
	}

#endif

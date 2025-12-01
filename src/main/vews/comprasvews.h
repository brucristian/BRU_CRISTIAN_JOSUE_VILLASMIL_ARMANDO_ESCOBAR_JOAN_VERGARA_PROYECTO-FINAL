#ifndef COMPRASVEWS_H
#define COMPRASVEWS_H

#include "../utils/getters.h"
#include "../controller/compracontroller.h"
#include <iostream>

using namespace std;

	void buy () {
		
		bool validation = false;
		
		do {
			system("cls");
			cout << "========== Compras ==========";
			
			long long cedula = getNumberLong ("\nIngrese su cedula");
			long long id = getNumberLong ("\nIngrese el codigo del producto");
			validation = compra (cedula, id);
			
		}while (!validation);
		
		cout << "\nSu compra a sido realizada con exito";
	}

#endif
#ifndef PRODUCTOSVEWS_H
#define PRODUCTOSVEWS_H
#include "../utils/getters.h"
#include "../controller/productocontroller.h"
#include <iostream>

using namespace std;

	void getBadProducts (vector <int> &error, long long &id, char (&fullName) [50],double &value, int &disponible){
		
		for (int i = 0; i < error.size(); i++){
			
			if (i == 1) {
				cout << "\nEl codigo del producto ingresado es incorrecto";
				id = getNumberLong ("\nDigite el codigo del producto nuevamente");
				
			}else if (i == 2){
				cout << "\nEl mombre del producto ingresado es incorrecto";
				getChar ("\nIngrese el nombre del producto nuevamente", fullName, 50);
				
			}else if (i == 3){
				cout << "\nEl valor del producto es invalido";
				double value = getDouble ("\nDigite el valor del producto nuevamente");
			}else {
				cout << "\nLa cantidad stock es invalida";
				int disponible = getInt ("\nIngrese la cantidad stock del producto nuevamente");
			}
		}
		error.clear();		
	} 

	void registrarProducto () {
		system ("cls");
		char fullName [50];
		vector <int> error;
		
		do {			
			cout << "========== Registrar Estudiante ==========";	
			
			long long id = getNumberLong ("\nDigite el codigo del producto"); 
			getChar ("\nIngrese el nombre del producto", fullName, 50);
			double value = getDouble ("\nDigite el valor del producto");	
			int disponible = getInt ("\nIngrese la cantidad stock del producto");
			
			error = agregarProducto(id, fullName, value, disponible);
			if (!error.empty()){
				getBadProducts (error, id, fullName, value, disponible);
			}
			
		}while(!error.empty());
		
		cout << "\nRegistro exitoso)";
	}

		

#endif

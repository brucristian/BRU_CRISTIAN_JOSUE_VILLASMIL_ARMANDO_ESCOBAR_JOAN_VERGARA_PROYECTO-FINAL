#ifndef PRODUCTOCONTROLLER_H
#define PRODUCTOCONTROLLER_H

#include "../model/producto.h"
#include "../utils/filemanager.h"
#include "../utils/getters.h"
#include "../utils/validaciones.h"
#include<cstring>
#include <iomanip>

vector<int> agregarProducto(long long &id, char name[50], double &precio, int &monto){
	vector<int> error;

    vector<Producto> productos = readBinaryFile <Producto>("data/productos.dat");
    
    bool exist = existsById<long long, Producto>("data/productos.dat", id);
    if (!productos.empty() && exist) {
        cout << "\nEl codigo de producto {" << id << "} ya se encuentra ocupada.\n";
        error.push_back(1);
    }

    if(precio < 0){
    	cout << "\nNo puede ingresar un precio negativo\n";
		error.push_back(3);
	}
	
    if(monto < 0){
    	cout << "\nNo puede ingresar una cantidad negativa\n";
		error.push_back(4);
	}

    Producto p;

    p.id = id;
    strcpy(p.name, name);
    p.precio = precio;
    p.monto = monto;

    if(!error.empty())
        return error;

    if(!writeBinaryFile <Producto> ("data/productos.dat", p)) {
        cout << "Ocurrio un error al registrar los datos porfavor intentelo nuevamente.";
        error.push_back(5);
    }
    
    return error;
}

void imprimirProductos(){

    vector<Producto> productos = readBinaryFile <Producto>("data/productos.dat");

    if(productos.empty()) {
        cout << "Aun no hay productos en el inventario."; return;
    }

     cout << "\n==============================================\n";
        imprimirConFormato("PRODUCTOS EN EL INVENTARIO");
        cout << "==============================================\n";
        cout << "| Codigo       | Nombre            | Precio | Cantidad  |\n";
        cout << "----------------------------------------------\n";

    for(int i = 0; i< productos.size(); i++){

        cout << "| " << productos[i].id 
                 << " | " << setw(16) << left << productos[i].name 
                 << " | " << setw(5) << left << productos[i].precio 
                 << " | " << setw(6) << right << productos[i].monto 
                 << " |\n";
    }

}



#endif

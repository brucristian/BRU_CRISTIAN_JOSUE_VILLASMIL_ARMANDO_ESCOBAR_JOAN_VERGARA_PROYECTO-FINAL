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

        cout << "\n==================================================\n";
        imprimirConFormato("CODIGO DUPLICADO");
        cout << "==================================================\n";
        cout << "     El codigo de producto {" << id <<"}\n";
        cout << "     Ya se encuentra ocupado.\n";
        cout << "==================================================\n";

        error.push_back(1);
    }

    if(precio < 0){

    	cout << "\n==================================================\n";
        imprimirConFormato("ERROR DE PRECIO");
        cout << "==================================================\n";
        cout << "  No puede ingresar un precio negativo.\n";
        cout << "==================================================\n";

		error.push_back(3);
	}
	
    if(monto < 0){
    	cout << "\n==================================================\n";
        imprimirConFormato("ERROR DE CANTIDAD");
        cout << "==================================================\n";
        cout << "  No puede ingresar una cantidad negativa.\n";
        cout << "==================================================\n";

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
        
       cout << "\n==================================================\n";
       imprimirConFormato("ERROR DE REGISTRO");
       cout << "==================================================\n";
       cout << "  Ocurrió un error al registrar los datos    \n";
       cout << "  por favor intente nuevamente.              \n";
       cout << "==================================================\n";

        error.push_back(5);
    }
    
    return error;
}

void imprimirProductos(){

    vector<Producto> productos = readBinaryFile <Producto>("data/productos.dat");

    if(productos.empty()) {
        cout << "Aun no hay productos en el inventario."; return;
    }

     cout << "\n========================================================\n";
        imprimirConFormato("PRODUCTOS EN EL INVENTARIO");
        cout << "=========================================================\n";
        cout << "| Codigo       | Nombre      | Precio | Cantidad  |\n";
        cout << "----------------------------------------------\n";

    for(int i = 0; i< productos.size(); i++){

        cout << "| " << productos[i].id 
                 << " | " << setw(16) << left << productos[i].name 
                 << " | " << setw(5) << left << productos[i].precio 
                 << " | " << setw(6) << right << productos[i].monto 
                 << " |\n";
        cout << "=========================================================\n";
    }

}



#endif
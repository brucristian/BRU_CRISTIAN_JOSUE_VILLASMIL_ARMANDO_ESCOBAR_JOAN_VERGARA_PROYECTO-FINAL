#ifndef PRODUCTOCONTROLLER_H
#define PRODUCTOCONTROLLER_H

#include "../model/producto.h"
#include "../utils/filemanager.h"
#include "../utils/getters.h"
#include<cstring>
#include <iomanip>

bool agregarProducto(long long &id, char name[50], double &precio, int &monto){

    vector<Producto> copia_momentanea = readBinaryFile <Producto>("data/productos.dat");
    
    for(int i=0;i<copia_momentanea.size();i++){

        if(id==copia_momentanea[i].id){

            return false;
        }

    }

    if(precio<0){return false;}
    if(monto<0){return false;}

    Producto informacion_a_pasar;

    informacion_a_pasar.id = id;
    strcpy(informacion_a_pasar.name, name);
    informacion_a_pasar.precio = precio;
    informacion_a_pasar.monto = monto;

    return writeBinaryFile <Producto> ("data/productos.dat", informacion_a_pasar);
    

}

void imprimirProductos(){

    vector<Producto> copia_momentanea = readBinaryFile <Producto>("data/productos.dat");

     cout << "\n==============================================\n";
        imprimirConFormato("PRODUCTOS EN EL INVENTARIO");
        cout << "==============================================\n";
        cout << "| Codigo       | Nombre            | Precio | Cantidad  |\n";
        cout << "----------------------------------------------\n";

    for(int i=0;i<copia_momentanea.size();i++){

        cout << "| " << copia_momentanea[i].id 
                 << " | " << setw(16) << left << copia_momentanea[i].name 
                 << " | " << setw(5) << left << copia_momentanea[i].precio 
                 << " | " << setw(6) << right << copia_momentanea[i].monto 
                 << " |\n";
    }

}



#endif
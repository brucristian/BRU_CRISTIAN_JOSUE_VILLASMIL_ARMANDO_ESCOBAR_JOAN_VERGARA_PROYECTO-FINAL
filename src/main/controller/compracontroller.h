#ifndef COMPRACONTROLLER_H
#define COMPRACONTROLLER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>

#include "../model/compra.h"
#include "../model/producto.h"
#include "../model/estudiante.h"
#include "estudiantecontroller.h"
#include "../utils/filemanager.h"
#include "../utils/validaciones.h"
#include "../utils/getters.h"
#include "../utils/messages.h"


using namespace std; 

//	Funcion para btener la fecha actual
	string obtenerFecha() {
	    time_t t = time(0);
	    tm* now = localtime(&t);
	
	    char buffer[80];
	    strftime(buffer, sizeof(buffer), "%d/%m/%Y", now); 
	    return string(buffer);
	}
	
//	funcion que valida si la compra fue exitosa
	bool compra (long long &id, long long &codigo){	
	
		Compra compra;		
		
		if (!existsById<long long, Estudiante>("data/estudiantes.dat", id)) {
			
	       studentNotFoundError();

	        return false;
	    } 
	    
   		Estudiante e = buscarEstudiante(id);
    	
    	
    	vector<Producto> productos = readBinaryFile <Producto>("data/productos.dat");
    	
    	for(int i=0;i<productos.size();i++){
    		
	    	if (codigo == productos[i].id) {
	    		
		    	if(productos[i].monto<=0){
		    		unavaibleProductError();
					return true;
				}else {
					
					if (e.monto < productos[i].precio){
						insufficientFoundsError(productos[i].precio);
						return true;

					}else {
						restarSaldo (e.id, productos[i].precio);
						compra.valor = productos[i].precio;
					}
							
					updateBinaryFile<Producto, int>("data/productos.dat", productos[i], productos[i].monto - 1);
					strcpy(compra.name, productos[i].name); 
				}	
				strcpy(compra.fecha, obtenerFecha().c_str());
				compra.id = e.id;
		
				if(writeBinaryFile <Compra> ("data/compras.dat", compra)) {
					successfullyBuy();
					return true;
				}
    		}	    
		}
		
		codeNotFoundError(codigo);

    	return false;
	}
	


#endif
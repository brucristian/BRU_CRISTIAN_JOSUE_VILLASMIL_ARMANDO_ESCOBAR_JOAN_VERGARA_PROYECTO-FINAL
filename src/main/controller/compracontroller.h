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
    	
    	
    	vector<Producto> copia_momentary = readBinaryFile <Producto>("data/productos.dat");
    	
    	for(int i=0;i<copia_momentary.size();i++){
    		
	    	if (codigo == copia_momentary[i].id) {
	    		
		    	if(copia_momentary[i].monto<=0){
		    		unavaibleProductError();
					return true;
				}else {
					
					if (e.monto < copia_momentary[i].precio){
						insufficientFoundsError(copia_momentary[i].precio);
						return true;

					}else {
						restarSaldo (e.id, copia_momentary[i].precio);
						compra.valor = copia_momentary[i].precio;
					}
							
					updateBinaryFile<Producto, int>("data/productos.dat", copia_momentary[i], copia_momentary[i].monto - 1);
					strcpy(compra.name, copia_momentary[i].name); 
				}	
				compra.fecha = obtenerFecha();
				compra.id = e.id;
		
				return writeBinaryFile <Compra> ("data/compras.dat", compra);
    		}	    
		}
		
		codeNotFoundError(codigo);

    	return false;
	}
	


#endif
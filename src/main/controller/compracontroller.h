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
	        cout << "\nNo tenemos registrado a un estudiante con la cedula ingresada en nuestra base de datos; ";
	        return false;
	    } 
	    
   		Estudiante e = buscarEstudiante(id);
    	
    	
    	vector<Producto> copia_momentary = readBinaryFile <Producto>("data/productos.dat");
    	
    	for(int i=0;i<copia_momentary.size();i++){
    		
	    	if (id == copia_momentary[i].id) {
	    		
		    	if(copia_momentary[i].monto<=0){
		    		cout << "\nLo sentimos, no tenemos este producto disponible en estos momentos"; 
					return false;
				}else {
					
					if (e.monto < copia_momentary[i].precio){
						cout << "\nNo se pudo realizar su compra dado que su saldo estudiantil es menor al precio del producto";
						cout << "\nValor del producto: " << copia_momentary[i].precio;
						return false; 
					}else {
						restarSaldo (e.id, copia_momentary[i].precio);
						compra.valor = copia_momentary[i].precio;
					}
								
					updateBinaryFile<Producto, int>("data/productos.dat", copia_momentary[i], copia_momentary[i].monto - 1);
					strcpy(compra.name, copia_momentary[i].name); 
				}	
				compra.fecha = obtenerFecha();
				compra.id = e.id;
			
				return writeBinaryFile <Compra> ("data/compra.dat", compra);
    		}
    			    
		}
		cout << "\nLa cedula ingresada no esta en nuestra base de datos";
		return false; 
	}
	


#endif

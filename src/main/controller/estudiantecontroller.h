#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "../model/estudiante.h"
#include "../utils/filemanager.h"


using namespace std;


Estudiante buscarEstudiante(long long id){
	 vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("../data/estudiantes.dat");
	 Estudiante e;
	
	for(Estudiante &p : estudiantes){
	    if(p.id == id){
	    	e = p;
	    	break;
		}
	}
   return e;
}



bool registroEstudiante(long long &id, char name[50], int &grado, double &saldo){
    vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("../data/estudiantes.dat");
    
    if(!estudiantes.empty()){
    	
       for(Estudiante &e : estudiantes){
    	
    	  if(id == e.id) return false; 	
       	
       }
	
	}
    
	if(saldo < 5000) return false;
	
	
	
	Estudiante e;
	
	e.grado = grado;
	e.id = id;
	strcpy(e.name, name);
	e.saldo = saldo;
	
	
	
    return writeBinaryFile("../data/estudiantes.dat", e);
		
}

bool recargaEstudiante(long long id, double recarga){
	 vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("../data/estudiantes.dat");
	 Estudiante e;
	 
	 
	 if(recarga>500000 || recarga<0){
	   cout<<"\n*****Monto de recarga no valido****"<<endl;
	   return false;	
	 }
	
	
    e = buscarEstudiante(id);
    
	return updateBinaryFile("../data/estudiantes.dat", e, recarga);
}

bool eliminarEstudiante(long long id){
	 vector<Estudiante> estudiantes = readBinaryFile<Estudiante>("../data/estudiantes.dat");
	 Estudiante e;
	 
	 e = buscarEstudiante(id);
	 
	 return deleteOnBinaryFile("../data/estudiantes.dat", e);
}

       

#endif

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <vector>
#include "convertions.h"
#include "filemanager.h"


// Funcion para a�o bisiesto
bool bisiesto(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 * @brief Valida si una fecha en formato DD-MM-YY es correcta.
 * 
 * Verifica que el d�a, mes y a�o sean v�lidos seg�n el calendario, 
 * incluyendo el manejo de a�os bisiestos.
 * 
 * @param data Fecha a validar (formato "DD-MM-YY").
 * @return true Si la fecha es v�lida.
 * @return false Si la fecha no cumple con los valores permitidos.
 */

bool dateValidation(const string &data) {
	vector<int> date;
	
	int position = 0;
	for(int i = 0; i < 3; i++) {
		date.push_back(integerConvertion(data.substr(position, 2)));
		position += 3;
	}
	if(date[1] < 1 || date[1] > 12 || date[2] < 0) return false;
	
	int day;
	switch (date[1]) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day = 31; break;
			
		case 4: case 6: case 9: case 11:
			day = 30; break;
			
		case 2:
			if(bisiesto(date[2])) 
				day = 29;
			else 
				day = 28;
				
			break;
	}
	
	if(date[0] < 1 || date[0] > day) return false;
	
	return true;
}

/**
 * @brief Verifica si existe un registro con un ID dado en un archivo binario.
 * 
 * Lee todos los registros del archivo y retorna true si alguno coincide
 * con el ID especificado.
 * 
 * @tparam idType Tipo del ID a buscar.
 * @tparam T Tipo del registro (debe tener un campo p�blico `id`).
 * @param fileName Nombre del archivo binario.
 * @param id ID que se desea verificar.
 * @return true Si el ID existe, false en caso contrario.
 */

template <typename idType, typename T>
bool existsById(const string &fileName, idType &id) {
	vector<T> data = readBinaryFile<T>(fileName);
	
	for(T regis : data) {
		if(regis.id == id) 
			return true;
	}
	
	return false;
}



#endif

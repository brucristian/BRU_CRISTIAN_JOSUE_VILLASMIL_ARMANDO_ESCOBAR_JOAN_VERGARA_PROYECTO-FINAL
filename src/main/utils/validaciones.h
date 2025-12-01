#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <vector>

#include "filemanager.h"

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
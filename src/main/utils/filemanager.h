#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <cstring>
#include <fstream>
#include <vector>

using namespace std;


/**
 * @brief Escribe un registro en un archivo binario.
 * 
 * Esta función abre un archivo binario en modo append y escribe
 * el dato proporcionado al final del archivo. Si el archivo no
 * existe, se crea automáticamente.
 *
 * @tparam T Tipo de dato a escribir ( struct ).
 * @param fileName Nombre del archivo binario.
 * @param dato Registro a escribir en el archivo.
 * @return true Si la operación fue exitosa.
 * @return false Si no se pudo abrir el archivo.
 */

template <typename T>
bool writeBinaryFile(const string &fileName, const T &dato) {
	ofstream file(fileName, ios::binary | ios::app);
	
	if(!file.is_open()) { return false; }
	
	file.write(reinterpret_cast<const char*>(&dato), sizeof(dato));
	file.close();
	
	return true;
}


/**
 * @brief Lee un archivo binario y retorna todos los registros.
 *
 * Esta funcion abre un archivo binario y lee todos los registros
 * del tipo T, guardandolos en un vector. Si el archivo no existe
 * o esta vacio, retorna un vector vacio.
 *
 * @tparam T Tipo de dato a leer ( struct ).
 * @param fileName Nombre del archivo binario.
 * @return vector<T> Vector con los registros leidos.
 */
 
template <typename T>
vector<T> readBinaryFile(const string &fileName) {
	vector<T> data;
	T dato;
	
	ifstream file(fileName, ios::binary | ios::in);	
	if(!file.is_open()) { return data; }
	
	while(file.read(reinterpret_cast<char*>(&dato), sizeof(dato))) {
		data.push_back(dato);
	}
	file.close();
	
	return data;
	
}


/**
 * @brief Elimina un registro específico de un archivo binario.
 *
 * Esta función plantilla permite eliminar un elemento de tipo T almacenado en un
 * archivo binario. Para lograrlo, primero lee todos los registros existentes en
 * un vector temporal, luego reescribe el archivo desde cero,
 * omitiendo aquel registro cuyo atributo `id` coincida con el del registro
 * buscado.
 *
 * @tparam T Tipo de dato del registro. ( struct )
 *          que pueda escribirse y leerse en binario, y debe contener
 *          obligatoriamente un atributo público llamado `id`.
 *
 * @param fileName Nombre del archivo binario en el cual se realizará la operación.
 * @param dato Registro que contiene el `id` del elemento que se busca eliminar.
 *
 * @return true Si el archivo se abrió correctamente y la operación se ejecutó.
 * @return false Si el archivo no pudo abrirse o si ocurrió un error.
 */


template <typename T>
bool deleteOnBinaryFile(const string &fileName, const T &dato) {
	vector<T> data = readBinaryFile<T>(fileName);
	
	ofstream file(fileName, ios::binary | ios::trunc);
	if(!file.is_open()) { return false; }
	
	for(const T &d : data) {
		if(d.id != dato.id) {
			file.write(reinterpret_cast<const char*>(&d), sizeof(T));
		}
	}
	file.close();
	
	return true;
}


/**
 * @brief Actualiza el registro con el mismo ID dentro del archivo binario.
 *
 * Lee todos los registros, modifica el que coincide con object.id
 * cambiando el valor del campo monto, y reescribe el archivo completo.
 *
 * @tparam Type1 Tipo del registro almacenado en el archivo.
 * @tparam Type2 Tipo del valor de cambio.
 * @param fileName Nombre del archivo binario.
 * @param object Registro que contiene el ID del elemento a actualizar.
 * @param change Nuevo valor para el campo monto.
 * @return true Si se pudo abrir/escribir el archivo, false en caso contrario.
 */


template <typename Type1, typename Type2>
bool updateBinaryFile(const string &fileName, const Type1 &object, const Type2 &change) {
	vector<Type1> data = readBinaryFile<Type1>(fileName);
	
	ofstream file(fileName, ios::binary | ios::trunc);
	if(!file.is_open()) { return false; }
	
	for(Type1 d : data) {
		if(d.id == object.id) {
			d.monto = change;
		}
		
		file.write(reinterpret_cast<const char*>(&d), sizeof(d));
	}
	file.close();
	
	return true;
}
#endif

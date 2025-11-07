#ifndef FILEMANAGER_H
#defina FILEMANAGER_H

#include <cstring>
#include <fstring>
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

#endif

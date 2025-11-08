#ifndef CONVERTIONS_H
#define CONVERTIONS_H

#include <string>
#include <sstream>

using namespace std;

/**
 * @brief Convierte una cadena numérica a un entero.
 * 
 * Utiliza un flujo de cadena (stringstream) para transformar 
 * un valor de tipo string en un número entero.
 * 
 * @param number Cadena que contiene el número a convertir.
 * @return int Valor entero equivalente al contenido de la cadena.
 */

int integerConvertion(const string &number) {
	int n;
	
	stringstream ss(number);
	ss >> n;
	
	return n;
}

#endif

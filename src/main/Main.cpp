// Codigos: 6902510029, 6902510017, 6902510023, 6902510055

#include <iostream>
#include "utils/getters.h"
#include "model/estudiante.h"
#include "controller/estudiantecontroller.h"

using namespace std;



int main() {
	
	// Son pedidos por consola (Lo hace josue desde views)
	char name[50] = "Joan Sebastian";
	long long cedu = 1043;
	int grado = 2;
	double saldo = 5000;
	
	char nombre [50] = "Armando";
	long long cc = 69020;
	int grado1 = 4;
	double saldo1 = 7000;
	
	char nombre2 [50] = "Cristian Bru";
	long long cc2 = 69025;
	int grado2 = 3;
	double saldo2 = 7500;
	
	
	registroEstudiante(cc, nombre, grado1, saldo1);
	
	
	
	int option;
	do {
		long long cedula = 0;
		
		cout << "\n\n1. Recargar Saldo"
		<< "\n2. Ver estudiante\n";
		option = getInt("Digite una opcion");
		
		double monto;
		cedula = getInt("Digite la cedula");
		switch (option) {
			case 1:
				monto = getDouble("Digite el monto");
				cout << recargaEstudiante(cedula, monto) << endl;
				break;
			case 2:
				Estudiante e = buscarEstudiante(cedula);
				cout << "\nCedula: " << e.id;
				cout << "\nNombre: " << e.name;
				cout << "\nSaldo: " << e.monto;
				
		}
		
	} while(option != 3);
}

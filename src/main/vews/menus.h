 #ifndef MENUS_H
#define MENUS_H
#include "../utils/getters.h"
#include <iostream>

using namespace std;


//	menu
	int menuPricipal () {

		system("cls");
			string nameproyect = "Estumercado";

            cout << "\n============================================================\n";
            cout << "||                                                        ||\n";
            cout << "||            BIENVENIDOS AL MENU PRINCIPAL               ||\n";
            cout << "||                  " << nameproyect << "                           ||\n";             
            cout << "||                                                        ||\n";
            cout << "||                                                        ||\n";
            cout << "============================================================\n";
            cout << "||  1.- Registrar estudiante                              ||\n";
            cout << "||  2.- Agregar producto al inventario                    ||\n";
            cout << "||  3.- Realizar compra                                   ||\n";
            cout << "||  4.- Recargar saldo del estudiante                     ||\n";
            cout << "||  5.- Eliminar estudiante                               ||\n";
            cout << "||  6.- Consultas                                         ||\n";
            cout << "||  7.- Salir                                             ||\n";
            cout << "============================================================";
			int op = getInt ("\nDigite una opcion");
			return op; 
				
	}

	char menuSecundario() {
		char op;
		system("cls");
		cout << "\n============================================================\n";
        cout << "||                     MENU DE CONSULTAS                   ||\n";
        cout << "============================================================\n";
        cout << "||  a. Consultar un estudiante                             ||\n";
        cout << "||  b. Listar todos los productos en inventario            ||\n";
        cout << "||  c. Estudiantes con saldo menor a $5000                 ||\n";
        cout << "||  d. Generar archivo 'retiros.txt' con                   ||\n";
        cout << "||       estudiantes eliminados                            ||\n";
        cout << "============================================================";
        imprimirConFormato("\nDigite una opcion: ");

        cin >> op;
		return op;
	}

#endif
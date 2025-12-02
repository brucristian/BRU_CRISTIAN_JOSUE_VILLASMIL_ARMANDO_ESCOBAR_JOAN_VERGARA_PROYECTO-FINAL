// Codigos: 6902510029, 6902510017, 6902510023, 6902510055

#include <iostream>
#include "utils/getters.h"
#include "views/menus.h"
#include "views/productosviews.h"
#include "views/comprasviews.h"
#include "views/estudiantesviews.h"
#include "controller/productocontroller.h"
#include "controller/estudiantecontroller.h"

using namespace std;



int main() {		
	
	int option; char op;
	do {
		option = menuPricipal();
		
		switch (option) {
			case 1:
				registrarStudent(); break;
			case 2:
				registrarProducto(); break;
			case 3:
				buy(); break;
			case 4:
				RecargarBalance(); break;
			case 5:
				eliminarStudent(); break;
			case 6:
				op = menuSecundario();
				switch (op) {
				case 'a':
					consultStudent(); break;
				case 'b':
					imprimirProductos(); break;
				case 'c':
					buscarSaldoMenor(); break;
				case 'd':
				    cout << "\n==================================================\n";
                    imprimirConFormato( "     El archivo de retiros se actualiza             \n");
                    imprimirConFormato( "     automaticamente al eliminar a un estudiante.   \n");
                    cout << "==================================================\n";
                    break;

				default:
					cout << "Opcion no valida."; break;
				}
				break;
				
			case 7:
				imprimirConFormato("Saliendo..."); break;
			default:
				imprimirConFormato("\nOpcion no valida. Intente nuevamente"); break;
				
		}
		cout << endl;
		system("pause");
		cout  << "\n--------------------------------------------------------------------------------------------------------\n";
		cout << endl;
		
	} while(option != 7);
}
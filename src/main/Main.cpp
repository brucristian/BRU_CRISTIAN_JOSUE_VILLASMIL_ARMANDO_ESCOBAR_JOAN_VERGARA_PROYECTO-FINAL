// Codigos: 6902510029, 6902510017, 6902510023, 6902510055

#include <iostream>
#include "utils/getters.h"
#include "vews/menus.h"
#include "vews/productosvews.h"
#include "vews/comprasvews.h"
#include "vews/estudiantesvews.h"

using namespace std;



int main() {		
	
	int option;
	do {
		option = menuPricipal();
		
		switch (option) {
			case 1:
				registrarStudent();
				break;
			case 2:
				registrarProducto();
				break;
			case 3:
				buy();
				break;
			case 4:
				RecargarBalance();
				break;
			case 5:
				eliminarStudent();
				break;
			case 6:
				cout << "\nAun esta pendiente...";
				break;
			case 7:
				imprimirConFormato("Saliendo...");
				break;
			default:
				imprimirConFormato("\nOpcion no valida. Intente nuevamente");
				break;
				
		}
		cout << endl;
		system("pause");
		
	} while(option != 7);
}

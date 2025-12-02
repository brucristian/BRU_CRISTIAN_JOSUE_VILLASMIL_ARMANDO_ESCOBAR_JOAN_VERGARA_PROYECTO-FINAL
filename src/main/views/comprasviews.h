#ifndef COMPRASVEWS_H
#define COMPRASVEWS_H

#include "../utils/getters.h"
#include "../controller/compracontroller.h"
#include <iostream>

using namespace std;

	void buy() {
    bool validation = false;

    do {
        system("cls");

        cout << "\n==================================================\n";
        cout << "||                  COMPRAS                      ||\n";
        cout << "==================================================\n";

        long long cedula = getNumberLong("\n  Ingrese su cedula ");
        long long id = getNumberLong("  Ingrese el codigo del producto ");

        validation = compra(cedula, id);

        if (!validation) {
           cout << "||  La compra no pudo realizarse. Intente   ||\n";
           cout << "||  nuevamente.                             ||\n";
           cout << "||  --------------------------------------- ||\n";

        }

        system("pause");
    } while (!validation);

    cout << "\n==================================================\n";
    imprimirConFormato( "    Su compra ha sido realizada con exito.\n");
    cout << "==================================================\n\n";
}


#endif
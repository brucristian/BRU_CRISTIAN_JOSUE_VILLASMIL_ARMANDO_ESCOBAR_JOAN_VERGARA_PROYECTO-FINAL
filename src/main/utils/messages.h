#ifndef MESSAGES_H
#define MESSAGES_H

#include<iostream>
#include<string>

#include "getters.h"

using namespace std;

void codeNotFoundError(long long &codigo) {
    cout << "\n============================================\n";
    cout << "||                                          ||\n";
    cout << "||  ! No se encontro el producto con el     ||\n";
    cout << "||    codigo [" << codigo << "]             ||\n";
    cout << "||                                          ||\n";
    cout << "============================================\n";
}

void insufficientFoundsError(double precio) {
    cout << "\n====================================================\n";
    cout << "||                                                ||\n";
    cout << "||  ! No se pudo realizar su compra debido a     ||\n";
    cout << "||    que su saldo estudiantil es menor al       ||\n";
    cout << "||    precio del producto.                        ||\n";
    cout << "||                                                ||\n";
    cout << "||  Valor del producto: $" << precio;
    cout << "                             ||\n";
    cout << "====================================================\n";
}

void unavaibleProductError() {
    cout << "\n";
    cout << "============================================\n";
    cout << "||                                        ||\n";
    cout << "||    ! Lo sentimos, no tenemos este      ||\n";
    cout << "||     producto disponible en estos       ||\n";
    cout << "||     momentos.                          ||\n";
    cout << "||                                        ||\n";
    cout << "============================================\n\n";
}

void studentNotFoundError() {
    cout << "\n==================================================\n";
    imprimirConFormato("NO REGISTRADO");
    cout << "==================================================\n";
    cout << "  No tenemos registrado a un estudiante con la\n";
    cout << "  cedula ingresada en nuestra base de datos.\n";
    cout << "==================================================\n";
}

void invalidInitialAmountError() {
    cout << "\n==================================================\n";
    imprimirConFormato("SALDO INVALIDO");
    cout << "==================================================\n";
    cout << "  El saldo inicial no puede ser menor a $5.000\n";
    cout << "==================================================\n";
}

void duplicateIDError(long long id) {
    cout << "\n==================================================\n";
    imprimirConFormato("CEDULA DUPLICADA");
    cout << "==============================================\n";
    cout << "  La cedula " << id << " ya se encuentra ocupada.\n";
    cout << "==============================================\n";
}

void duplicateCodeError(long long id) {
    cout << "\n==================================================\n";
    imprimirConFormato("CODIGO DUPLICADO");
    cout << "\n==================================================\n";
    cout << "     El codigo de producto {" << id <<"}\n";
    cout << "     Ya se encuentra ocupado.\n";
    cout << "==================================================\n";
}

void registrationError(string text) {
    cout << "\n==================================================\n";
    imprimirConFormato("ERROR AL REGISTRAR");
    cout << "==================================================\n";
    cout << "  Ocurrio un error al " << text << " los datos. Por\n";
    cout << "  favor intentelo nuevamente.\n";
    cout << "==================================================\n";
}

void invalidRechargeAmountError() {
    cout << "\n==================================================" << endl;
    cout << "           Monto de recarga no valido         " << endl;
    cout << "==================================================" << endl;
}

void negativeQuantityError(string text) {
    cout << "\n==================================================\n";
    imprimirConFormato("ERROR DE " + text);
    cout << "\n==================================================\n";
    cout << "  No puede ingresar una cantidad negativa.\n";
    cout << "==================================================\n";
}

#endif
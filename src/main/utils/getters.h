#ifndef GETTERS_H
#define GETTERS_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

string getString(string text) {
	string texto;
	cout << text << ": "; getline(cin, texto);
	return texto;
}

int getInt(string text) {
	
	int n;
	cout << text << ": "; cin >> n;
	cin.ignore();
	
	return n;
}

double getDouble(string text) {
	
	double n;
	cout << text << ": "; cin >> n;
	cin.ignore();
	
	return n;
}

void imprimirConFormato(const string &message) {
	for(char letter : message) {
		cout << letter << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	cout << endl;
}


#endif

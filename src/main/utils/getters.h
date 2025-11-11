#ifndef GETTERS_H
#define GETTERS_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void imprimirConFormato(const string &message) {
	for(char letter : message) {
		cout << letter << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	cout << endl;
}

string getString(string text) {
	string texto;
	imprimirConFormato(text + ": "); getline(cin, texto);
	return texto;
}

int getInt(string text) {
	
	int n;
	imprimirConFormato(text + ": "); cin >> n;
	cin.ignore();
	
	return n;
}

long long getNumberLong(string text) {
	
	long long n;
	imprimirConFormato(text + ": "); cin >> n;
	cin.ignore();
	
	return n;
}

void getChar(const string &text, char *buffer, int size) {
    cout << text << ": ";
    cin.getline(buffer, size);
}

double getDouble(string text) {
	
	double n;
	imprimirConFormato(text + ": "); cin >> n;
	cin.ignore();
	
	return n;
} 


#endif

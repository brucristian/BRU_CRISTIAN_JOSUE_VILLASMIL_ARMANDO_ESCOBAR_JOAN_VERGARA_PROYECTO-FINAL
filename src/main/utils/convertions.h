#ifndef CONVERTIONS_H
#define CONVERTIONS_H

#include <string>
#include <sstream>

using namespace std;

int integerConvertion(const string &number) {
	int n;
	
	stringstream ss(number);
	ss >> n;
	
	return n;
}

#endif

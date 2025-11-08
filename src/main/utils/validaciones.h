#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <vector>
#include "convertions.h"

bool bisiesto(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool dateValidation(const string &data) {
	vector<int> date;
	
	int position = 0;
	for(int i = 0; i < 3; i++) {
		date.push_back(integerConvertion(data.substr(position, 2)));
		position += 3;
	}
	if(date[1] < 1 || date[1] > 12 || date[2] < 0) return false;
	
	int day;
	switch (date[1]) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day = 31; break;
			
		case 4: case 6: case 9: case 11:
			day = 30; break;
			
		case 2:
			if(bisiesto(date[2])) 
				day = 29;
			else 
				day = 28;
				
			break;
	}
	
	if(date[0] < 1 || date[0] > day) return false;
	
	return true;
}



#endif

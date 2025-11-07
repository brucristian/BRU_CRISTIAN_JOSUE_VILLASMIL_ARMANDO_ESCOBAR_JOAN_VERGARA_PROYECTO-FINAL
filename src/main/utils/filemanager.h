#ifndef FILEMANAGER_H
#defina FILEMANAGER_H

#include <cstring>
#include <fstring>

using namespace std;

template <typename T>
bool writeBinaryFile(const string &fileName, const T &dato) {
	ofstream file(filename, ios::binary | ios::app);
	
	if(!file) { return false; }
	
	file.write(reinterpret_cast<const char*>(&dato), sizeof(dato));
	file.close();
	
	return true;
}


#endif

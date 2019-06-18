#ifndef _MEMORIA_H_
#define _MEMORIA_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

class memoria{

private:
	
	int tamanhoMemoria;
	std::vector <int> principal;	

public:

	memoria();
	memoria(int);

	int getTamMemoria();

	int getPosMemoria(int x);
 	
 	void preencheMemoria();

	void alteraDado(int, int);

	void listaDados();
	
};


#endif
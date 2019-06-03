#ifndef _MEMORIA_H_
#define _MEMORIA_H_

#include <vector>

class memoria{

private:
	
	int tamanhoMemoria;
	std::vector <int> principal;	

public:

	memoria();
	memoria(int);

	int getTamMemoria();
 	
 	void preencheMemoria();

	int alteraDado(int, int);

	void listaDados();
	
};


#endif
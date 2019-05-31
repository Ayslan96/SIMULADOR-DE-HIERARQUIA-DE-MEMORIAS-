#ifndef _MEMORIA_H_
#define _MEMORIA_H_

#include <vector>

class memoria{

private:
	
	std::vector <int> mem;	
	int tamanhoMemoria;


public:

	memoria();
	memoria(int);

	int getTamMemoria();
 	
 	void preencheMemoria();

	int alteraDado(int, int);

	void listaDados(int);
	
	

};


#endif
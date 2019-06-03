#include "memoria.h"

#include <iostream>

memoria::memoria(int a) {
	tamanhoMemoria = a;
}

int memoria::getTamMemoria(){
	return tamanhoMemoria;
}
 	
void memoria::preencheMemoria(){
 	for (int i =0; i<tamanhoMemoria; i++){
		principal.push_back(i);
	}
}

int memoria::alteraDado(int posicao, int c){
	principal[posicao] = c;
}

void memoria::listaDados(){
	for (int i =0; i<tamanhoMemoria; i++){
	std::cout<<principal[i]<<"\t";
	}
}
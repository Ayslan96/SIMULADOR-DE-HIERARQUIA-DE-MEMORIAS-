/**
ESTE É O CABEÇALHO DA CLASSE MEMÓRIA.
*/

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
	
	int tamanhoMemoria;//Atributo referente ao tamanho da memória
	std::vector <int> principal; //Instancia atributo do tipo vector para armazenar os valores da memória principal

public:

	memoria();//Construtor não parametrizado
	memoria(int);//Construtor parametrizado

	int getTamMemoria(); //Este método retorna o tamanho da memória

	int getPosMemoria(int x); //Este método retorna o valor armazenado em uma posição de memória x
 	
 	void preencheMemoria(); //Este método Preenche a memória

	void alteraDado(int, int); //Este método Altera uma valor dentro da memória baseado uma posição informada

	void listaDados(); //Este método lista todos os elementos da memória
	
};


#endif
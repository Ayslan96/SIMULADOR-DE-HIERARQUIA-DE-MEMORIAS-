#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

#include "memoria.h"

using namespace std;

memoria::memoria(int a) {
	tamanhoMemoria = a;
}

int memoria::getTamMemoria(){
	return tamanhoMemoria;
}

void memoria::preencheMemoria(){

// cria um objeto da classe  'ifstream'
	ifstream arquivoDeEntrada;
//char S[100];
	string S, aux;

// Abre um arquivo para leitura 
	arquivoDeEntrada.open ("arquivo.txt", ios::in);

	if (!arquivoDeEntrada)
	{
		cout << "Problemas na abertura do arquivo" << endl;
		exit(1);
	}

	while(!arquivoDeEntrada.eof()){

		getline(arquivoDeEntrada, S);

		std::istringstream iss(S);
		std::string token;

		while (std::getline(iss, token, ','))
		{
			principal.push_back(stoi(token));
		}
	}
	arquivoDeEntrada.close();	
}

void memoria::alteraDado(int posicao, int c){
	principal[posicao] = c;
}

void memoria::listaDados(){
	for (int i =0; i<tamanhoMemoria; i++){
		std::cout<<principal[i]<<"\t";
	}
	cout<<"\n\n";
}
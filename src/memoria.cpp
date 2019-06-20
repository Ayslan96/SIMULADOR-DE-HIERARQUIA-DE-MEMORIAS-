/**
A Classe Memória implementa os atributos da memória principal e os métodos referentes as operações
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

#include "../include/memoria.h"

using namespace std;

memoria::memoria(int a) {
	tamanhoMemoria = a;
}

int memoria::getTamMemoria(){
	return tamanhoMemoria;
}

void memoria::preencheMemoria(){


	ifstream arquivoDeEntrada;//Instancia um objeto da classe  'ifstream'
	string S, aux; //Variáveis auxiliares

	arquivoDeEntrada.open ("data/arquivo.txt", ios::in); //O Objeto arquivoDeEntrada usa o arquivo arquivo.txt como entrada

	if (!arquivoDeEntrada)
	{	
		///Caso haja algum problema na abertura de arquivo.txt a mensagem é exibida
		cout << "Problemas na abertura do arquivo" << endl;
		exit(1);
	}

	while(!arquivoDeEntrada.eof()){
		///Enquanto o arquivo não chegar ao final as instruções do laço serão executadas
		getline(arquivoDeEntrada, S); //Insere o conteúdo do objeto arquivoDeEntrada na string S

		std::istringstream iss(S); //Instancia iss com S como entrada
		std::string token; //Cria string token

		while (std::getline(iss, token, ',')) 
		{
			//Enquanto houverem separadores ',' as instruções do laço serão executadas
			principal.push_back(stoi(token)); //pega o numero no formato de string, converte e insere na memória
		}
	}
	arquivoDeEntrada.close();//Fecha o arquivo.txt
}

void memoria::alteraDado(int posicao, int c){
	//Altera uma posição da memória baseada numa posição informada
	principal[posicao] = c;
}

int memoria::getPosMemoria(int x){
	//Retorna uma posição da memória
	return principal[x];
}

void memoria::listaDados(){
	//Lista os valores da memória
	std::cout<<"\nDADOS NA MEMORIA RAM:\n\n";
	for (int i =0; i<tamanhoMemoria; i++){
		std::cout<<principal[i]<<"\t";
	}
	std::cout<<"\n\n";
}

#include <iostream>
#include "memoria.h"

using namespace std;


memoria::memoria(int a) {
	tamanhoMemoria = a;
}


int memoria::getTamMemoria(){

}
 	
void memoria::preencheMemoria(){
 	for (int i =0; i<10; i++){
		mem.push_back(i);
	}
}

int alteraDado(int posicao, int b){
	

}

void listaDados(int){
	for (int i =0; i<10; i++){
	cout<<mem[i];
	}
}
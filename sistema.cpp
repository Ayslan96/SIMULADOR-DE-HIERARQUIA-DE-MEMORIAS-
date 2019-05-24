#include <iostream>
#include "cpu.h"
//#include "memoria"

int main(){

	int quantidadeNucleos;

	while (true){
		std::cout<<"Entre com a quantidade de nucleos desejada: ";
		std::cin>> quantidadeNucleos ;

		if(quantidadeNucleos%2==0) break;
		else {
			std::cout<<"\nQuantidade invalida! entre apenas com Numeros pares.\n\n";
			false;
		}
	}

	cpu corei5(quantidadeNucleos);

	std::cout<<"\n\nQuantidade de Nucleos: "<<corei5.getQuantidadeNucleos()
			 <<"\n\nQuantidade de threads: "<<corei5.getQuantidadeThreads()
			 <<"\nQuantidade cache L1: "<<corei5.getCacheL1()
			 <<"\nQuantidade Cache L2: "<<corei5.getCacheL2()<<"\n\n";





return 0;	
}
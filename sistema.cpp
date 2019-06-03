#include <iostream>
#include "cpu.h"
#include <vector>
//#include "memoria"

int main(){

	int quantidadeNucleos;

	while (true){
		std::cout<<"Entre com a quantidade de nucleos desejada: ";
		std::cin>> quantidadeNucleos ;

		if(quantidadeNucleos%2==0) break;
		else {
			std::cout<<"\nQuantidade invalida! entre apenas com Numeros pares.\n\n";
		}
	}

	int qtdProcessadores = (2* quantidadeNucleos);
	int tamCacheL1 = (2*quantidadeNucleos);
	int tamCacheL2 = quantidadeNucleos;


	cpu corei5(quantidadeNucleos, qtdProcessadores, 
			   tamCacheL1, tamCacheL2);

	std::cout<<"\n\nQuantidade de Nucleos: "<<corei5.getQuantidadeProcessadores()
			 <<"\nQuantidade de threads: "<<corei5.getQuantidadeCpu()
			 <<"\nCache L1: "<<corei5.getTamCacheL1()
			 <<"\nCache L2: "<<corei5.getTamCacheL2()<<"\n\n";

	
	corei5.criaCacheL1(tamCacheL1);
	corei5.criaCacheL2(tamCacheL2);

return 0;	
}
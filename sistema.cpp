#include <iostream>
#include "cpu.h"
#include "memoria"

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
	std::cout<<"\n\n"<<quantidadeNucleos<<"\n\n";


return 0;	
}
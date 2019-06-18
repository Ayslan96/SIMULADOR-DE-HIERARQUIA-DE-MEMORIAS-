#include "cpu.h"
#include "memoria.h"

int main(){
	int op;
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


	cpu corei5(quantidadeNucleos, qtdProcessadores, tamCacheL1, tamCacheL2);
	memoria ram(20);

	std::cout<<"\n\nQuantidade de Nucleos: "<<corei5.getQuantidadeProcessadores()
	<<"\nQuantidade de threads: "<<corei5.getQuantidadeCpu()
	<<"\nCache L1: "<<corei5.getTamCacheL1()
	<<"\nCache L2: "<<corei5.getTamCacheL2()<<"\n\n";

	corei5.criaCacheL1(tamCacheL1);
	corei5.criaCacheL2(tamCacheL2);

	std::cout<<"tamanho da memoria: " <<ram.getTamMemoria()<<"\n";
	ram.preencheMemoria();
	ram.alteraDado(0, 555);
	ram.listaDados();

	bool a = true;
	while(a){

		std::cout<<"\n       ESCOLHA UMA OPCAO\n";
		std::cout<<"1. Ler dado da memoria\n";
		std::cout<<"2. Alterar dado na memoria principal\n";
		std::cout<<"3. Listar os dados da memoria\n";
		std::cout<<"4. Listar os dados das caches\n";
		std::cout<<"5. SAIR\n";
		std::cout<<"O que deseja fazer? ";
		std::cin >> op;
		switch (op){
			case 1:
				std::cout<<"ver dado\n";
				break;
			case 2:
				std::cout<<"altera dado\n";
				break;
			case 3:
				std::cout<<"listar dados\n";
				break;
			case 4:
				std::cout<<"listar dados\n";
				break;
			case 5:
				a=false;
				break;
			default:
				std::cout<<"Opção desconhecida. Tente novamente\n\n";
		}
	}
	return 0;	
}

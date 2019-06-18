#include "cpu.h"
#include "memoria.h"

using namespace std;

int main(){
	int op;
	int quantidadeProcessadores;

	while (true){
		std::cout<<"Entre com a quantidade de Processadores desejada: ";
		std::cin>> quantidadeProcessadores ;

		if(quantidadeProcessadores%2==0) break;
		else {
			std::cout<<"\nQuantidade invalida! entre apenas com Numeros pares.\n\n";
		}
	}

	int quantidadeCores = (2* quantidadeProcessadores);
	int tamCacheL1 = (2*quantidadeProcessadores);
	int tamCacheL2 = quantidadeProcessadores;


	cpu corei5(quantidadeProcessadores, quantidadeCores, tamCacheL1, tamCacheL2);
	memoria ram(20);

	std::cout<<"\n\nQuantidade de Processadores: "<<corei5.getQuantidadeProcessadores()
	<<"\nQuantidade de Cores: "<<corei5.getQuantidadeCores()
	<<"\nTamanho da Cache L1: "<<corei5.getTamCacheL1()
	<<"\nTamanho da Cache L2: "<<corei5.getTamCacheL2()<<"\n\n";

	corei5.criaCacheL1(tamCacheL1);
	corei5.criaCacheL2(tamCacheL2);

	std::cout<<"Tamanho da Memoria RAM: " <<ram.getTamMemoria()<<"\n";
	ram.preencheMemoria();
	ram.listaDados();


	bool a = true;
	while(a){

		std::cout<<"\n       ESCOLHA UMA OPCAO\n";
		std::cout<<"1. Ler dado da memoria\n";
		std::cout<<"2. Alterar dado na memoria principal\n";
		std::cout<<"3. Listar os dados das memorias\n";
		std::cout<<"4. SAIR\n";
		std::cout<<"O que deseja fazer? ";
		std::cin >> op;
		switch (op){
			case 1:
			//Ver dado
			int coreOp, memPos,valorIns;

			while (true){
				cout<<"\nInforme o Core da operação: ";
				cin>>coreOp;

				if(coreOp > 0 && coreOp <= corei5.getQuantidadeCores()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}

			while (true){
				cout<<"\nInforme a posicao da memoria para a operação: ";
				cin>>memPos;

				if(memPos >> 0 && memPos <= ram.getTamMemoria()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}
			//adicionar na cache L1 Processador
			//adicionar na cache l2 compartilhada

			cout<<"\nDado da "<<memPos <<"ª" <<"posição:" << ram.getPosMemoria(memPos-1);
			break;

			case 2:
			//altera dado
			while (true){
				cout<<"\nInforme o Core da operação: ";
				cin>>coreOp;

				if(coreOp > 0 && coreOp <= corei5.getQuantidadeCores()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}

			while (true){
				cout<<"\nInforme a posicao da memoria para a operação: ";
				cin>>memPos;

				if(memPos >> 0 && memPos <= ram.getTamMemoria()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}
			cout<<"Informe o valor para insercao na posicao de memoria escolhida: ";
			cin>>valorIns;
			ram.alteraDado(memPos-1, valorIns);

			//alterar dado na memoria endereço de alterar e core
			//adicionar na cache L1 Processador
			//adicionar na cache l2 compartilhada
			break;

			case 3:
			//listar dados
			ram.listaDados();
			cout<<"\n\n";

			cout<<"Cache L1:\n";
			corei5.listaCacheL1(tamCacheL1);
			cout<<"\n\n";

			cout<<"Cache L2:\n";
			corei5.listaCacheL2(tamCacheL2);
			cout<<"\n\n";
			break;

			case 4:
			a=false;
			break;

			default:
			std::cout<<"Opção desconhecida. Tente novamente\n\n";
		}
	}
	return 0;	
}
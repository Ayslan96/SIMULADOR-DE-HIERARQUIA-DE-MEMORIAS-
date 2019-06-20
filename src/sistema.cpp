/**
ESTA CLASSE IMPLEMENTA O FUNCIONAMENTO DA HIERARQUIA DE MEMORIAS UTILIZANDO AS CLASSES MEMORIA, CPU E CACHE.

O sistema de memória tem dois níveis de cache (L1 e L2) e a memória principal. 
Cada core terá uma cache L1. Uma cache L2 é compartilhada entre dois cores.
A memória principal é compartilhada por todos os cores. 

No simulador, o usuário informa quantos processadores o sistema terá, sendo permitido como entrada, somente, inteiros menores que 9.
O sistema automaticamente cria as caches e a memória principal e um arquivo, lido pelo simulador, carrega os dados na memória principal.
O usuário informa o endereço da memória principal para leitura e o core que irá utilizar
aquele dado. O sistema automaticamente carrega o dado na cache L2 e na cache L1 do
respectivo core. 
*/

#include "../include/cpu.h"
#include "../include/memoria.h"

int main(){
	int op;
	int quantidadeProcessadores;

	while (true){ ///Este loop só encerra quando a quantidade de processadores é par e menor ou igual a 8
		std::cout<<"Entre com a quantidade de Processadores desejada (MAXIMO DE 8): ";
		std::cin>> quantidadeProcessadores ;

		if(quantidadeProcessadores%2==0 && quantidadeProcessadores<=8) break;
		else {
			std::cout<<"\nQuantidade invalida! Entrada permitida apenas para Numero par <= 8.\n\n";
		}
	}
	///Atribui valores as variáveis de quantidade de cores e caches, baseada no número de processadores 
	int quantidadeCores = (2* quantidadeProcessadores);
	int quantidadeCacheL1 = (2*quantidadeProcessadores);
	int quantidadeCacheL2 = quantidadeProcessadores;

	///Instancia uma CPU baseada nos valores das variáveis 
	cpu corei5(quantidadeProcessadores, quantidadeCores, quantidadeCacheL1, quantidadeCacheL2);	
	corei5.criaCachesL1(quantidadeCacheL1); //Cria a cache L1
	corei5.criaCachesL2(quantidadeCacheL2); //Cria a cache L2
	memoria ram(20); //Instancia uma memória de 20 Posições
	ram.preencheMemoria(); // Preenche memória

	///Exibe Dados do sistema
	std::cout<<"\n\nQuantidade de Processadores: "<<corei5.getQuantidadeProcessadores()
	<<"\nQuantidade de Cores: "<<corei5.getQuantidadeCores()
	<<"\nQuantidade de Cache L1: "<<corei5.getQuantidadeCachesL1()
	<<"\nQuantidade de Cache L2: "<<corei5.getQuantidadeCachesL2()<<"\n\n";

	std::cout<<"Tamanho da Memoria RAM: " <<ram.getTamMemoria()<<"\n";
	ram.listaDados();

	std::cout<<"\nTamanho da Cache L1: "<<corei5.getTamCachesL1()	
			 <<"\nTamanho da Cache L2: "<<corei5.getTamCachesL2()<<"\n\n";

	bool a = true; //Declaração da variável de controle do laço principal
	while(a){ //Laço Principal

		std::cout<<"\n       ESCOLHA UMA OPCAO\n";
		std::cout<<"1. Ler dado da memoria\n";
		std::cout<<"2. Alterar dado na memoria principal\n";
		std::cout<<"3. Listar os dados das memorias\n";
		std::cout<<"4. SAIR\n";
		std::cout<<"O que deseja fazer? ";
		std::cin >> op;
		switch (op){
			case 1:
			int coreOp, memPos,valorIns;

			while (true){
				///Laço para escolha de Core
				std::cout<<"\nInforme o Core da operação: ";
				std::cin>>coreOp;

				if(coreOp > 0 && coreOp <= corei5.getQuantidadeCores()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}

			while (true){
				///Laço para escolha de Posição de memória
				std::cout<<"\nInforme a posicao da memoria para a operação: ";
				std::cin>>memPos;

				if(memPos >> 0 && memPos <= ram.getTamMemoria()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}

			std::cout<<"\nDado da "<<memPos <<"ª" <<"posição:" << ram.getPosMemoria(memPos-1); ///Exibe Valor contido na posição de memoria informada
			corei5.atualizaCaches(coreOp,ram.getPosMemoria(memPos-1)); ///Atualiza as Caches
			break;

			case 2:
			while (true){
				///Laço para escolha de Core
				std::cout<<"\nInforme o Core da operação: ";
				std::cin>>coreOp;

				if(coreOp > 0 && coreOp <= corei5.getQuantidadeCores()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}

			while (true){
				///Laço para escolha de Posição de memória
				std::cout<<"\nInforme a posicao da memoria para a operação: ";
				std::cin>>memPos;

				if(memPos >> 0 && memPos <= ram.getTamMemoria()) break;
				else {
					std::cout<<"\nQuantidade invalida! entre apenas com um core valido.\n\n";
				}
			}
			std::cout<<"Informe o valor para insercao na posicao de memoria escolhida: ";
			std::cin>>valorIns;
			ram.alteraDado(memPos-1, valorIns);//Altera valor na posição de memória informada
			corei5.atualizaCaches(coreOp,valorIns); //Atualiza os valores nas caches
			break;
			case 3:
			ram.listaDados(); //Lista os valores armazenados na memória principal
			std::cout<<"\n\n";

			std::cout<<"Cache L1:\n";
			corei5.listaCachesL1(quantidadeCacheL1); //Lista os valores armazenados nas Cache L1 dos Cores
			std::cout<<"\n\n";

			std::cout<<"Cache L2:\n";
			corei5.listaCachesL2(quantidadeCacheL2);//Lista os valores armazenados nas Cache L2 dos Processadores
			std::cout<<"\n\n";
			break;

			case 4: //Sai do programa
			a=false; 
			break;

			default:
			std::cout<<"Opção desconhecida. Tente novamente\n\n";
		}
	}
	return 0;	
}
#include "cpu.h"

cpu::cpu(int a, int b, int c, int d) {
	
	quantidadeProcessadores = a;
	quantidadeCores = b;
	
	quantidadeCacheL1 = c;
	quantidadeCacheL2 = d;
}

cpu::~cpu(){}

int cpu::getQuantidadeProcessadores(){
	return quantidadeProcessadores;
}

int cpu::getQuantidadeCores(){
	return quantidadeCores;
}

int cpu::getQuantidadeCachesL1(){
	return quantidadeCacheL1;
}

int cpu::getQuantidadeCachesL2(){
	return quantidadeCacheL2;
}


int cpu::getTamCachesL1(){
	return cacheL1[0].getTamCache();
}

int cpu::getTamCachesL2(){
	return cacheL2[0].getTamCache();
}

void cpu::criaCachesL1(int q){
	for (int i=0;i<q;i++){
		cacheL1[i].setTamCache(3);
	}
}

void cpu::criaCachesL2(int r){
	for (int i=0;i<r;i++){
		cacheL2[i].setTamCache(5);
	}
}

void cpu::atualizaCaches(int core, int valor){
	int arit_CoreL2 = int(((core-1)/2)+0.5); //lógica escolha da cache L2 baseado no core
	cacheL1[int(core-1)].refer(int(valor));
	cacheL2[arit_CoreL2].refer(int(valor));
	//cacheL2[int(((core-1)/2)+0.5)].refer(int(valor));

}

void cpu::listaCachesL1(int x){
	for(int i = 0; i<x;i++){
		std::cout<<"Cache do Core: "<<i+1 <<": ";
		cacheL1[i].display();
		std::cout<<"\n";
	}
}

void cpu::listaCachesL2(int x){
	for(int i = 0; i<x;i++){
		std::cout<<"Cache do Core: "<<i+1 <<": ";
		cacheL2[i].display();
		std::cout<<"\n";
	}
}
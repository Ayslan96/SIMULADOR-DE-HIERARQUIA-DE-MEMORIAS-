#include "cpu.h"

cpu::cpu(int a, int b, int c, int d, int e, int f) {
	
	quantidadeProcessadores = a;
	quantidadeCores = b;
	
	tamCacheL1 = c;
	tamCacheL2 = d;

	cacheL1[f];
	cacheL2[e];
}
cpu::~cpu(){}

int cpu::getQuantidadeProcessadores(){
	return quantidadeProcessadores;
}

int cpu::getQuantidadeCores(){
	return quantidadeCores;
}

int cpu::getTamCachesL1(){
	return tamCacheL1;
}

int cpu::getTamCachesL2(){
	return tamCacheL2;
}

void cpu::criaCachesL1(int q){
	for (int i=0;i<q;i++){
		cacheL1[q].setTamCache(3);
	}
}

void cpu::criaCachesL2(int q){
	for (int i=0;i<q;i++){
		cacheL2[q].setTamCache(5);
	}
}

void cpu::atualizaCaches(int core, int valor){
	cacheL1[core].refer(valor);
	cacheL2[int(core/2)].refer(valor);
}

void cpu::listaCachesL1(int x){
	for(int i = 0; i<x;i++){
		cacheL1[x].display();
		std::cout<<"\n";
	}
}

void cpu::listaCachesL2(int x){
	for(int i = 0; i<x;i++){
		cacheL2[x].display();
		std::cout<<"\n";
	}
}
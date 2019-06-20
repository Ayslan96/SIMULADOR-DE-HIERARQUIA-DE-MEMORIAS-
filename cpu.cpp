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

int cpu::getTamCachesL1(){
	return quantidadeCacheL1;
}

int cpu::getTamCachesL2(){
	return quantidadeCacheL2;
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
	cacheL1[int(core-1)].refer(int(valor));
	cacheL2[int(((core-1)/2)+0.5)].refer(int(valor));

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
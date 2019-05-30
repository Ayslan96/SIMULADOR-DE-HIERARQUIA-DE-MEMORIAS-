#include "cpu.h"
#include <iostream>

cpu::cpu(int a, int b, int c, int d) {
	
	quantidadeProcessadores = a;
	quantidadeCpu = b;
	
	tamCacheL1 = c;
	tamCacheL2 = d;

}

int cpu::getQuantidadeProcessadores(){
	return quantidadeProcessadores;
}

int cpu::getQuantidadeCpu(){
	return quantidadeCpu;
}

int cpu::getTamCacheL1(){
	return tamCacheL1;
}

int cpu::getTamCacheL2(){
	return tamCacheL2;
}


int cpu::criaCacheL1(int q){

	for (int i = 0; i < q; i++){
		cacheL1.push_back(1);
	}
}

int cpu::criaCacheL2(int q){

	for (int i = 0; i< q; i++){
		cacheL2.push_back(1);
	}
}

void cpu::listaCacheL1(int x){

	for(int i = 0; i<x;i++){
		std::cout<<cacheL1[i]<<"\n";
	}

}

void cpu::listaCacheL2(int x){

	for(int i = 0; i<x;i++){
		std::cout<<cacheL2[i]<<"\n";
	}

}
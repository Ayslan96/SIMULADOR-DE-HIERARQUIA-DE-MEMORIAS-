#include "cpu.h"


cpu::cpu(int a) {

	int quantidadeNucleos = a;
	int quantidadeThreads = 2*quantidadeNucleos;
	int cacheL1 = 2*quantidadeNucleos;
	int cacheL2 = a;

}

int cpu::getQuantidadeNucleos(){
	return quantidadeNucleos;
}

int cpu::getQuantidadeThreads(){
	return quantidadeThreads;
}
int cpu::getCacheL1(){
	return cacheL1;
};
int cpu::getCacheL2(){
	return cacheL2;
};

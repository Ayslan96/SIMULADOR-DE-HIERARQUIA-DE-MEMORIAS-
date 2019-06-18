#ifndef _CPU_H_
#define _CPU_H_

#include <vector>
#include "cache.h"


class cpu{

private:

	int quantidadeProcessadores;
	int quantidadeCores;

	int tamCacheL1;
	int tamCacheL2;

	cache cacheL1[quantidadeCores];
	cache cacheL2[quantidadeProcessadores];

public:
	cpu();
	cpu(int, int, int, int);

	int getTamCacheL1();
 	int getTamCacheL2();

	int getQuantidadeProcessadores();
	int getQuantidadeCores();

	void criaCacheL1(int);
	void criaCacheL2(int);

	void alteraDadoCacheL1(int, int);
	void alteraDadoCacheL2(int, int);

	void listaCacheL1(int);
	void listaCacheL2(int);

	void preencheCacheL1();
	void preencheCacheL2();

	

};
#endif
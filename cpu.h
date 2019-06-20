#ifndef _CPU_H_
#define _CPU_H_
#include "cache.h"

class cpu{

private:

	int quantidadeProcessadores;
	int quantidadeCores;

	int quantidadeCacheL1;
	int quantidadeCacheL2;

	cache cacheL1[4]{3,3,3,3};
	cache cacheL2[4]{3,3,3,3};

public:

	cpu(int, int, int, int);
	~cpu();
	int getTamCachesL1();
 	int getTamCachesL2();

	int getQuantidadeProcessadores();
	int getQuantidadeCores();

	void criaCachesL1(int);
	void criaCachesL2(int);

	void atualizaCaches(int, int);

	void listaCachesL1(int);
	void listaCachesL2(int);


};
#endif
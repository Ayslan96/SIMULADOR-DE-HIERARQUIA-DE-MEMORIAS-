#ifndef _CPU_H_
#define _CPU_H_
#include "cache.h"

class cpu{

private:

	int quantidadeProcessadores;
	int quantidadeCores;

	int tamCacheL1;
	int tamCacheL2;

	cache cacheL1[100];
	cache cacheL2[100];

public:
	cpu(int, int, int, int, int, int);
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
#ifndef _CPU_H_
#define _CPU_H_

#include <vector>


class cpu{

private:

	int quantidadeProcessadores;
	int quantidadeCpu;

	int tamCacheL1;
	int tamCacheL2;

	std::vector <int> cacheL1;
	std::vector <int> cacheL2;

public:
	cpu();
	cpu(int, int, int, int);

	int getTamCacheL1();
 	int getTamCacheL2();

	int getQuantidadeProcessadores();
	int getQuantidadeCpu();

	int criaCacheL1(int);
	int criaCacheL2(int);

	void listaCacheL1(int);
	void listaCacheL2(int);

	void preencheCacheL1();
	void preencheCacheL2();

	
	


};
#endif
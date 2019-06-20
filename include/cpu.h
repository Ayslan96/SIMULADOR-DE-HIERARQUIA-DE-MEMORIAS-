/**
ESTE É O CABEÇALHO DA CLASSE CPU.
*/

#ifndef _CPU_H_
#define _CPU_H_
#include "cache.h"

class cpu{

private:

	int quantidadeProcessadores; /*!<Atributo referente a quantidade de processadores*/
	int quantidadeCores;/*!<Atributo referente a quantidade de cores*/

	int quantidadeCacheL1;/*!<Atributo referente a quantidade de cache L1*/
	int quantidadeCacheL2;/*!<Atributo referente a quantidade de cache L2*/

	cache cacheL1[16]{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};/*!<Atributo que armazena um vetor de caches L1*/
	cache cacheL2[8]{5,5,5,5,5,5,5,5}; /*!<Atributo que armazena um vetor de caches L2*/

public:

	cpu(int, int, int, int); /*!<Construtor Parametrizado de CPU*/
	~cpu(); /*!<Destrutor*/
	
	int getQuantidadeCachesL1();
 	int getQuantidadeCachesL2();
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

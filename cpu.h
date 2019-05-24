#ifndef _CPU_H_
#define _CPU_H_

class cpu{

private:

	int quantidadeNucleos;
	int quantidadeThreads;
	int cacheL1;
	int cacheL2;


public:

	cpu(int);
	int getQuantidadeNucleos();
	int getQuantidadeThreads();
	int getCacheL1();
	int getCacheL2();

};


#endif
/**
ESTE É O CABEÇALHO DA CLASSE CACHE.
*/

#ifndef _cache_h_
#define _cache_h_

#include <bits/stdc++.h> 
#include <iostream>

using namespace std;
  
class cache 
{ 
	int tamCache; /*!<Tamanho maximo da cache*/
    list<int> dq; /*!< Armazena chaves da cache*/
    unordered_map<int, list<int>::iterator> ma; /*!< armazena referencias das chaves na cache*/

  
public: 
    cache(int); /*!<Este é o método construtor parametrizado da classe Cache*/
    void setTamCache(int); /*!<Este mátodo seta o tamanho maximo da cache*/
    int getTamCache(); /*!<Este método retorna o tamanho da cache*/
    void refer(int); /*!<Este método adiciona um dado na cache*/
    void display(); /*!<Este método exibe os elementos armazenados na cache*/
}; 

#endif
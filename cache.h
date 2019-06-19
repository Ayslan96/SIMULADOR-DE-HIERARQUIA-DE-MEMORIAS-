#ifndef _cache_h_
#define _cache_h_

#include <bits/stdc++.h> 
#include <iostream>

using namespace std;
  
class cache 
{ 
    // Armazena chaves da cache
    list<int> dq; 
  
    // armazena referencias das chaves na cache
    unordered_map<int, list<int>::iterator> ma; 
    int tamCache; //Tamanho maximo da cache
  
public: 
    cache(); 
    void setTamCache(int);
    void refer(int); 
    void display(); 
}; 

#endif
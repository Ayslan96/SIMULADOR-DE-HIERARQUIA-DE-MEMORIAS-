#include "cache.h"

cache::cache(int n) 
{ 
    tamCache = n; 
} 

void cache::setTamCache(int n){
    tamCache = n;
}

int cache::getTamCache(){
    return tamCache;
}

void cache::refer(int x) 
{ 
    // não presente em cache
    if (ma.find(x) == ma.end()) 
    { 
        // cache está cheia 
        if (int(dq.size()) == tamCache) 
        { 
            //deleta o elemento menos usado recentemente
            int last = dq.back(); 
            dq.pop_back(); 
            ma.erase(last); 
        } 
    } 
    // presente na cache
    else
        dq.erase(ma[x]); 
  
    // atualiza referencia 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 
  
// exibe dados cache
void cache::display() 
{ 
    for (auto it = dq.begin(); it != dq.end(); it++) 
        cout << (*it) << " "; 
    cout << endl; 
} 

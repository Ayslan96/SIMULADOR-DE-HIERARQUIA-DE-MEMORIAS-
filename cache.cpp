
/* We can use stl container list as a double 
   ended queue to store the cache keys, with 
   the descending time of reference from front 
   to back and a set container to check presence 
   of a key. But to fetch the address of the key 
   in the list using find(), it takes O(N) time. 
    This can be optimized by storing a reference 
    (iterator) to each key in a hash map. */
#include <bits/stdc++.h> 
using namespace std; 
  
class LRUCache 
{ 
    // Armazena chaves da cache
    list<int> dq; 
  
    // armazena referencias das chaves na cache
    unordered_map<int, list<int>::iterator> ma; 
    int csize; //Tamanho maximo da cache
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
}; 
  
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
void LRUCache::refer(int x) 
{ 
    // não presente em cache
    if (ma.find(x) == ma.end()) 
    { 
        // cache está cheia 
        if (dq.size() == csize) 
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
void LRUCache::display() 
{ 
    for (auto it = dq.begin(); it != dq.end(); it++) 
        cout << (*it) << " "; 
    cout << endl; 
} 
  
int main() 
{ 
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
}

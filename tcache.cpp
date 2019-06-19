#include "cache.h"
#include <vector>
int main() 
{ 
	cache vetorCache[2];

	

	vetorCache[0].setTamCache(3);
    vetorCache[1].setTamCache(4);

	vetorCache[1].refer(1); 
    vetorCache[1].refer(2); 
    vetorCache[1].refer(3); 
    vetorCache[1].refer(1); 
    vetorCache[1].refer(4); 
    vetorCache[1].refer(5); 
    vetorCache[1].display(); 

    vetorCache[0].refer(6); 
    vetorCache[0].refer(7); 
    vetorCache[0].display(); 

    return 0; 
}

/*
ESTE É O ARQUIVO DE DEFINIÇÃO DA CLASSE CACHE

A Classe Cache implementa os atributos e os métodos referentes a uma cache
*/

#include "../include/cache.h"

cache::cache(int n) 
{ 
    tamCache = n; /*!< Constroi um objeto do tipo Cache, com valor inicial de tamCache = n*/
} 

void cache::setTamCache(int n){
    tamCache = n; /*!< Seta o valor do atributo tamCache*/
}

int cache::getTamCache(){
    return tamCache; /*!< Retorna o valor do atributo tamCache*/
}

void cache::refer(int x) /*!<Este método adiciona um dado na cache*/
{ 

    if (ma.find(x) == ma.end()) /*!< Verifica se o dado está presente no mapa*/
    { 

        if (int(dq.size()) == tamCache) 
        { 
            ///Se a Cache estiver cheia o elemento menos usado recentemente será deletado
            int last = dq.back(); /*!<Last recebe o valor do elemento menos usado do mapa*/
            dq.pop_back(); /*!<Deleta o elemento menos usado da lista*/
            ma.erase(last); /*!<Deleta o elemento menos usado do mapa*/
        } 
    } 
    ///Caso esteja presente na cache ele atualiza o mapa e a lista
    else
        dq.erase(ma[x]); 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 

void cache::display() ///Este método exibe os dados contidos na lista
{ 
    for (auto it = dq.begin(); it != dq.end(); it++) 
        std::cout << (*it) << " "; 
    std::cout << endl; 
} 

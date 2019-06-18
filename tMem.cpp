#include "memoria.h"
#include <iostream>

int main(){

memoria ram(20);

std::cout<<"tamanho da memoria: " <<ram.getTamMemoria()<<"\n";
ram.preencheMemoria();
ram.alteraDado(0, 555);
ram.listaDados();



return 0;
}
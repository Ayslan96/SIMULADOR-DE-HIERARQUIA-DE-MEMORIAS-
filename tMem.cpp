#include "memoria.h"
#include <iostream>

using std::cout;

int main(){

memoria ram(100);

cout<<"tamanho da memoria: " <<ram.getTamMemoria()<<"\n";
ram.preencheMemoria();
ram.alteraDado(0, 555);
ram.listaDados();



return 0;
}
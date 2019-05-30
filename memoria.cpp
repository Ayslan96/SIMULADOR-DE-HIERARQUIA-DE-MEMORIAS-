#include <iostream>
#include "memoria.h"
#include <vector>
using namespace std;

int main()
{

std::vector <int> mem;

for (int i =0; i<10; i++){

  mem.push_back(i);
}

mem[2]=60;

for (int i =0; i<10; i++){

  cout<<mem[i];
}


}

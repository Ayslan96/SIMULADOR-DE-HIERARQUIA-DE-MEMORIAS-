#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{

// cria um objeto da classe  'ifstream'
	ifstream arquivoDeEntrada;
  //char S[100];
	string S, aux;
	std::vector<int> v;

  // Abre um arquivo para leitura 
	arquivoDeEntrada.open ("arquivo.txt", ios::in);

	if (!arquivoDeEntrada)
	{
		cout << "Problemas na abertura do arquivo" << endl;
		exit(1);
	}

	while(!arquivoDeEntrada.eof()){

		getline(arquivoDeEntrada, S);

		std::istringstream iss(S);
		std::string token;

		while (std::getline(iss, token, ','))
		{
			std::cout << token << std::endl;
			v.push_back(stoi(token));
		}
		for (int i;i<v.size();i++){
			cout<<v[i]<<"\t";
		}
	}
	arquivoDeEntrada.close();
	return 0;
}
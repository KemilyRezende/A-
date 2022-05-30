#include <iostream>
#include "CaminhoDFS.hpp"
#include "CaminhoBFS.hpp"
#include "AEstrela.hpp"
#include <locale.h>

using namespace std;

int main(){
	int lin, col, metodo, op;
	setlocale (LC_ALL, "Portuguese");
	do{
		cout << "Quantas Linhas h� no mapa(matriz)?\n";
		cin >> lin;
		cout << "Quantas Colunas h� no mapa(matriz)?\n";
		cin >> col;
		cout << "M�todo de busca:\n1. DFS.\n2. BFS.\n3. A*.\n";
		cin >> metodo;
		switch (metodo){
			case 1:
				CaminhoDFS(lin, col);
				break;
			case 2:
				CaminhoBFS(lin, col);
				break;
			case 3:
				AEstrela(lin, col);
				break;
		}
		cout << "\nDesejas testar outro mapa/m�todo?\n1. Sim.\n2. N�o.\n";
		cin >> op;
	}while (op != 2);
	return 0;
}

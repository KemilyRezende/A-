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
		cout << "Quantas Linhas há no mapa(matriz)?\n";
		cin >> lin;
		cout << "Quantas Colunas há no mapa(matriz)?\n";
		cin >> col;
		cout << "Método de busca:\n1. DFS.\n2. BFS.\n3. A*.\n";
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
		cout << "\nDesejas testar outro mapa/método?\n1. Sim.\n2. Não.\n";
		cin >> op;
	}while (op != 2);
	return 0;
}

#include <iostream>
#include "CaminhoDFS.hpp"

using namespace std;

CaminhoDFS::CaminhoDFS(int lin, int col){
	char Mapa[lin][col];
	int cont;
	cont = 0;
	int op;
	int i;
	int j;
	cout << "\nInforme o mapa, linha por linha.\nEspaços livres devem ser designados como '.' e impedidos como '-'.\n";
	do {
		for (i = 0; i < lin; i++){
			for (j = 0; j < col; j++){
				cin >> Mapa[i][j];
			}
		}
		cout << "\nSeu mapa é este:\n";
		for (i = 0; i < lin; i++){
			for (j = 0; j < col; j++){
				cout <<  Mapa[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Prosseguir?\n1- Sim.\n2- Não.\n";
		cin >> op;
	}while (op == 2);
	i = 0;
	j = 0;
	Mapa[i][j] =  49;
	while (i != lin-1 || j != col-1){
		if (i < lin-1 && j < col-1){
			if(Mapa[i+1][j] == 46 && i+1 <= lin-1){
				i++;
				Mapa[i][j] = 49;
				this->pos.setPosicao(i, j);
				this->p.inserirInicio(pos);
			}
			else if(Mapa[i][j+1] != 49 && Mapa[i][j+1] != 45 && j+1 < col){
				j++;
				Mapa[i][j] = 49;
				this->pos.setPosicao(i, j);
				this->p.inserirInicio(pos);
			}
			else if ((j+1 == col || Mapa[i][j+1] != 46) && (i+1 < lin || Mapa[i+1][j] != 46)){
				this->p.removeLast();
				i = p.getLast_line();
				j = p.getLast_column();
			}
		}
		else if	(i == lin-1 && j < col-1){
			if(Mapa[i][j+1] == 46 && j+1 <= col-1){
				j++;
				Mapa[i][j] = 49;
				this->pos.setPosicao(i, j);
				this->p.inserirInicio(pos);
			}
			else {
				this->p.removeLast();
				i = p.getLast_line();
				j = p.getLast_column();
			}
		}
		else if (i< lin-1 && j == col-1){
			if (Mapa[i+1][j] == 46 && i+1 < lin){
				i++;
				Mapa[i][j] = 49;
				this->pos.setPosicao(i,j);
				this->p.inserirInicio(pos);
			}
			else{
				this->p.removeLast();
				i = p.getLast_line();
				j = p.getLast_column();
			}
		}
		cont++;
	}
	cout << "\nO caminho traçado foi este:\n";
		for (i = 0; i < lin; i++){
			for (j = 0; j < col; j++){
				cout <<  Mapa[i][j] << " ";
			}
			cout << endl;
		}
	cout << "\nO caminho foi encontrado em " << cont << " interações.";
}

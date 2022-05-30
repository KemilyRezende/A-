#include <iostream>
#include "Fila.hpp"
#include "CaminhoBFS.hpp"

using namespace std;

CaminhoBFS::CaminhoBFS(int lin, int col){
	Posicao Mapa[lin][col];
	char crc;
	int op;
	cout << "\nInforme o mapa, linha por linha.\nEspaços livres devem ser designados como '.' e impedidos como '-'.\n";
	do {
		for (int i = 0; i < lin; i++){
			for (int j = 0; j < col; j++){
				cin >> crc;
				Mapa[i][j].setPosicao(i, j);
				Mapa[i][j].setValue(crc);
				Mapa[i][j].setAdded(true);
			}
		}
		cout << "\nSeu mapa é este:\n";
		for (int i = 0; i < lin; i++){
			for (int j = 0; j < col; j++){
				cout <<  Mapa[i][j].getValue() << " ";
			}
			cout << endl;
		}
		cout << "Prosseguir?\n1- Sim.\n2- Não.\n";
		cin >> op;
	}while (op == 2);
	int i = 0;
	int j = 0;
	int cont = 0;
	bool prox;
	crc = 49;
	Mapa[i][j].setValue(crc);
	f.inserirFinal(Mapa[i][j]);
	while (i != lin-1 || j != col-1){
		prox = true;
		if (i < lin-1 && j < col-1){
			if(Mapa[i+1][j].getValue() == 46 && i+1 < lin){
				i++;
				Mapa[i][j].setValue(crc);
				f.inserirFinal(Mapa[i][j]);
				Mapa[i][j].setAdded(false);
			}
			if(Mapa[i][j+1].getValue() == 46 && j+1 < col){
				j++;
				Mapa[i][j].setValue(crc);
				f.inserirFinal(Mapa[i][j]);
				Mapa[i][j].setAdded(false);
			}
			else if ((j+1 == col || Mapa[i][j+1].getValue() != 46) && (i+1 < lin || Mapa[i+1][j].getValue() != 46)){
				f.removeFirst();
				i = f.getLast_line();
				j = f.getLast_column();
				prox = false;
			}
		}
		else if	(i == lin-1 && j < col-1){
			if(Mapa[i][j+1].getValue() == 46 && j+1 <= col-1){
				j++;
				Mapa[i][j].setValue(crc);
				f.inserirFinal(Mapa[i][j]);
				Mapa[i][j].setAdded(false);
			}
			else {
				f.removeFirst();
				i = f.getLast_line();
				j = f.getLast_column();
				prox = false;
			}
		}
		else if (i< lin-1 && j == col-1){
			if (Mapa[i+1][j].getValue() == 46 && i+1 < lin){
				i++;
				Mapa[i][j].setValue(crc);
				f.inserirFinal(Mapa[i][j]);
				Mapa[i][j].setAdded(false);
			}
			else{
				f.removeFirst();
				i = f.getLast_line();
				j = f.getLast_column();
				prox = false;
			}
		}
		if (prox){
			f.removeFirst();
			i = f.getLast_line();
			j = f.getLast_column();
		}
		cont++;
	}
	cout << "\nO caminho foi encontrado em " << cont << " interações.";
}

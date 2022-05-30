#include <iostream>
#include "Fila.hpp"
#include "AEstrela.hpp"
#include <math.h>

using namespace std;

AEstrela::AEstrela(int lin, int col){
	this->lin = lin;
	this->col = col;
	Posicao Mapa[lin][col];
	char crc;
	int op;
	int media;
	media = 0;
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
	cout << "\nComo desejas calcular a média?\n1. Manhattan.\n2. Euclidiana.\n";
	cin >> media;
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
			if (Mapa[i+1][j].getValue() == 46 && i+1 < lin && Mapa[i][j+1].getValue() == 46 && j+1 < col){
				if (media == 1){
					int i1, i2, j1, j2;
					i1 = i + 1;
					j1 = j;
					i2 = i;
					j2 = j + 1;
					this->Manhattan(i1, j1, i2, j2);
					f.inserirFinal(Mapa[this->i_aux][this->j_aux]);
				}
				else {
					int i1, i2, j1, j2;
					i1 = i + 1;
					j1 = j;
					i2 = i;
					j2 = j + 1;
					this->Euclidiana(i1, i2, j1, j2);
					f.inserirFinal(Mapa[this->i_aux][this->j_aux]);
				}
			}
			else if(Mapa[i+1][j].getValue() == 46 && i+1 < lin){
				i++;
				Mapa[i][j].setValue(crc);
				f.inserirFinal(Mapa[i][j]);
				Mapa[i][j].setAdded(false);
			}
			else if(Mapa[i][j+1].getValue() == 46 && j+1 < col){
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

void AEstrela::Manhattan(int i, int j, int i2, int j2){
	int a;
	int b;
	int c;
	
	a = i - this->lin;
	if (a< 0){
		a = a*-1;
	}
	b = j - this->col;
	if (b< 0){
		b = b*-1;
	}
	a = a + b;
	
	c = i2 - this->lin;
	if (c< 0){
		c = c*-1;
	}
	b = j2 - this->col;
	if (b< 0){
		b = b*-1;
	}
	c = c + b;
	
	if (a < c){
		this->i_aux = i;
		this->j_aux = j;
	}
	else{
		this->i_aux = i2;
		this->j_aux = j2;
	}
}

void AEstrela::Euclidiana(int i, int j, int i2, int j2){
	int a;
	int b;
	int c;
	int d;
	a = pow(i - this->lin, 2);
	b = pow(j - this->col, 2);
	c = sqrt(a+b);
	a = pow(i2 - this->lin, 2);
	b = pow(j2 - this->col, 2);
	d = sqrt(a+b);
	if (c< d){
		this->i_aux = i;
		this->j_aux = j;
	}
	else{
		this->i_aux = i2;
		this->j_aux = j2;
	}
}

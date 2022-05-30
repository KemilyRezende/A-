#include <iostream>
#include "Posicao.hpp"
#include "Fila.hpp"

using namespace std;

Fila::Fila(){
	cabeca = NULL;
	cauda = NULL;
}

Fila::Fila(Posicao n){
	cabeca = new Posicao(n);
	cauda = cabeca;
}

bool Fila::verificaVazia(){
	return (cabeca == NULL);
}

void Fila::inserirFinal(Posicao n){
	Posicao* novo_no = new Posicao(n);
	
	if (n.getAdded()){
		if(verificaVazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}
}

int Fila::Size(){
	if(verificaVazia()){
		cout << "\nLista vazia -> tamanho = 0.";	
	}
	Posicao* c = cabeca;
	int tam = 0;
	do
	{
		c = c->obterProx();
		tam++;
	}
	while(c);
	
	return tam;
}

void Fila::removeFirst(){
	Posicao* c = cabeca->obterProx();
	cabeca = c;
}

int Fila::getLast_line(){
	return cabeca->Linha();
}

int Fila::getLast_column(){
	return cabeca->Coluna();
}

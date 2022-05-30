#include <iostream>
#include "Posicao.hpp"
#include "Pilha.hpp"

using namespace std;

Pilha::Pilha(){
	cabeca = NULL;
	cauda = NULL;
}

Pilha::Pilha(Posicao n){
	cabeca = new Posicao(n);
	cauda = cabeca;
}

bool Pilha::verificaVazia(){
	return (cabeca == NULL);
}

void Pilha::inserirInicio(Posicao p){
	Posicao* novo_no = new Posicao(p);

	if(verificaVazia())
	{
		cabeca = novo_no;
		cauda = novo_no;
	}
	else
	{
		novo_no->setProx(cabeca);
		cabeca = novo_no;
	}
}

int Pilha::Size(){
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

void Pilha::removeLast(){
	Posicao* c = cabeca->obterProx();
	cabeca = c;
}

int Pilha::getLast_line(){
	return cabeca->Linha();
}

int Pilha::getLast_column(){
	return cabeca->Coluna();
}

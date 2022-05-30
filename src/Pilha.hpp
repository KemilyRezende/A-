#include <iostream>
#ifndef __PILHA__HPP
#define __PILHA__HPP
#include "Posicao.hpp"

using namespace std;

class Pilha: public Posicao{
	private:
		Posicao* cabeca;
		Posicao* cauda;
	public:
		Pilha();
		Pilha (Posicao n);
		bool verificaVazia();
		void inserirInicio(Posicao n);
		int Size();	
		void removeLast();
		int getLast_column();
		int getLast_line();	
};

#endif

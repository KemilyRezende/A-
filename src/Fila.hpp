#include <iostream>
#include "Posicao.hpp"
#ifndef __FILA__HPP
#define __FILA__HPP

using namespace std;

class Fila: public Posicao{
	private:
		Posicao* cabeca;
		Posicao* cauda;
	public:
		Fila();
		Fila (Posicao n);
		bool verificaVazia();
		void inserirFinal(Posicao n);
		int Size();	
		void removeFirst();
		int getLast_column();
		int getLast_line();
};

#endif

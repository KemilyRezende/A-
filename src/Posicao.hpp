#include <iostream>
#ifndef __Posicao__HPP
#define __Posicao__HPP

using namespace std;

class Posicao{
	private:
		int lin;
		int col;
		char value;
		bool added;
		Posicao* prox;
	public:
		Posicao();
		Posicao(int lin, int col, char value, bool added);
		void setPosicao(int lin, int col);
		void setValue(char value);
		char getValue();
		int Linha();
		int Coluna();
		void setProx(Posicao* p);
		Posicao* obterProx();
		void setAdded(bool added);
		bool getAdded();
		
};

#endif

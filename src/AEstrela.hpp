#include <iostream>
#include "Fila.hpp"
#ifndef __AESTRELA__HPP
#define __AESTRELA__HPP

using namespace std;

class AEstrela{
	private:
		Fila f;
		Posicao pos;
		int lin;
		int col;
		int i_aux;
		int j_aux;
	public:
		AEstrela(int lin, int col);
		void Manhattan(int i, int j, int i2, int j2);
		void Euclidiana(int i, int j, int i2, int j2);
};

#endif

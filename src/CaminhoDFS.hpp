#include <iostream>
#include "Pilha.hpp"
#ifndef __CAMINHODFS__HPP
#define __CAMINHODFS__HPP

using namespace std;

class CaminhoDFS{
	private:
		Posicao pos;
		Pilha p;
	public:
		CaminhoDFS(int lin, int col);
};

#endif

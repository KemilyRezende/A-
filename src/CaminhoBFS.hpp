#include <iostream>
#include "Fila.hpp"
#ifndef __CAMINHOBFS__HPP
#define __CAMINHOBFS__HPP

using namespace std;

class CaminhoBFS: public Fila{
	private:
		Fila f;
		Posicao pos;
	public:
		CaminhoBFS(int lin, int col);
};

#endif

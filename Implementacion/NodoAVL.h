#ifndef NODOAVL_H
#define NODOAVL_H

#include "Puntero.h"

template <class T>
class NodoAVL {
	public:
		typedef Puntero<NodoAVL<T>> pNodoAVL;
		T dato;
		pNodoAVL izq;
		pNodoAVL der;
		int fB;

		NodoAVL(const T &e,pNodoAVL i, pNodoAVL d, int fB) : dato(e), izq(i), der(d), fB(fB){}
		NodoAVL(const NodoAVL<T> &n) : dato(n.dato), izq(n.izq), der(n.der), fB(n.fB){}

		NodoAVL<T> &operator=(const NodoAVL<T> &n) { dato= n.dato; izq = n.izq; der = n.der; fB = n.fB}

		virtual ~NodoAVL() {}
};
#endif
#ifndef ITERADORAVL_H
#define ITERADORAVL_H

#include "AVLImp.h"
#include "Array.h"
#include "NodoAVL.h"
#include <Assert.h>

template <class T>
class IteradorAVL : public Iteracion<T>
{
public:
	IteradorAVL(Puntero<NodoAVL<T>> raiz, nat largo);
	~IteradorAVL();

	bool HayElemento() const;
	const T& ElementoActual() const;
	void Avanzar();
	void Reiniciar();
	
private:
	Puntero<NodoAVL<T>> raiz;
	Array<Puntero<NodoAVL<T>>> pila;
	nat tope;

	void AgregarHastaMenor(Puntero<NodoAVL<T>> nodo);
};

#include "IteradorAVL.cpp"

#endif
#ifndef ITERADORTABLAHASH_H
#define ITERADORTABLAHASH_H

#include "Array.h"
#include "Tupla.h"
#include "NodoLista.h"

template <class C, class V>
class IteradorTablaHash : public Iterador<Tupla<C,V>>
{
public:
	IteradorTablaHash(Array<Puntero<NodoLista<Tupla<C,V>>> buckets);
	virtual ~IteradorTablaHash();
		
	bool HayElemento() const;
	const Tupla<C,V>& ElementoActual() const;
	void Avanzar();
	void Reiniciar();

private:
	Array<Puntero<NodoLista<Tupla<C,V>>> buckets;
	Puntero<NodoLista<Tupla<C,V>> nodoActual;
	nat posActual;

	void BuscarSiguiente();
};

#include "IteradorTablaHash.cpp"

#endif
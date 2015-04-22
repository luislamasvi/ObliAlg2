#ifndef ITERADORTABLAHASH_CPP
#define ITERADORTABLAHASH_CPP

#include <assert.h>
#include "IteradorTablaHash.h"

template <class C, class V>
IteradorTablaHash<C,V>::IteradorTablaHash(Array<Puntero<NodoLista<C,V>> buckets){
	this->buckets = buckets;
	Reiniciar();
}

template <class C, class V>
IteradorTablaHash<C,V>::~IteradorTablaHash(){
}

template <class C, class V>
void IteradorTablaHash<C,V>::Reiniciar(){
	posActual = 0;
	nodoActual = buckets[posActual];
	BuscarSiguiente();
}

template <class C, class V>
bool IteradorTablaHash<C,V>::HayElemento() const{
	return nodoActual != NULL;
}

template <class C, class V>
const Tupla<C,V>& IteradorTablaHash<C,V>::ElementoActual() const{
	assert(HayElemento());
	return nodoActual->datos;
}

template <class C, class V>
void IteradorTablaHash<C,V>::Avanzar(){
	assert(HayElemento());
	nodoActual = nodoActual->sig;
	BuscarSiguiente();
}

template <class C, class V>
void IteradorTablaHash<C,V>::BuscarSiguiente(){
	while (nodoActual == NULL && posActual < buckets.Largo())	{
		posActual++;
		nodoActual = buckets[posActual];
	}
}

#endif
#ifndef ITERADORAVL_CPP
#define ITERADORAVL_CPP

#include "IteradorAVL.h"

template <class T>
IteradorAVL<T>::IteradorAVL(Puntero<NodoAVL<T>> raiz, nat largo){
	this->raiz = raiz;
	pila = Array<Puntero<NodoAVL<T>>>(largo);
	Reiniciar();
}

template <class T>
IteradorAVL<T>::~IteradorAVL(){
}

template <class T>
void IteradorAVL<T>::Reiniciar(){
	for (nat i = 0; i < pila.Largo; i++)
		pila[i] = NULL;
	tope = 0;
	AgregarHastaMenor(raiz);
}

template <class T>
bool IteradorAVL<T>::HayElemento() const{
	return tope != 0;
}

template <class T>
const T& IteradorAVL<T>::ElementoActual() const{
	assert(HayElemento());
	return pila[tope - 1]->dato;
}

template <class T>
void IteradorAVL<T>::Avanzar(){
	assert(HayElemento());
	tope--;
	Puntero<NodoAVL<T>> actual = pila[tope];
	pila[tope] = NULL;
	AgregarHastaMenor(actual->der);
}

template <class T>
void IteradorAVL<T>::AgregarHastaMenor(Puntero<NodoAVL<T>> nodo){
	while (nodo != NULL){
		pila[tope] = nodo;
		tope++;
		nodo = nodo->izq;
	}
}

#endif
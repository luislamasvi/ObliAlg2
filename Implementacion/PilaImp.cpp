#pragma once
#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

#include "assert.h"

template<class T>
PilaImp<T>::PilaImp(){
	pila=nullptr;
	largo=0;
}

template<class T>
PilaImp<T>::PilaImp(T dat){
	pila = new stack<T>;
	pila->dato= dat;
	pila->sig=nullptr;
	largo=1;
}

template<class T>
PilaImp<T>::~PilaImp(){
	Vaciar();
}

template<class T>
void PilaImp<T>::Push(const T &dat){
	Puntero<stack<T>> aux= new stack<T>;
	aux->dato=dat;
	aux->sig=pila;
	pila=aux;
	largo++;
	aux=nullptr;
}

template<class T>
const T& PilaImp<T>::Top() const{
	return pila->dato;
}

template<class T>
T PilaImp<T>::Pop(){
	T ret;
	ret=pila->dato;
	pila=pila->sig;
	largo--;
	return ret;
}

template<class T>
void PilaImp<T>::Vaciar(){
	pila=NULL;
}

template<class T>
unsigned int PilaImp<T>::Largo() const{
	return largo;
}

template<class T>
bool PilaImp<T>::EsVacia() const{
	return pila==nullptr;
}


template<class T>
void PilaImp<T>::Imprimir() const{
	assert(false);
}

#endif
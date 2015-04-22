#pragma once

#ifndef PILAIMP_H
#define PILAIMP_H
#include "Puntero.h"
#include "Pila.h"

template<class T>
struct stack{
	T dato;
	Puntero<stack<T>> sig;
};

template<class T>
class PilaImp: public Pila<T>{
public:

	PilaImp();
	PilaImp(T);
	~PilaImp();

	void Push(const T &e);

	const T& Top() const;

	T Pop();

	void Vaciar();

	unsigned int Largo() const;

	bool EsVacia() const;

	void Imprimir() const;
private:
	Puntero<stack<T>> pila;
	unsigned int largo;

};

#include "PilaImp.cpp"
#endif
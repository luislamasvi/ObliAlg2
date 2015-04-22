#pragma once
#ifndef PILA_H
#define PILA_H

template <class T>
class Pila abstract {

public:

	virtual ~Pila() {}
	
	// Inserta un elemento en primer lugar
	virtual void Push(const T &e) abstract;

	// Retorna el elemento del primer lugar
	virtual const T& Top() const abstract;

	// Extrae el elemento del primer lugar y lo retorna
	virtual T Pop() abstract;

	// Vacia toda la pila
	virtual void Vaciar() abstract;

	// Retorna la cantidad de elementos de la pila
	virtual unsigned int Largo() const abstract;

	// Reorna true si la pila esta vacia
	virtual bool EsVacia() const abstract;

	virtual void Imprimir() const abstract;

};


#endif
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;
#include "Iterable.h"

template <class T>
class Lista;

// Escribe los elementos de la lista en el flujo out
template <class T>
ostream &operator<< <>(ostream& out, const Lista<T> &l) {
	for (Iterador<T> &i = l.ObtenerIterador(); !i.EsFin();) {
		out << i++ << " ";
	}
	return out;
};

template<class T>
class Lista abstract : public Iterable<T>{
public:
	virtual ~Lista(){};

	// PRE: -
	// POS: Agrega el elemento e al principio de la lista
	virtual void AgregarPpio(const T &e) abstract;

	// PRE: -
	// POS: Agrega el elemento e al final de la lista
	virtual void AgregarFin(const T &e) abstract;

	// PRE: -
	// POS: Vacia la lista
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna true si la lista esta vacia
	virtual bool EsVacia() const abstract;

	// PRE: -
	// POS: Busca si existe un elemento que sea igual a e
	// Usa el operador == del elemento e para encontrar uno igual
	virtual bool Existe(const T &e) const abstract;

	// PRE: -
	// POS: Borra el primer elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarPpio() abstract;

	// PRE: -
	// POS: Borra el ultimo elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarFin() abstract;
	
};



#endif
#ifndef COLAPRIORIDADIMP_H
#define COLAPRIORIDADIMP_H

#include "Puntero.h"
#include "Cola.h"
#include "Array.h"
#include "Comparacion.h"
typedef unsigned int nat;

template<class T>
class ColaPrioridadImp: public Cola<T>{
public:

	//Constructor
	ColaPrioridadImp(nat cant, Puntero<Comparador<T>> & cmp);

	~ColaPrioridadImp();

	T PrimElemento() const;

	void BorrarPrim();

	void Insertar(const T &);

	bool EsVacio() const;

	bool EstaLLena() const;

	void Vaciar();

private:
	Array<T> _heap;
	nat _tope;
	Puntero<Comparador<T>> _cmp;

	void FLotar(nat pos);
	void Hundir(nat pos);
};
#include "ColaPrioridadImp.cpp"
#endif
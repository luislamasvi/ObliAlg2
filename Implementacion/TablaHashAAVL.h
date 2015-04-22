#pragma once

#ifndef TABLAHASHAAVL_H
#define TABLAHASHAAVL_H

#include "Tabla.h"
#include "Array.h"
#include "FuncionHash.h"
#include "Puntero.h"
#include "Tupla.h"
#include "ABB.h"
#include "AVLImp.h"
#include "Comparador.h"

template<class C,class V>
class TablaHashAAVL:public Tabla<C,V>{
public:
	TablaHashAAVL(unsigned int max,Puntero<FuncionHash<C>> & fh, Puntero<Comparador<Tupla<C,V>> &com);

	~TablaHashAAVL();

	virtual void Agregar(const C& c, const V& v);

	virtual void Borrar(const C& c);

	virtual bool Pertenece(const C& c) const;

	virtual V& Recuperar(const C& c) const;

	virtual bool EsVacia() const;

	virtual void Vaciar();

private:
	Array<Puntero<ABB<Tupla<C,V>>>> _buckets;
	Puntero<FuncionHash<C>> _fhash;
	unsigned int _ocupados;

	unsigned int H(const C& dato){
		return fhash->CodigoDeHash(dato)%buckets.Largo;
	}
	unsigned int Primo(unsigned int num);

};
#include "TablaHashAAVL.cpp"
#endif
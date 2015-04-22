/*
#pragma once

#ifndef TABLAHASHA_H
#define TABLAHASHA_H

#include "Tabla.h"
#include "Array.h"
#include "FuncionHash.h"
#include "Puntero.h"
#include "Tupla.h"
#include "Lista.h"
#include "ListaImp.h"

template<class C,class V>
class TablaHashA:public Tabla<C,V>{
public:
	TablaHashA(unsigned int max,Puntero<FuncionHash<C>> fh);

	~TablaHashA();

	virtual void Agregar(const C& c, const V& v);

	virtual void Borrar(const C& c);

	virtual bool Pertenece(const C& c) const;

	virtual V& Recuperar(const C& c) const;

	virtual bool EsVacia() const;

	virtual void Vaciar();

private:
	Array<Lista<Tupla<C,V>>> _buckets;
	Puntero<FuncionHash<C>> _fhash;
	unsigned int _ocupados;

	unsigned int H(const C& dato){
		return fhash->CodigoDeHash(dato)%buckets.Largo;
	}
	unsigned int Primo(unsigned int num);

};
#include "TablaHashA.cpp"
#endif
*/
#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Tabla.h"
#include "FuncionHash.h"
#include "Array.h"
#include "NodoLista.h"

template <class C, class V>
class TablaHash : public Tabla<C,V>{

public:
	TablaHash(Puntero<FuncionHash<C>> fHash, nat cantBuckets, float factorCarga = 1.5);
	virtual ~TablaHash();

	void BorrarTodo();
	void Agregar(const C& clave, const V& valor);
	void Borrar(const C& clave);
	bool Pertenece(const C& clave) const;
	bool EsVacio() const;
	bool EstaLleno() const;
	V& Obtener(const C& clave) const;
	bool ObtenerRecuperar(const C& clave, V& valor) const;
	nat LargoT() const;
	Puntero<Iterador<C>> Claves() const;
	Puntero<Iterador<V>> Valores() const;
	Puntero<Iterador<Tupla<C,V>>> ObtenerIterador() const;

private:
	Array<Puntero<NodoLista<C,V>> buckets;
	Puntero<FuncionHash<C>> fHash;
	float factorCarga;
	nat ocupados;
};

#include "TablaHash.cpp"

#endif
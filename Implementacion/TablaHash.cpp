#ifndef TABLAHASH_CPP
#define TABLAHASH_CPP

#include "TablaHash.h"
//#include "TablaIteradorValores.h"
#include "IteradorTablaHash.h"

template <class C, class V>
TablaHash<C,V>::TablaHash(Puntero<FuncionHash<C>> fHash, nat cantBuckets, float factorCarga = 1.5)
{
	this->fHash = fHash;
	this->factorCarga = factorCarga;
	buckets = Array<Puntero<nodoLista<C,V>>>(cantBuckets);
	for(nat i=0;i<cantBuckets;i++) buckets[i]=NULL;
	largo = 0;
}


template <class C, class V>
TablaHash<C,V>::~TablaHash()
{	
	BorrarTodo();
}


template <class C, class V>
void TablaHash<C,V>::BorrarTodo()
{
	buckets = Array<Puntero<nodoLista<C,V>>>(buckets.Largo());
	largo = 0;
}


template <class C, class V>
void TablaHash<C,V>::Agregar(const C& clave, const V& valor){
	nat pos = fHash->CodigoDeHash(clave) % buckets.Largo();
	Puntero<nodoLista<C,V>> lista = buckets[pos];
	while (lista != NULL){
		if (lista->datos.GetDato1() == clave)		{
			lista->datos = Tupla<C,V>(clave, valor);
			return;
		}
		lista = lista->sig;
	}
	lista = new nodoLista<C,V>(Tupla<C,V>(clave, valor));
	lista->sig = buckets[pos];
	buckets[pos] = lista;
	largo++;
}


template <class C, class V>
void TablaHash<C,V>::Borrar(const C& clave){
		nat pos = fHash->CodigoDeHash(clave) % buckets.Largo();
		Puntero<nodoLista<C,V>> lista = buckets[pos];
		//si esta primero
		if(lista->datos.GetDato1()==clave){
			buckets[pos] = lista->sig;
			largo--;
			return;
		}
		while (lista->sig != NULL)
		{
			if (lista->sig->datos.GetDato1() == clave)
			{	lista->sig=lista->sig->sig;
				largo--;
				return;
			}
			lista = lista->sig;
		}
		//si esta ultimo
		if(lista->datos.GetDato1()==clave){
			lista=NULL;
			largo--;
			return;
		}	
}


template <class C, class V>
bool TablaHash<C,V>::Pertenece(const C& clave) const{
	nat pos = fHash->CodigoDeHash(clave) % buckets.Largo();
	Puntero<nodoLista<C,V>> lista = buckets[pos];
	while (lista != NULL)
	{
		if (lista->datos.GetDato1() == clave)
			return true;
		lista = lista->sig;
	}
	return false;
}

template <class C, class V>
bool TablaHash<C,V>::EsVacio() const{
	return largo == 0;
}

template <class C, class V>
bool TablaHash<C,V>::EstaLleno() const
{
	return Largo() >= factorCarga * buckets.Largo();
}


template <class C, class V>
V& TablaHash<C,V>::Recuperar(const C& clave) const{
	assert(Pertenece(clave));
	nat pos = fHash->CodigoDeHash(clave) % buckets.Largo();

	Puntero<nodoLista<C,V>> lista = buckets[pos];
	while (lista != NULL)
	{
		if (lista->datos.GetDato1() == clave)
			break;
		lista = lista->sig;
	}
	assert(lista != NULL);
	return lista->datos.GetDato2();
}


template <class C, class V>
bool TablaHash<C,V>::IntentarRecuperar(const C& clave, V& valor) const{
	nat pos = fHash->CodigoDeHash(clave) % buckets.Largo();
	Puntero<nodoLista<C,V>> lista = buckets[pos];

	while (lista != NULL)	{
		if (lista->datos.GetDato1() == clave)		{
			valor = lista->datos.GetDato2();
			return true;
		}
		lista = lista->sig;
	}
	return false;
}

template <class C, class V>
nat TablaHash<C,V>::Largo() const{
	return largo;
}

template <class C, class V>
Puntero<Iterador<C>> TablaHash<C,V>::Claves() const
{
	return NULL;
}

template <class C, class V>
Puntero<Iterador<V>> TablaHash<C,V>::Valores() const
{
	return nullptr;//new TablaIteradorValores<C,V>(ObtenerIterador());
}

template <class C, class V>
Puntero<Iterador<Tupla<C,V>>> TablaHash<C,V>::ObtenerIterador() const
{
	return new IteradorTablaHashC,V>(buckets);
}

#endif
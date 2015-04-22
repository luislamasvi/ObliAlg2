#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Puntero.h"
#include "Tupla.h"

template <class C, class V>
class NodoLista{
	public:
		Tupla<C,V> datos;
		Puntero<NodoLista<C,V>> sig;

		//Puntero<nodoLista<C,V>> sig;

		NodoLista(Tupla<C,V> d): datos(d){}
		//NodoLista(const Tupla<C,V> &e, Puntero<NodoLista<Tupla<C,V>> s) : datos(e), sig(s) {}
		//NodoLista(const NodoLista<Tupla<C,V>> &n) : datos(n.datos), sig(n.sig)  {}
		
		bool operator==(const NodoLista<C,V> &n){
			return this == &n;
		}

		NodoLista<C,V> &operator=(const NodoLista<C,V> &n) { 
			if (this != &n){
				datos= n.datos; sig = n.sig; 
			}
			return Puntero<this>;
		}

		virtual ~NodoLista() {}
};
#endif

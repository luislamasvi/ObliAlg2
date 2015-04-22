#ifndef LISTAIMP_H
#define LISTAIMP_H

#include "Lista.h"
#include "Puntero.h"
#include "IteradorListaImp.h"

template <class T>
class IteradorListaImp;

template <class T>
class NodoLista {
	public:
		T dato;
		Puntero<NodoLista<T>> sig;
		Puntero<NodoLista<T>> ant;

		virtual ~NodoLista() {}

		bool operator==(const NodoLista<T>& nodo) { return this == &nodo; }
};

template <class T>
class ListaImp: public Lista<T> {
	friend class IteradorListaImp<T>; 
	friend ostream &operator<< <>(ostream& o, const ListaImp<T> & l);
public:

	// Constructor por defecto
	ListaImp();

	// Constructor copia
	ListaImp(const Lista<T> &l);

	// Operador de asignacion
	Lista<T> &operator=(const Lista<T> &l);

	~ListaImp();
	
	void AgregarPpio(const T &e);
	void AgregarFin(const T &e);
	void Vaciar();
	
	bool EsVacia() const;
    bool Existe(const T &e) const;
	
	void BorrarPpio();
	void BorrarFin();
	
private:

	Puntero<NodoLista<T>> ppio;
	Puntero<NodoLista<T>> fin;

	bool Existe(Puntero<NodoLista<T>> nodo,const T &e) const ;
};

#include "ListaImp.cpp"

#endif
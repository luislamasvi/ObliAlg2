#ifndef AVLIMP_H
#define AVLIMP_H

#include "NodoAVL.h"
#include "AVL.h"
#include "Comparador.h"
#include "Puntero.h"


template<class T>
class AVLImp:public AVL<T>{
public:
	AVLImp(Puntero<Comparacion<T>> & comp);
	~AVLImp();
	void Vaciar();
	bool Insertar(const T &e);
	void Borrar(const T &e);
	bool Existe(const T &e) const;
	const T& Recuperar(const T &e) const;
	
	Iterador<T> ObtenerIterador() const;
	nat CantNodos() const;

private:
	//Atributos
	Puntero<NodoAVL<T>> raiz;
	bool varioH;
	nat cantNodos;
	Puntero<Comparador<T>> comparador;
	
	//Metodos Privados (raiz)
	void Vaciar(Puntero<NodoAVL<T>> &r);
	bool Insertar(const T &e, Puntero<NodoAVL<T>> &r);
	bool ResolverCambioAltura(Puntero<NodoAVL<T>> &r);
	void RotacionSimpleIzq(Puntero<NodoAVL<T>> &r);
	void RotacionDobleIzq(Puntero<NodoAVL<T>> &r);
	void RotacionSimpleDer(Puntero<NodoAVL<T>> &r);
	void RotacionDobleDer(Puntero<NodoAVL<T>> &r);

	void Borrar(const T &e, Puntero<NodoAVL<T>> &r);
	void BalanceoI(Puntero<NodoAVL<T>> &r);
	void BalanceoD(Puntero<NodoAVL<T>> &r);
	Puntero<NodoAVL<T>> BuscarMayor(Puntero<NodoAVL<T>> r);
	void BorrarMayor(Puntero<NodoAVL<T>> &r);
	/*void RotElimSimpDer(Puntero<NodoAVL<T>> &r);
	void RotElimSimpIzq(pNodoAVL &r);*/

	bool Existe(const T &e, const Puntero<NodoAVL<T>> &r) const;
	const T& Recuperar(const T &e, const Puntero<NodoAVL<T>> &r)const;

};
#include "AVLImp.cpp"
#endif




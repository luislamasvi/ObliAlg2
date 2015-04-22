#ifndef AVLIMP_CPP
#define AVLIMP_CPP

#include "AVLImp.h"
#include "IteradorAVL.h"

template <class T>
AVLImp<T>::AVLImp(Puntero<Comparacion<T>> & comp){
	this->raiz = nullptr;
	this->varioH = false;
	this->cantNodos = 0;
	this->comparador =comp;
}

template <class T>
AVLImp<T>::~AVLImp(){
	Vaciar();
}

template<class T>
void AVLImp<T>::Vaciar(){
	Vaciar(raiz);
}

template<class T>
void AVLImp<T>::Vaciar(Puntero<NodoAVL<T>> &r){
	if(r!=nullptr){
		Vaciar(r->izq);
		Vaciar(r->der);
		r=nullptr;
		this->comparador=nullptr;
	}
}

template <class T>
bool AVLImp<T>::Insertar(const T &e){
	return Insertar(e,raiz);
}

template <class T>
bool AVLImp<T>::Insertar(const T &e, Puntero<NodoAVL<T>> &r){
	if(r==nullptr){
		r = new NodoAVL<T>(e,nullptr,nullptr,0)
		this->cantNodos++;
		return true; 
	}
	else if(this->comparador->EsMayor(r->dato, e)){
			if(Insertar(e,r->izq)){
				r->fB++;
				return ResolverCambioAltura(r);
			}
			else
				return false; 
	}
	else if(this->comparador->EsMenor(r->dato, e)){
			if(Insertar(e,r->der)){
				r->fB--;
				return ResolverCambioAltura(r);
		    }
			else
				return false; 
	}
	else 
	   return false;
}

template <class T>
bool AVLImp<T>::ResolverCambioAltura(Puntero<NodoAVL<T>> &r){
	switch(r->fB){
	case 0:
		return false;
	case -1:
	case 1:
		return true;
	case 2:
		if(r->izq->fB==1)
			RotacionSimpleIzq(r);
		else{
			assert(r->izq->fB==-1);
			RotacionDobleIzq(r);
		}
		return false;
	case -2:
		if(r->der->fB==-1)
			RotacionSimpleDer(r);
		else{
			assert(r->der->fB==1);
			RotacionDobleDer(r);
		}
		return false;
	}
	default: return false;
}

template <class T>
void AVLImp<T>::RotacionSimpleIzq(Puntero<NodoAVL<T>> &r){
	Puntero<NodoAVL<T>> a = r;
	Puntero<NodoAVL<T>> b = a->izq;
	Puntero<NodoAVL<T>> f = b->der;
	a->izq = f;
	a->fB = 0;
	b->der = a;
	b->fB = 0;
	r = b;
}

template <class T>
void AVLImp<T>::RotacionDobleIzq(Puntero<NodoAVL<T>> &r){
	Puntero<NodoAVL<T>> a = r;
	Puntero<NodoAVL<T>> p1 = a->izq;
	Puntero<NodoAVL<T>> p2 = p1->der;
	p2 = p1->der;
	p1->der = p2->izq;
	p2->izq = p1;
	a->izq = p2->der;
	p2->der = a;
	a->fB = p2->fB == -1 ? 1:0;
	p1->fB = p2->fB == 1 ?-1:0;
	r = p2;
}

template <class T>
void AVLImp<T>::RotacionSimpleDer(Puntero<NodoAVL<T>> &r){
	Puntero<NodoAVL<T>> a = r;
	Puntero<NodoAVL<T>> b = a->der;
	Puntero<NodoAVL<T>> e = b->izq;
	b->izq = a;
	b->fB = 0;
	a->der = e;
	a->fB = 0;
	r = b;
}

template <class T>
void AVLImp<T>::RotacionDobleDer(Puntero<NodoAVL<T>> &r){
	Puntero<NodoAVL<T>> a = r;
	Puntero<NodoAVL<T>> p1 = a->izq;
	Puntero<NodoAVL<T>> p2 = p1->der;
	p2 = p1->izq;
	p1->izq = p2->der;
	p2->der = p1;
	a->der = p2->izq;
	p2->izq = a;
	a->fB = p2->fB == 1? -1: 0;
	p1->fB = p2->fB == -1 ? 1 : 0;
	r = p2;
}

template <class T>
void AVLImp<T>::Borrar(const T &e){
	Borrar(e,raiz);
}

template <class T>
void AVLImp<T>::Borrar(const T &e, Puntero<NodoAVL<T>> &r){
	if(r != nullptr){
		if(comparador->EsMayor(r->dato,e)){
			Borrar(e, r->izq);
			if(varioH)
				BalanceoI(r);
		}
		else if(comparador->EsMenor(r->dato, e)){
			Borrar(e, r->der);
			if(varioH)
				BalanceoD(r);
		}
		else{
			if(r->izq!=nullptr && r->der!=nullptr){
				Puntero<NodoAVL<T>> ptrMax = BuscarMayor(actual->izq);
				r->dato = ptrMax->dato;
				BorrarMayor(r->izq);
				if(varioH)
					BalanceoI(r);
			}
			else if(r->izq != nullptr){
				r = r->izq;
				varioH = true;
			}
			else if(r->der != nullptr){
				r = r->der;
				varioH = true;
			}
		}
	}	
}

template<class T>
void AVLImp<T>::BalanceoI(Puntero<NodoAVL<T>> &r){
	int fB = r->fB;
	if(fB == 1){
		r->fB = 0;
		varioH = true;
	}
	else if(fB == 0){
		r->fB = -1;
		varioH = false;
	}
	else{
		r->fB = -2;
		ResolverCambioAltura(r);
		varioH=false;
	}
}

template<class T>
void AVLImp<T>::BalanceoD(Puntero<NodoAVL<T>> &r){
	int fB = r->fB;
	if(fB == -1){
		r->fB = 0;
		varioH = true;
	}
	else if(fB == 0){
		r->fB = 1;
		varioH = false;
	}
	else{
		r->fB = 2;
		ResolverCambioAltura(r);
		varioH = false;
	}
}

template<class T>
Puntero<NodoAVL<T>> AVLImp<T>::BuscarMayor(Puntero<NodoAVL<T>> r){
		while(r->der! = nullptr){
			r=r->der;
		}
		return r;
}

template<class T>
void AVLImp<T>::BorrarMayor(Puntero<NodoAVL<T>> &r){
	if(r->der != nullptr){
		BorrarMayor(r->der);
		if(varioH)
			BalanceoD(r);
	}
	else{
		r=r->izq;
		varioH=true;
	}
}

template <class T>
bool  AVLImp<T>::Existe(const T &e) const{
	return Existe(e,raiz);
}

template <class T>
bool AVLImp<T>::Existe(const T &e, const Puntero<NodoAVL<T>> &r) const{
	if(r!=nullptr){
		if(this->comparador->SonIguales(r->dato,e))
				return true;
		else{
			if(this->comparador->EsMayor(r->dato,e))
					return Existe(e,r->izq);
			else
					return Existe(e,r->der);
		}
		else
			return false;
	}
}

template <class T>
const T& AVLImp<T>::Recuperar(const T &e)const{
	return Recuperar(e,raiz);
}

template <class T>
const T& AVLImp<T>::Recuperar(const T &e, const Puntero<NodoAVL<T>> &r)const{
	if(this->comparador->SonIguales(r->dato,e))
		return r->dato;
	else{
		if(this->comparador->EsMayor(r->dato,e))
			return Recuperar(e,r->izq);
		else
			return Recuperar(e,r->der);
	}
}

template <class T>
Iterador<T> AVLImp<T>::ObtenerIterador() const{
	if(raiz!=nullptr)
		return new IteradorAVL<T>(raiz, CantElementos());
	else
		return nullptr;
}

template <class T>
nat AVLImp<T>::CantNodos() const{
	return this->cantNodos;
}
#endif
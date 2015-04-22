#ifndef LISTAIMP_CPP
#define LISTAIMP_CPP

#include "ListaImp.h"

template <class T>
ostream &operator<< <>(ostream& out, const ListaImp<T> &l) {
	for (Iterador<T> &i = l.ObtenerIterador(); !i.EsFin();) {
		i.Resto();
		out << i.ElementoActual() << " ";
	}
	return out;
}

template <class T>
ListaImp<T>::ListaImp(){
	largo =0;
	ppio=NULL;
	fin=NULL;
}

template <class T>
ListaImp<T>::~ListaImp(){
	while(!EsVacia()){
		BorrarPpio();
	}
}

template <class T>
void ListaImp<T>::AgregarPpio(const T &e){
	Puntero<NodoLista<T>> nuevo=new NodoLista<T>();
	nuevo->dato=e;
	nuevo->sig=ppio;
	nuevo->ant=NULL;
	if(ppio==NULL){
		ppio=nuevo;
		fin=nuevo;
	}
	else{
		ppio->ant=nuevo;
		ppio=nuevo;
	}
	largo++;
}

template <class T>
void ListaImp<T>::AgregarFin(const T &e){
	Puntero<NodoLista<T>> nuevo=new NodoLista<T>();
	nuevo->dato=e;
	nuevo->sig=NULL;
	nuevo->ant=fin;
	if(fin==NULL){
		ppio=nuevo;
		fin=nuevo;
	}
	else{
		nuevo->ant = fin;
		fin->sig=nuevo;
		fin=nuevo;
	}
	largo++;
}

template <class T>
void ListaImp<T>::Vaciar(){
	if (ppio==NULL)
		return;
	BorrarFin();
	Vaciar();
}

template <class T>
bool ListaImp<T>::EsVacia()const { 

	return largo==0;
}

template <class T>
bool ListaImp<T>::Existe(const T &e) const {

	Puntero<NodoLista<T>> nodo=ppio;
	return PerteneceAux(nodo,e);

}

template <class T>
bool ListaImp<T>::Existe(Puntero<NodoLista<T>> nodo,const T &e) const {
	if(nodo==NULL){
		return false;
	}
	if(nodo->dato==e){
		return true;			
	}
		else{
			return PerteneceAux(nodo->sig,e);
		}
}

template <class T>
void ListaImp<T>::BorrarPpio(){
	if(largo==1){
	ppio=NULL;
	fin=NULL;
	largo--;
	return ;
	}
	else{
	ppio=ppio->sig;
	ppio->ant=NULL;
	largo--;
	return ;
	}
}

template <class T>
void ListaImp<T>::BorrarFin(){
	if(largo==1){
	ppio=NULL;
	fin=NULL;
	largo--;
	return ;
	}
	else{
	fin=fin->ant;
	fin->sig=NULL;
	largo--;
	return ;
	}
}

template <class T>
Lista<T> &ListaImp<T>::operator=(const Lista<T> &l) { 
	if (this != &l) {
		this->Vaciar();
		for (Iterador<T> &i = l.ObtenerIterador(); !i.EsFin();) {
			AgregarFin(i++);
		}
	}
	return Puntero<this>;	
}

template <class T>
Puntero<Iterador<T>> ListaImp<T>::ObtenerIterador() const {
	return new IteradorListaImp<T>(*this);
}

#endif
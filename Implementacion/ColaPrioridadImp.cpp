#ifndef COLAPRIORIDADIMP_CPP
#define COLAPRIORIDADIMP_CPP

#include "ColaPrioridadImp.h"

template<class T>
ColaPrioridadImp<T>::ColaPrioridadImp(nat cant, Puntero<Comparador<T>> & cmp){
	_cmp=cmp;
	_heap = Array<T>(cant);
	_tope=0;
}

template<class T>
ColaPrioridadImp<T>::~ColaPrioridadImp(){
	Vaciar();
}

template<class T>
T ColaPrioridadImp<T>::PrimElemento() const{
	return _heap[0];
}

template<class T>
void ColaPrioridadImp<T>::BorrarPrim(){
	_heap[0]=_heap[_tope-1];
	_tope--;
	Hundir(0);
}

template<class T>
void ColaPrioridadImp<T>::Hundir(nat pos){
	nat hizq = pos*2+1;
	if(hizq<_tope){
		nat hder=pos*2+2;
		if(hder<_tope && _cmp->EsMayor(_heap[hizq],_heap[hder])){
			if(_cmp->EsMayor(_heap[pos],_heap[hder])){
				T dat=_heap[hder];
				_heap[hder]=_heap[pos];
				_heap[pos]=dat;
				Hundir(hder);
			}
		}
		else{
			if(_cmp->EsMayor(_heap[pos],_heap[hizq])){
				T dat=_heap[hizq];
				_heap[hizq]=_heap[pos];
				_heap[pos]=dat;
				Hundir(hizq);
			}
		}
	}

	
}

template<class T>
void ColaPrioridadImp<T>::Insertar(const T &dato){
	_heap[_tope]=dato;
	Flotar(_tope);
	_tope++;
}

template<class T>
void ColaPrioridadImp<T>::FLotar(nat pos){
	nat padre=(pos-1)/2;
	if(pos!=0){
		if(_cmp->EsMenor(_heap[pos],_heap[padre])){
			T dat=_heap[padre];
			_heap[padre]=_heap[pos];
			_heap[pos]=dat;
			Flotar(padre);
		}
	}
}

template<class T>
bool ColaPrioridadImp<T>::EsVacio() const{
	return _heap[0]==NULL;
}

template<class T>
bool ColaPrioridadImp<T>::EstaLLena() const{
	return _heap[_heap.Largo-1]!=NULL;
}

template<class T>
void ColaPrioridadImp<T>::Vaciar(){
	_cmp=nullptr;
	_tope=0;
	_heap=NULL;
}


#endif
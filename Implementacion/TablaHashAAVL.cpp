#ifndef TABLAHASHAAVL_CPP
#define TABLAHASHAAVL_CPP

#include "TablaHashAAVL.h"

template<class C,class V>
TablaHashAAVL<C,V>::TablaHashAAVL(unsigned int max,Puntero<FuncionHash<C>> & fh,Puntero<Comparador<C>> &comp){
	_buckets= Array<Puntero<ABB<Tupla<C,V>>>>(Primo(max));
	for(unsigned int i=0; i<_buckets.Largo;i++){
		_buckets[i]= new AVLImp<Tupla<C,V>>(comp);
	}
	_ocupados=0;
	_fhash=fh;
}

template<class C,class V>
unsigned int TablaHashAAVL<C,V>::Primo(unsigned int num){
	if(num==1||num==0){
		return 1;
	}
	unsigned int aux=num-1;
	while(num%aux!=0){
		aux--;
	}
	if(aux==1)
		return num;
	else
		return Primo(num++);
}

template<class C,class V>
TablaHashAAVL<C,V>::~TablaHashAAVL(){
	Vaciar();
}

template<class C,class V>
void TablaHashAAVL<C,V>::Agregar(const C& c, const V& v){
	unsigned int pos= _fhash->CodigoDeHash(c)%_buckets.Largo;
	_buckets[pos]->Insertar(Tupla<C,V>(c,v));
	_ocupados++;
	
}

template<class C,class V>
void TablaHashAAVL<C,V>::Borrar(const C& c){
	unsigned int pos= _fhash->CodigoDeHash(c)%_buckets.Largo;
	_buckets[pos]->Borrar(Tupla<C,V>(c));
	_ocupados--;
}

template<class C,class V>
bool TablaHashAAVL<C,V>::Pertenece(const C& c) const{
	unsigned int pos= _fhash->CodigoDeHash(c)%_buckets.Largo;
	
	return _buckets[pos]->Existe(Tupla<C,V>(c));
}

template<class C,class V>
V& TablaHashAAVL<C,V>::Recuperar(const C& c) const{
	unsigned int pos= _fhash->CodigoDeHash(c)%_buckets.Largo;
	
	return _buckets[pos]->Recuperar(Tupla<C,V>(c));
}

template<class C,class V>
bool TablaHashAAVL<C,V>::EsVacia() const{
	return _ocupados==0;
}

template<class C,class V>
void TablaHashAAVL<C,V>::Vaciar(){
	_ocupados=0;
	_fhash=nullptr;
	for(unsigned int i=0; i<_buckets.Largo ; i++){
		_buckets[i]=NULL;
	}
}

#endif
/* 
#include "TablaHashA.h"

#ifndef TABLAHASHA_CPP
#define TABLAHASHA_CPP

template<class C,class V>
TablaHashA<C,V>::TablaHashA(unsigned int max,Puntero<FuncionHash<C>> fh){
	_ocupados=0;
	_fhash=fh;
	_buckets= Array<Punteros<ListaImp<Tupla<C,V>>>>(Primo(max));
	for(int i=0; i<_buckets.Largo;i++){
		_buckets[i]= new ListaImp<Tupla<C,V>>();
	}
}

template<class C,class V>
unsigned int TablaHashA<C,V>::Primo(unsigned int num){
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
TablaHashA<C,V>::~TablaHashA(){
	Vaciar();
}

template<class C,class V>
void TablaHashA<C,V>::Agregar(const C& c, const V& v){
	unsigned int pos= _fhash->CodigoDeHash(c)%_buckets.Largo;
	_buckets[pos]->AgregarPpio(Tupla<c,v>);
	_ocupados++;
	
}

template<class C,class V>
void TablaHashA<C,V>::Borrar(const C& c){

}

template<class C,class V>
bool TablaHashA<C,V>::Pertenece(const C& c) const{
	return true;
}

template<class C,class V>
V& TablaHashA<C,V>::Recuperar(const C& c) const{
	return V;
}

template<class C,class V>
bool TablaHashA<C,V>::EsVacia() const{
	return true;
}

template<class C,class V>
void TablaHashA<C,V>::Vaciar(){

}

#endif
*/
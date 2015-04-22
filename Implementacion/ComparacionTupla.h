#pragma once
#ifndef COMPARACIONTUPLA_H
#define COMPARACIONTUPLA_H

#include "Comparador.h"
#include "Tupla.h"

template<class C,class V>
class ComparacionTupla: public Comparacion<C>{
public:
	//CompRetorno Comparar(const T& t1, const T& t2) const
	CompRetorno Comparar(const Tupla<C,V> & t1, const Tupla<C,V> & t2) const{
		if(t1.ObtenerDato1()==t2.ObtenerDato1()) //if(t1.Dato1==t2.Dato1)
			return IGUALES;
		else if(t1.ObtenerDato1()<t2.ObtenerDato1())
			return MENOR;
		else 
			return MAYOR;
	}

};


#endif
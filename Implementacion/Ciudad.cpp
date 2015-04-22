#ifndef CIUDAD_CPP
#define CIUDAD_CPP

#include "Ciudad.h"

Ciudad::Ciudad(Cadena Nombre,nat CostoPorDia){
	Nombre=Nombre;
	Costo=CostoPorDia;
}

Cadena Ciudad:: ObtenerNombreCiudad() const{
	return Nombre;
}
nat Ciudad:: ObtenerCostoPorDia() const{
	return Costo;
}

Iterador<nat> Ciudad:: ObtenerExcursionesQueLaVisitan() const{
	return nullptr;
}

bool Ciudad::operator==(const ICiudad& c) const{
	return this->ObtenerNombreCiudad()==c.ObtenerNombreCiudad();
}

#endif

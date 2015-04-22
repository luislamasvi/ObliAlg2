#ifndef EXCURSION_CPP
#define EXCURSION_CPP

#include "Excursion.h"

Excursion::Excursion(nat nroExcursion,nat fechaDePartida, nat duracion, nat valor){
	this->nroExcursion = nroExcursion;
	this->fechaDePartida = fechaDePartida;
    this->duracion = duracion;
	this->valor = valor;
	//this->listaDeCiudades = nullptr;
}

Excursion::~Excursion(){}

nat Excursion::ObtenerNroExcursion() const{
	return this->nroExcursion;
}
nat Excursion::ObtenerFechaDePartida() const{
	return this->fechaDePartida;
}

nat Excursion::ObtenerDuracion() const{
	return this->duracion;
}

nat Excursion::ObtenerValor() const{
	return this->valor;
}

Iterador<Tupla<Cadena, nat>> Excursion:: ObtenerItinerario() const{
	return nullptr;
}

bool Excursion::operator ==(const IExcursion& e) const{
	return ObtenerNroExcursion()==e.ObtenerNroExcursion();
}

#endif
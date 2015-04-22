#ifndef CLIENTE_CPP
#define CLIENTE_CPP

#include "Cliente.h"

Cliente::Cliente(nat CI, Cadena nombreCliente, nat fechaRegCliente, Iterador<nat> excursionesRealizadas){
	this->CI=CI;
	this->nombreCliente = nombreCliente;
	this->fechaRegCliente = fechaRegCliente;
	this->excursionesRealizadas = excursionesRealizadas;
}

nat Cliente::ObtenerCiCliente() const{
	return this->CI;
}

Cadena Cliente::ObtenerNombreCliente() const{
	return this->nombreCliente;
}

nat Cliente::ObtenerFechaRegCliente() const{
	return this->fechaRegCliente;
}

Iterador<nat> Cliente::ObtenerExcursionesRealizadas() const{
	return this->excursionesRealizadas;
}

bool Cliente::operator ==(const ICliente& e) const{
	return this->ObtenerCiCliente()==e.ObtenerCiCliente();
}

#endif
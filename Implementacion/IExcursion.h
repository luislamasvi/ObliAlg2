#pragma once

#include "Puntero.h"
#include "Iterador.h"
#include "Tupla.h"
#include "Cadena.h"

class IExcursion abstract
{
public:
	virtual ~IExcursion(){}

	virtual nat ObtenerNroExcursion() const abstract;
	virtual nat ObtenerFechaDePartida() const abstract;
	virtual nat ObtenerDuracion() const abstract;
	virtual nat ObtenerValor() const abstract;
	virtual Iterador<Tupla<Cadena, nat>> ObtenerItinerario() const abstract;

	virtual bool operator==(const IExcursion& e) const abstract;
};
typedef Puntero<IExcursion> pExcursion;
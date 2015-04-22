#pragma once

#include "Puntero.h"
#include "Cadena.h"
#include "Iterador.h"

class ICiudad abstract
{
public:
	virtual ~ICiudad(){}

	virtual Cadena ObtenerNombreCiudad() const abstract;
	virtual nat ObtenerCostoPorDia() const abstract;
	virtual Iterador<nat> ObtenerExcursionesQueLaVisitan() const abstract;

	virtual bool operator==(const ICiudad& c) const abstract;
};
typedef Puntero<ICiudad> pCiudad;
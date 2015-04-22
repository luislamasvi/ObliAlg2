#pragma once

#include "Puntero.h"
#include "Cadena.h"
#include "Iterador.h"

class ICliente abstract
{
public:
	virtual ~ICliente(){}

	virtual nat ObtenerCiCliente() const abstract;
	virtual Cadena ObtenerNombreCliente() const abstract;
	virtual nat ObtenerFechaRegCliente() const abstract;
	virtual Iterador<nat> ObtenerExcursionesRealizadas() const abstract;

	virtual bool operator==(const ICliente& c) const abstract;
};
typedef Puntero<ICliente> pCliente;
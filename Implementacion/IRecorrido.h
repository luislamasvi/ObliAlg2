#pragma once

#include "Puntero.h"
#include "Cadena.h"
#include "Iterador.h"
#include "Tupla.h"
#include "TipoTransporte.h"

class IRecorrido abstract
{
public:
	virtual ~IRecorrido(){}

	virtual Cadena ObtenerNombreCiudadOrigen() const abstract;
	virtual Iterador<Tupla<TipoTransporte, Cadena>> ObtenerTraslados() const abstract;
	virtual nat ObtenerCostoTotalTraslados() const abstract;
	virtual float ObtenerTiempoTotalTraslados() const abstract;

	virtual bool operator==(const IRecorrido& r) const abstract;
};
typedef Puntero<IRecorrido> pRecorrido;
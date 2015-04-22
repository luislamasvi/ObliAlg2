#ifndef CIUDAD_H
#define CIUDAD_H

#include "ICiudad.h"

class Ciudad : public ICiudad
{
public:
	Ciudad(Cadena Nombre,nat CostoPorDia);
	~Ciudad(){}

	Cadena ObtenerNombreCiudad() const;
	nat ObtenerCostoPorDia() const;
	Iterador<nat> ObtenerExcursionesQueLaVisitan() const;

	bool operator==(const ICiudad& c) const;

private:
	Cadena Nombre;
	nat Costo;
};

#endif
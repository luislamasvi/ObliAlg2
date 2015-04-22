#ifndef CLIENTE_H
#define CLIENTE_H

#include "ICliente.h"

class Cliente : public ICliente{

public:
	Cliente(nat CI, Cadena nombreCliente, nat fechaRegCliente, Iterador<nat> excursionesRealizadas);
	~Cliente(){}

	nat ObtenerCiCliente() const;
	Cadena ObtenerNombreCliente() const;
	nat ObtenerFechaRegCliente() const;
	Iterador<nat> ObtenerExcursionesRealizadas() const;

	bool operator==(const ICliente& c) const;
	

private:
	nat CI;
	Cadena nombreCliente;
	nat fechaRegCliente;
	Iterador<nat> excursionesRealizadas;
};
#endif
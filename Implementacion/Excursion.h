#ifndef EXCURSION_H
#define EXCURSION_H

#include "IExcursion.h"
//#include "Lista.h"
#include "Ciudad.h"

class Excursion : public IExcursion{

public:
	Excursion(nat nroExcursion,nat fechaPartida);
	Excursion(nat nroExcursion,nat fechaPartida, nat duracion, nat valor);
	virtual ~Excursion();

	nat ObtenerNroExcursion() const;
	nat ObtenerFechaDePartida() const;
	nat ObtenerDuracion() const;
	nat ObtenerValor() const;
	Iterador<Tupla<Cadena, nat>> ObtenerItinerario() const;

	bool operator==(const IExcursion& e) const;
	

private:
	nat nroExcursion;
	nat fechaDePartida;
	nat duracion;
	nat valor;
	//Puntero<Lista<Puntero<Ciudad>>> listaDeCiudades;
};
#endif

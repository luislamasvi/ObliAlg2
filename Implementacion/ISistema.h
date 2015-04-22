#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "Cadena.h"
#include "Iterador.h"
#include "Puntero.h"
#include "TipoRetorno.h"
#include "Tupla.h"
#include "ICiudad.h"
#include "IExcursion.h"
#include "ICliente.h"
#include "IRecorrido.h"
#include "TipoTransporte.h"

class ISistema abstract
{
public:
	virtual ~ISistema(){}

	// Tipo 1
	virtual TipoRetorno IngresoCiudad(Cadena nombreCiudad, nat costoPorDia) abstract;
	virtual TipoRetorno IngExcItinerario(nat nroExcursion, nat fechaDePartida, Iterador<Tupla<Cadena, nat>> itinerario) abstract;
	virtual TipoRetorno IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente) abstract;
	virtual TipoRetorno CompraExcursion(nat ciCliente, nat nroExcursion) abstract;
	virtual Tupla<TipoRetorno, Iterador<pCiudad>> ListadoCiudades() abstract;
	virtual Tupla<TipoRetorno, Iterador<pCliente>> ListadoClientes() abstract;
	virtual Tupla<TipoRetorno, Iterador<pExcursion>> ListadoExcursiones() abstract;

	// Tipo 2
	virtual Tupla<TipoRetorno, pExcursion> ConsultaExcursion(nat nroExcursion) abstract;
	virtual Tupla<TipoRetorno, pCliente> ConsultaCliente(nat ciCliente) abstract;
	virtual Tupla<TipoRetorno, pCiudad> ConsultaCiudad(Cadena nombreCiudad) abstract;
	virtual Tupla<TipoRetorno, pCliente> MejorCliente() abstract;
	virtual TipoRetorno IngresoConexion(Cadena nombreCiudadOrigen, Cadena nombreCiudadDestino, nat distancia, TipoTransporte tipoTransporte) abstract;
	virtual Tupla<TipoRetorno, bool> ValidarExcursion(nat nroExcursion) abstract;
	virtual Tupla<TipoRetorno, pRecorrido> ExcursionMenorCosto(nat nroExcursion) abstract;
	virtual Tupla<TipoRetorno, pRecorrido> ExcursionMenorTiempo(nat nroExcursion) abstract;

	// Operaciones opcionales
	virtual TipoRetorno BajaCliente(nat ciCliente) abstract;
	virtual Tupla<TipoRetorno, bool> ViajarEntreCiudades() abstract;
};

#endif

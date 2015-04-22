#pragma once

#include "ICiudad.h"
#include "IExcursion.h"
#include "ICliente.h"
#include "IRecorrido.h"

class CiudadMock : public ICiudad
{
public:
	CiudadMock(Cadena nombreCiudad, nat costoPorDia, Iterador<nat> excursionesQueLaVisitan);

	Cadena ObtenerNombreCiudad() const override;
	nat ObtenerCostoPorDia() const override;
	Iterador<nat> ObtenerExcursionesQueLaVisitan() const override;

	bool operator==(const ICiudad& c) const override;

private:
	Cadena m_NombreCiudad;
	nat m_CostoPorDia;
	Iterador<nat> m_ExcursionesQueLaVisitan;
};

class ExcursionMock : public IExcursion
{
public:
	ExcursionMock(nat nroExcursion, nat fechaDePartida, nat duracion, nat valor, Iterador<Tupla<Cadena, nat>> itinerario);

	nat ObtenerNroExcursion() const override;
	nat ObtenerFechaDePartida() const override;
	nat ObtenerDuracion() const override;
	nat ObtenerValor() const override;
	Iterador<Tupla<Cadena, nat>> ObtenerItinerario() const override;

	bool operator==(const IExcursion& e) const override;

private:
	nat m_NroExcursion;
	nat m_FechaDePartida;
	nat m_Duracion;
	nat m_Valor;
	Iterador<Tupla<Cadena, nat>> m_Itinerario;
};

class ClienteMock : public ICliente
{
public:
	ClienteMock(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Iterador<nat> excursionesRealizadas);

	nat ObtenerCiCliente() const override;
	Cadena ObtenerNombreCliente() const override;
	nat ObtenerFechaRegCliente() const override;
	Iterador<nat> ObtenerExcursionesRealizadas() const override;

	bool operator==(const ICliente& c) const override;

private:
	nat m_CiCliente;
	Cadena m_NombreCliente;
	nat m_FechaRegCliente;
	Iterador<nat> m_ExcursionesRealizadas;
};

class RecorridoMock : public IRecorrido
{
public:
	RecorridoMock(Cadena nombreCiudadOrigen, Iterador<Tupla<TipoTransporte, Cadena>> traslados, nat costoTotalTraslados, float tiempoTotalTraslados);

	Cadena ObtenerNombreCiudadOrigen() const override;
	Iterador<Tupla<TipoTransporte, Cadena>> ObtenerTraslados() const override;
	nat ObtenerCostoTotalTraslados() const override;
	float ObtenerTiempoTotalTraslados() const override;

	bool operator==(const IRecorrido& r) const override;

private:
	Cadena m_NombreCiudadOrigen;
	Iterador<Tupla<TipoTransporte, Cadena>> m_Traslados;
	nat m_CostoTotalTraslados;
	float m_TiempoTotalTraslados;
};

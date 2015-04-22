#include "PruebasMock.h"

CiudadMock::CiudadMock(Cadena nombreCiudad, nat costoPorDia, Iterador<nat> excursionesQueLaVisitan)
{
	m_NombreCiudad = nombreCiudad;
	m_CostoPorDia = costoPorDia;
	m_ExcursionesQueLaVisitan = excursionesQueLaVisitan;
}

Cadena CiudadMock::ObtenerNombreCiudad() const
{
	return m_NombreCiudad;
}

nat CiudadMock::ObtenerCostoPorDia() const
{
	return m_CostoPorDia;
}

Iterador<nat> CiudadMock::ObtenerExcursionesQueLaVisitan() const
{
	return m_ExcursionesQueLaVisitan;
}

bool CiudadMock::operator==(const ICiudad& c) const
{
	return this == &c;
}

ExcursionMock::ExcursionMock(nat nroExcursion, nat fechaDePartida, nat duracion, nat valor, Iterador<Tupla<Cadena, nat>> itinerario)
{
	m_NroExcursion = nroExcursion;
	assert(fechaDePartida >= 20000101);
	m_FechaDePartida = fechaDePartida;
	m_Duracion = duracion;
	m_Valor = valor;
	m_Itinerario = itinerario;
}

nat ExcursionMock::ObtenerNroExcursion() const
{
	return m_NroExcursion;
}

nat ExcursionMock::ObtenerFechaDePartida() const
{
	return m_FechaDePartida;
}

nat ExcursionMock::ObtenerDuracion() const
{
	return m_Duracion;
}

nat ExcursionMock::ObtenerValor() const
{
	return m_Valor;
}

Iterador<Tupla<Cadena, nat>> ExcursionMock::ObtenerItinerario() const
{
	return m_Itinerario;
}

bool ExcursionMock::operator==(const IExcursion& e) const
{
	return this == &e;
}

ClienteMock::ClienteMock(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Iterador<nat> excursionesRealizadas)
{
	m_CiCliente = ciCliente;
	m_NombreCliente = nombreCliente;
	assert(fechaRegCliente >= 20000101);
	m_FechaRegCliente = fechaRegCliente;
	m_ExcursionesRealizadas = excursionesRealizadas;
}

nat ClienteMock::ObtenerCiCliente() const
{
	return m_CiCliente;
}

Cadena ClienteMock::ObtenerNombreCliente() const
{
	return m_NombreCliente;
}

nat ClienteMock::ObtenerFechaRegCliente() const
{
	return m_FechaRegCliente;
}

Iterador<nat> ClienteMock::ObtenerExcursionesRealizadas() const
{
	return m_ExcursionesRealizadas;
}

bool ClienteMock::operator==(const ICliente& c) const
{
	return this == &c;
}

RecorridoMock::RecorridoMock(Cadena nombreCiudadOrigen, Iterador<Tupla<TipoTransporte, Cadena>> traslados, nat costoTotalTraslados, float tiempoTotalTraslados)
{
	m_NombreCiudadOrigen = nombreCiudadOrigen;
	m_Traslados = traslados;
	m_CostoTotalTraslados = costoTotalTraslados;
	m_TiempoTotalTraslados = tiempoTotalTraslados;
}

Cadena RecorridoMock::ObtenerNombreCiudadOrigen() const
{
	return m_NombreCiudadOrigen;
}

Iterador<Tupla<TipoTransporte, Cadena>> RecorridoMock::ObtenerTraslados() const
{
	return m_Traslados;
}

nat RecorridoMock::ObtenerCostoTotalTraslados() const
{
	return m_CostoTotalTraslados;
}

float RecorridoMock::ObtenerTiempoTotalTraslados() const
{
	return m_TiempoTotalTraslados;
}

bool RecorridoMock::operator==(const IRecorrido& r) const
{
	return this == &r;
}

#pragma once

#include "ISistema.h"
#include "Prueba.h"


class CasoDePrueba : public Prueba
{
public:
	CasoDePrueba(Puntero<ISistema> (*inicializar)(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES));

protected:
	void CorrerPruebaConcreta() override;
	Cadena GetNombre() const override;

private:
	Puntero<ISistema> (*inicializar)(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES);
	Puntero<ISistema> InicializarSistema(nat VELOCIDAD_OMNIBUS = 90, nat VELOCIDAD_AVION = 500, nat COSTO_OMNIBUS = 2, nat COSTO_AVION = 15, nat MAX_CIUDADES = 30, nat MAX_EXCURSIONES = 30, nat MAX_CLIENTES = 30);
	Array<pCiudad> InicializarCiudad(Puntero<ISistema> interfaz);
	Array<pExcursion> InicializarExcursion(Puntero<ISistema> interfaz);
	Array<pCliente> InicializarCliente(Puntero<ISistema> interfaz);
	void InicializarRecorrido(Puntero<ISistema> interfaz);

	bool ignorarOK;
	void Verificar(TipoRetorno obtenido, TipoRetorno esperado, Cadena comentario);
	template <class T>
	void Verificar(const T& obtenido, const T& esperado, Cadena comentario);
	template <class T>
	void VerificarConjuntos(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra);
	template <class T>
	void VerificarSecuencias(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra);
	template <class T>
	bool SonIguales(Iterador<T> obtenidos, Iterador<T> esperados) const;
	template <class T>
	Cadena ObtenerTexto(Iterador<T> it) const;
	template <class T>
	bool Pertenece(const T& dato, Iterador<T> iterador, T& encontrado) const;
	void VerificarListadoCiudades(Tupla<TipoRetorno, Iterador<pCiudad>> obtenido, Tupla<TipoRetorno, Iterador<pCiudad>> esperado, Cadena comentario);
	void VerificarListadoClientes(Tupla<TipoRetorno, Iterador<pCliente>> obtenido, Tupla<TipoRetorno, Iterador<pCliente>> esperado, Cadena comentario);
	void VerificarListadoExcursiones(Tupla<TipoRetorno, Iterador<pExcursion>> obtenido, Tupla<TipoRetorno, Iterador<pExcursion>> esperado, Cadena comentario);
	void VerificarConsultaExcursion(Tupla<TipoRetorno, pExcursion> obtenido, Tupla<TipoRetorno, pExcursion> esperado, Cadena comentario);
	void VerificarConsultaCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario);
	void VerificarConsultaCiudad(Tupla<TipoRetorno, pCiudad> obtenido, Tupla<TipoRetorno, pCiudad> esperado, Cadena comentario);
	void VerificarMejorCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario);
	void VerificarValidarExcursion(Tupla<TipoRetorno, bool> obtenido, Tupla<TipoRetorno, bool> esperado, Cadena comentario);
	void VerificarExcursionMenorCosto(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario);
	void VerificarExcursionMenorTiempo(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario);
	void VerificarViajarEntreCiudades(Tupla<TipoRetorno, bool> obtenido, Tupla<TipoRetorno, bool> esperado, Cadena comentario);
	bool SonIguales(const pCiudad& obtenido, const pCiudad& esperado) const;
	Cadena ObtenerTexto(const pCiudad& c) const;
	bool SonIguales(const pExcursion& obtenido, const pExcursion& esperado) const;
	Cadena ObtenerTexto(const pExcursion& e) const;
	bool SonIguales(const pCliente& obtenido, const pCliente& esperado) const;
	Cadena ObtenerTexto(const pCliente& c) const;
	bool SonIguales(const pRecorrido& obtenido, const pRecorrido& esperado) const;
	Cadena ObtenerTexto(const pRecorrido& r) const;
	bool SonIguales(const Tupla<Cadena, nat>& obtenido, const Tupla<Cadena, nat>& esperado) const;
	Cadena ObtenerTexto(const Tupla<Cadena, nat>& t) const;
	bool SonIguales(const Tupla<TipoTransporte, Cadena>& obtenido, const Tupla<TipoTransporte, Cadena>& esperado) const;
	Cadena ObtenerTexto(const Tupla<TipoTransporte, Cadena>& t) const;
	Cadena ObtenerTexto(const TipoTransporte& t) const;
	Cadena CadenaCiudadesItinerario(pExcursion exc);

	void PruebaOKIngresoCiudad();
	void PruebaOKIngExcItinerario();
	void PruebaOKIngresoCliente();
	void PruebaOKCompraExcursion();
	void PruebaOKListadoCiudades();
	void PruebaOKListadoClientes();
	void PruebaOKListadoExcursiones();
	void PruebaOKConsultaExcursion();
	void PruebaOKConsultaCliente();
	void PruebaOKConsultaCiudad();
	void PruebaOKMejorCliente();
	void PruebaOKIngresoConexion();
	void PruebaOKValidarExcursion();
	void PruebaOKExcursionMenorCosto();
	void PruebaOKExcursionMenorTiempo();
	void PruebaOKBajaCliente();
	void PruebaOKViajarEntreCiudades();

	void PruebaERRORIngresoCiudad();
	void PruebaERRORIngExcItinerario();
	void PruebaERRORIngresoCliente();
	void PruebaERRORCompraExcursion();
	void PruebaERRORListadoCiudades();
	void PruebaERRORListadoClientes();
	void PruebaERRORListadoExcursiones();
	void PruebaERRORConsultaExcursion();
	void PruebaERRORConsultaCliente();
	void PruebaERRORConsultaCiudad();
	void PruebaERRORMejorCliente();
	void PruebaERRORIngresoConexion();
	void PruebaERRORValidarExcursion();
	void PruebaERRORExcursionMenorCosto();
	void PruebaERRORExcursionMenorTiempo();
	void PruebaERRORBajaCliente();
	void PruebaERRORViajarEntreCiudades();
};
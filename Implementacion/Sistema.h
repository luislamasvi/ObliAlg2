#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "Ciudad.h"
#include "Excursion.h"
#include "Cliente.h"
#include "AVLImp.h"
#include "Comparador.h"
//#include "Lista.h"
//#include "ListaImp.h"

class Sistema : public ISistema
{
public:
	Sistema(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES);
	
	// Operaciones de Tipo 1
	TipoRetorno IngresoCiudad(Cadena nombreCiudad, nat costoPorDia) override;
	TipoRetorno IngExcItinerario(nat nroExcursion, nat fechaDePartida, Iterador<Tupla<Cadena, nat>> itinerario) override;
	TipoRetorno IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente) override;
	TipoRetorno CompraExcursion(nat ciCliente, nat nroExcursion) override;
	Tupla<TipoRetorno, Iterador<pCiudad>> ListadoCiudades() override;
	Tupla<TipoRetorno, Iterador<pCliente>> ListadoClientes() override;
	Tupla<TipoRetorno, Iterador<pExcursion>> ListadoExcursiones() override;

	// Operaciones de Tipo 2
	Tupla<TipoRetorno, pExcursion> ConsultaExcursion(nat nroExcursion) override;
	Tupla<TipoRetorno, pCliente> ConsultaCliente(nat ciCliente) override;
	Tupla<TipoRetorno, pCiudad> ConsultaCiudad(Cadena nombreCiudad) override;
	Tupla<TipoRetorno, pCliente> MejorCliente() override;
	TipoRetorno IngresoConexion(Cadena nombreCiudadOrigen, Cadena nombreCiudadDestino, nat distancia, TipoTransporte tipoTransporte) override;
	Tupla<TipoRetorno, bool> ValidarExcursion(nat nroExcursion) override;
	Tupla<TipoRetorno, pRecorrido> ExcursionMenorCosto(nat nroExcursion) override;
	Tupla<TipoRetorno, pRecorrido> ExcursionMenorTiempo(nat nroExcursion) override;

	// Operaciones opcionales
	TipoRetorno BajaCliente(nat ciCliente) override;
	Tupla<TipoRetorno, bool> ViajarEntreCiudades() override;

private:
	Puntero<AVL<Puntero<Ciudad>>> ciudad;
	Puntero<AVL<Puntero<Excursion>>> excursion;
	Puntero<AVL<Puntero<Cliente>>> cliente;

	nat VelocidadOmnibus;
	nat VelocidadAvion;
	nat CostoOmnibus;
	nat CostAvion;
	nat MaxCiudades;
	nat MaxExcursiones;
	nat MaxClientes;
};

#endif

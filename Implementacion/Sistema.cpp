#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Sistema.h"
#include "ComparacionCiudad.h"


Sistema::Sistema(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES)
{

	Puntero<Comparacion<Puntero<Ciudad>>> compCiudad= new ComparacionCiudad();
	Comparador<Tupla<nat,nat>> cObj(compCiudad);


	ciudad = new AVLImp<Puntero<Ciudad>>(compCiudad);
	excursion = new AVLImp<Puntero<Excursion>>();
	cliente = new AVLImp<Puntero<Cliente>>();

	 VelocidadOmnibus=VELOCIDAD_OMNIBUS;
	 VelocidadAvion=VELOCIDAD_AVION;
	 CostoOmnibus=COSTO_OMNIBUS;
	 CostAvion=COSTO_AVION;
	 MaxCiudades=MAX_CIUDADES;
	 MaxExcursiones=MAX_EXCURSIONES;
	 MaxClientes=MAX_CLIENTES;
}

// Operaciones de Tipo 1

TipoRetorno Sistema::IngresoCiudad(Cadena nombreCiudad, nat costoPorDia)
{
	if(ciudad->CantNodos() > MaxCiudades){
		cout<<"Se sobrepasa la cantidad máxima de ciudades";
		return ERROR;
	}
	if(ciudad->Existe(new Ciudad(nombreCiudad,costoPorDia))){
		cout<<"Ya existe una ciudad de nombre " << nombreCiudad;
		return ERROR;
	}
	ciudad->Insertar(new Ciudad(nombreCiudad,costoPorDia));
	return OK;
}

TipoRetorno Sistema::IngExcItinerario(nat nroExcursion, nat fechaDePartida, Iterador<Tupla<Cadena, nat>> itinerario)
{
	if(excursion->CantNodos() > MaxExcursiones){
		cout<<"Se sobrepasa la cantidad máxima de excursiones";
		return ERROR;
	}
	if(excursion->Existe(new Excursion(nroExcursion, fechaDePartida))){
		cout<<"Ya existe una Excursion con ese "<<nroExcursion;
		return ERROR;
	}
	if(!itinerario.HayElemento()){
		cout<<"El Itinerario está vacío";
		return ERROR;
	}

	nat valor = 0;
	nat duracion = 0;
	//Puntero<Lista<Puntero<Ciudad>>> listaDeCiudades = new ListaImp<Puntero<Ciudad>>();

	Iterador<Tupla<Cadena, nat>> it = itinerario;
	while(it.HayElemento()){
		Tupla<Cadena, nat> tupla = it.ElementoActual();
		Cadena nombreCiudad = tupla.Dato1;
		if(!this->ciudad->Existe(new Ciudad(nombreCiudad,0))){
			cout<<"No existe alguna de las ciudades de la lista Itinerario.";
			return ERROR;
		}

		valor = valor + (tupla.Dato2 * this->ciudad->Recuperar(new Ciudad(nombreCiudad,0))->ObtenerCostoPorDia());
		duracion = duracion + tupla.Dato2;
		it.Avanzar();
	}
	//it.Reiniciar();
	// faltan las ciudades
	this->excursion->Insertar(new Excursion(nroExcursion, fechaDePartida, duracion, valor));
	

	return OK;
}

TipoRetorno Sistema::IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno Sistema::CompraExcursion(nat ciCliente, nat nroExcursion)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, Iterador<pCiudad>> Sistema::ListadoCiudades()
{
	return Tupla<TipoRetorno, Iterador<pCiudad>>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, Iterador<pCliente>> Sistema::ListadoClientes()
{
	return Tupla<TipoRetorno, Iterador<pCliente>>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, Iterador<pExcursion>> Sistema::ListadoExcursiones()
{
	return Tupla<TipoRetorno, Iterador<pExcursion>>(NO_IMPLEMENTADA, nullptr);
}

// Operaciones de Tipo 2

Tupla<TipoRetorno, pExcursion> Sistema::ConsultaExcursion(nat nroExcursion)
{
	return Tupla<TipoRetorno, pExcursion>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pCliente> Sistema::ConsultaCliente(nat ciCliente)
{
	return Tupla<TipoRetorno, pCliente>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pCiudad> Sistema::ConsultaCiudad(Cadena nombreCiudad)
{
	return Tupla<TipoRetorno, pCiudad>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pCliente> Sistema::MejorCliente()
{
	return Tupla<TipoRetorno, pCliente>(NO_IMPLEMENTADA, nullptr);
}

TipoRetorno Sistema::IngresoConexion(Cadena nombreCiudadOrigen, Cadena nombreCiudadDestino, nat distancia, TipoTransporte tipoTransporte)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, bool> Sistema::ValidarExcursion(nat nroExcursion)
{
	return Tupla<TipoRetorno, bool>(NO_IMPLEMENTADA, false);
}

Tupla<TipoRetorno, pRecorrido> Sistema::ExcursionMenorCosto(nat nroExcursion)
{
	return Tupla<TipoRetorno, pRecorrido>(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pRecorrido> Sistema::ExcursionMenorTiempo(nat nroExcursion)
{
	return Tupla<TipoRetorno, pRecorrido>(NO_IMPLEMENTADA, nullptr);
}

// Operaciones opcionales

TipoRetorno Sistema::BajaCliente(nat ciCliente)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, bool> Sistema::ViajarEntreCiudades()
{
	return Tupla<TipoRetorno, bool>(NO_IMPLEMENTADA, false);
}

#endif
#include "CasoDePrueba.h"
#include "PruebasMock.h"

CasoDePrueba::CasoDePrueba(Puntero<ISistema> (*inicializar)(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES))
{
	this->inicializar = inicializar;
}

Puntero<ISistema> CasoDePrueba::InicializarSistema(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES)
{
	Puntero<ISistema> interfaz = inicializar(VELOCIDAD_OMNIBUS, VELOCIDAD_AVION, COSTO_OMNIBUS, COSTO_AVION, MAX_CIUDADES, MAX_EXCURSIONES, MAX_CLIENTES);
	ignorarOK = false;
	return interfaz;
}

Array<pCiudad> CasoDePrueba::InicializarCiudad(Puntero<ISistema> interfaz)
{
	Array<pCiudad> ciudades = Array<pCiudad>(20);
	//Ordenadas alfabeticamente
	ciudades[0] = new CiudadMock("Artigas", 26, Iterador<nat>());
	ciudades[1] = new CiudadMock("Asunción", 20, Iterador<nat>());
	ciudades[2] = new CiudadMock("Auckland", 18, Iterador<nat>());
	ciudades[3] = new CiudadMock("Beijing", 26, Iterador<nat>());
	ciudades[4] = new CiudadMock("Buenos Aires", 21, Iterador<nat>());
	ciudades[5] = new CiudadMock("Colonia", 19, Iterador<nat>());
	ciudades[6] = new CiudadMock("Cuzco", 15, Iterador<nat>());
	ciudades[7] = new CiudadMock("Fray Bentos", 30, Iterador<nat>());
	ciudades[8] = new CiudadMock("Jerusalén", 21, Iterador<nat>());
	ciudades[9] = new CiudadMock("La Paz", 23, Iterador<nat>());
	ciudades[10] = new CiudadMock("Las Piedras", 20, Iterador<nat>());
	ciudades[11] = new CiudadMock("Mercedes", 23, Iterador<nat>());
	ciudades[12] = new CiudadMock("Montevideo", 24, Iterador<nat>());
	ciudades[13] = new CiudadMock("New York", 29, Iterador<nat>());
	ciudades[14] = new CiudadMock("Oslo", 35, Iterador<nat>());
	ciudades[15] = new CiudadMock("Paysandú", 10, Iterador<nat>());
	ciudades[16] = new CiudadMock("Punta Del Este", 17, Iterador<nat>());
	ciudades[17] = new CiudadMock("Río de Janeiro", 25, Iterador<nat>());
	ciudades[18] = new CiudadMock("Salto", 14, Iterador<nat>());
	ciudades[19] = new CiudadMock("Santiago de Chile", 29, Iterador<nat>());
		
	for (nat i = 0; i < ciudades.Largo; i++)
	{
		//Ya fueron verificadas
		interfaz->IngresoCiudad(ciudades[i]->ObtenerNombreCiudad(), ciudades[i]->ObtenerCostoPorDia());
	}
	
	return ciudades;
}
	
Array<pExcursion> CasoDePrueba::InicializarExcursion(Puntero<ISistema> interfaz)
{
	Array<Tupla<Cadena, nat>> itin1 = Array<Tupla<Cadena, nat>>(2);
	Array<Tupla<Cadena, nat>> itin2 = Array<Tupla<Cadena, nat>>(3);
	Array<Tupla<Cadena, nat>> itin3 = Array<Tupla<Cadena, nat>>(1);
	Array<Tupla<Cadena, nat>> itin4 = Array<Tupla<Cadena, nat>>(1);
	Array<Tupla<Cadena, nat>> itin5 = Array<Tupla<Cadena, nat>>(3);
	Array<Tupla<Cadena, nat>> itin6 = Array<Tupla<Cadena, nat>>(4);
	Array<Tupla<Cadena, nat>> itin7 = Array<Tupla<Cadena, nat>>(1);
	Array<Tupla<Cadena, nat>> itin8 = Array<Tupla<Cadena, nat>>(2);

	itin1[0] = Tupla<Cadena, nat>("Punta Del Este", 3);
	itin1[1] = Tupla<Cadena, nat>("Paysandú", 5);
	
	itin2[0] = Tupla<Cadena, nat>("Río de Janeiro", 1);
	itin2[1] = Tupla<Cadena, nat>("Salto", 2);
	itin2[2] = Tupla<Cadena, nat>("Montevideo", 2);
	
	itin3[0] = Tupla<Cadena, nat>("Oslo", 1);
	
	itin4[0] = Tupla<Cadena, nat>("New York", 1);
	
	itin5[0] = Tupla<Cadena, nat>("Beijing", 1);
	itin5[1] = Tupla<Cadena, nat>("Jerusalén", 1);
	itin5[2] = Tupla<Cadena, nat>("Cuzco", 2);
	
	itin6[0] = Tupla<Cadena, nat>("Montevideo", 1);
	itin6[1] = Tupla<Cadena, nat>("Salto", 1);
	itin6[2] = Tupla<Cadena, nat>("Punta Del Este", 2);
	itin6[3] = Tupla<Cadena, nat>("Buenos Aires", 2);
	
	itin7[0] = Tupla<Cadena, nat>("Auckland", 1);
	
	itin8[0] = Tupla<Cadena, nat>("Mercedes", 1);
	itin8[1] = Tupla<Cadena, nat>("Las Piedras", 2);

	Array<pExcursion> excursiones = Array<pExcursion>(8);
	excursiones[0] = new ExcursionMock(1, 20150331, 8, 101, itin1.ObtenerIterador());
	excursiones[1] = new ExcursionMock(2, 20150401, 5, 101, itin2.ObtenerIterador());
	excursiones[2] = new ExcursionMock(3, 20150402, 1, 35, itin3.ObtenerIterador());
	excursiones[3] = new ExcursionMock(4, 20150403, 1, 29, itin4.ObtenerIterador());
	excursiones[4] = new ExcursionMock(5, 20150404, 4, 77, itin5.ObtenerIterador());
	excursiones[5] = new ExcursionMock(6, 20150405, 6, 114, itin6.ObtenerIterador());
	excursiones[6] = new ExcursionMock(7, 20150406, 1, 18, itin7.ObtenerIterador());
	excursiones[7] = new ExcursionMock(8, 20150407, 3, 63, itin8.ObtenerIterador());

	
	for (nat i = 0; i < excursiones.Largo; i++)
	{
		//Ya fueron verificadas
		interfaz->IngExcItinerario(i + 1, excursiones[i]->ObtenerFechaDePartida(), excursiones[i]->ObtenerItinerario());
	}

	return excursiones;
}

Array<pCliente> CasoDePrueba::InicializarCliente(Puntero<ISistema> interfaz)
{
	Array<pCliente> clientes = Array<pCliente>(12);
	clientes[0] = new ClienteMock(12345678, "Ana", 20150519, Iterador<nat>());
	clientes[1] = new ClienteMock(87654321, "Andrea", 20150520, Iterador<nat>());
	clientes[2] = new ClienteMock(11111111, "Jaime", 20150521, Iterador<nat>());
	clientes[3] = new ClienteMock(22222222, "Jose", 20150523,Iterador<nat>());
	clientes[4] = new ClienteMock(44444444, "Juan", 20150515, Iterador<nat>());
	clientes[5] = new ClienteMock(55555555, "Lucía", 20150516,Iterador<nat>());
	clientes[6] = new ClienteMock(66666666, "María", 20150510, Iterador<nat>());
	clientes[7] = new ClienteMock(77777777, "Martín", 20150509, Iterador<nat>());
	clientes[8] = new ClienteMock(88888888, "Natalia", 20150528, Iterador<nat>());
	clientes[9] = new ClienteMock(33333333, "Romina", 20150509,Iterador<nat>());
	clientes[10] = new ClienteMock(99999999, "Rosa", 20150610,Iterador<nat>());
	clientes[11] = new ClienteMock(10101010, "Valeria", 20150728,Iterador<nat>());

	for (nat i = 0; i < clientes.Largo; i++)
	{
		//Ya se verificaron
		interfaz->IngresoCliente(clientes[i]->ObtenerCiCliente(), clientes[i]->ObtenerNombreCliente(), clientes[i]->ObtenerFechaRegCliente());
	}

	return clientes;
}

void CasoDePrueba::InicializarRecorrido(Puntero<ISistema> interfaz)
{
}

Cadena CasoDePrueba::GetNombre()const
{
	return "Casos de Prueba";
}

void CasoDePrueba::CorrerPruebaConcreta()
{
	PruebaOKIngresoCiudad();
	PruebaOKIngExcItinerario();
	PruebaOKIngresoCliente();
	PruebaOKCompraExcursion();
	PruebaOKListadoCiudades();
	PruebaOKListadoClientes();
	PruebaOKListadoExcursiones();
	PruebaOKConsultaExcursion();
	PruebaOKConsultaCliente();
	PruebaOKConsultaCiudad();
	PruebaOKMejorCliente();
	PruebaOKIngresoConexion();
	PruebaOKValidarExcursion();
	PruebaOKExcursionMenorCosto();
	PruebaOKExcursionMenorTiempo();
	PruebaOKBajaCliente();
	PruebaOKViajarEntreCiudades();
	
	PruebaERRORIngresoCiudad();
	PruebaERRORIngExcItinerario();
	PruebaERRORIngresoCliente();
	PruebaERRORCompraExcursion();
	PruebaERRORListadoCiudades();
	PruebaERRORListadoClientes();
	PruebaERRORListadoExcursiones();
	PruebaERRORConsultaExcursion();
	PruebaERRORConsultaCliente();
	PruebaERRORConsultaCiudad();
	PruebaERRORMejorCliente();
	PruebaERRORIngresoConexion();
	PruebaERRORValidarExcursion();
	PruebaERRORExcursionMenorCosto();
	PruebaERRORExcursionMenorTiempo();
	PruebaERRORBajaCliente();
	PruebaERRORViajarEntreCiudades();
}

void CasoDePrueba::Verificar(TipoRetorno obtenido, TipoRetorno esperado, Cadena comentario)
{
	if (!ignorarOK || obtenido != esperado)
		Prueba::Verificar(obtenido, esperado, comentario);
}

template <class T>
void CasoDePrueba::Verificar(const T& obtenido, const T& esperado, Cadena comentario)
{
	Verificar(SonIguales(obtenido, esperado) ? OK : ERROR, OK, comentario.DarFormato(ObtenerTexto(obtenido), ObtenerTexto(esperado)));
}

template <class T>
void CasoDePrueba::VerificarConjuntos(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra)
{
	bool verificarCantidad = true;
	nat totalObtenidos = 0;
	T aux;
	foreach (T obtenido, obtenidos)
	{
		totalObtenidos++;
		if (Pertenece(obtenido, esperados, aux))
			Verificar(OK, OK, comentarioEncontrado);
		else
		{
			Verificar(ERROR, OK, comentarioSobra.DarFormato(ObtenerTexto(obtenido)));
			verificarCantidad = false;
		}
	}
	nat totalEsperados = 0;
	foreach (T esperado, esperados)
	{
		totalEsperados++;
		if (!Pertenece(esperado, obtenidos, aux))
		{
			Verificar(ERROR, OK, comentarioFalta.DarFormato(ObtenerTexto(esperado)));
			verificarCantidad = false;
		}
	}
	if (verificarCantidad && totalObtenidos != totalEsperados)
		Verificar(ERROR, OK, "Se verifica la cantidad de elementos de los conjuntos");
}

template <class T>
void CasoDePrueba::VerificarSecuencias(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra)
{
	esperados.Reiniciar();

	foreach (T obtenido, obtenidos)
	{
		if (esperados.HayElemento())
		{
			T esperado = *esperados;
			++esperados;
			Verificar(obtenido, esperado, comentarioEncontrado);
		}
		else
			Verificar(ERROR, OK, comentarioSobra.DarFormato(ObtenerTexto(obtenido)));
	}

	while (esperados.HayElemento())
	{
		T esperado = *esperados;
		++esperados;
		Verificar(ERROR, OK, comentarioFalta.DarFormato(ObtenerTexto(esperado)));
	}
}

template <class T>
bool CasoDePrueba::SonIguales(Iterador<T> obtenidos, Iterador<T> esperados) const
{
	obtenidos.Reiniciar();
	esperados.Reiniciar();
	while (obtenidos.HayElemento() && esperados.HayElemento())
	{
		if (!SonIguales(*obtenidos, *esperados))
			return false;
		++obtenidos;
		++esperados;
	}

	return esperados.HayElemento() == obtenidos.HayElemento();
}

template <class T>
Cadena CasoDePrueba::ObtenerTexto(Iterador<T> it) const
{
	Cadena sepVacio = "";
	Cadena sepGuion = "-";
	Cadena sep = sepVacio;
	Cadena retorno = sepVacio;
	foreach (auto t, it)
	{
		retorno += sep + ObtenerTexto(t);
		sep = sepGuion;
	}
	return retorno;
}

template <class T>
bool CasoDePrueba::Pertenece(const T& dato, Iterador<T> iterador, T& encontrado) const
{
	foreach (T dato2, iterador)
	{
		if (SonIguales(dato, dato2))
		{
			encontrado = dato2;
			return true;
		}
	}
	return false;
}

void CasoDePrueba::VerificarListadoCiudades(Tupla<TipoRetorno, Iterador<pCiudad>> obtenido, Tupla<TipoRetorno, Iterador<pCiudad>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		VerificarSecuencias(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarListadoClientes(Tupla<TipoRetorno, Iterador<pCliente>> obtenido, Tupla<TipoRetorno, Iterador<pCliente>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		VerificarSecuencias(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarListadoExcursiones(Tupla<TipoRetorno, Iterador<pExcursion>> obtenido, Tupla<TipoRetorno, Iterador<pExcursion>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		VerificarSecuencias(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarConsultaExcursion(Tupla<TipoRetorno, pExcursion> obtenido, Tupla<TipoRetorno, pExcursion> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarConsultaCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarConsultaCiudad(Tupla<TipoRetorno, pCiudad> obtenido, Tupla<TipoRetorno, pCiudad> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarMejorCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarValidarExcursion(Tupla<TipoRetorno, bool> obtenido, Tupla<TipoRetorno, bool> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2 == esperado.Dato2 ? OK : ERROR, OK, "Se verifica el dato 2");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarExcursionMenorCosto(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarExcursionMenorTiempo(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarViajarEntreCiudades(Tupla<TipoRetorno, bool> obtenido, Tupla<TipoRetorno, bool> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2 == esperado.Dato2 ? OK : ERROR, OK, "Se verifica el dato 2");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

bool CasoDePrueba::SonIguales(const pCiudad& obtenido, const pCiudad& esperado) const
{
	return obtenido->ObtenerNombreCiudad() == esperado->ObtenerNombreCiudad() && obtenido->ObtenerCostoPorDia() == esperado->ObtenerCostoPorDia();
}

Cadena CasoDePrueba::ObtenerTexto(const pCiudad& c) const
{
	return c->ObtenerNombreCiudad();
}

bool CasoDePrueba::SonIguales(const pExcursion& obtenido, const pExcursion& esperado) const
{
	return obtenido->ObtenerNroExcursion() == esperado->ObtenerNroExcursion() && obtenido->ObtenerFechaDePartida() == esperado->ObtenerFechaDePartida() && obtenido->ObtenerDuracion() == esperado->ObtenerDuracion() && obtenido->ObtenerValor() == esperado->ObtenerValor();
}

Cadena CasoDePrueba::ObtenerTexto(const pExcursion& e) const
{
	Cadena numExc = "Num. excursión: {0}";
	char strNum [6];
	_itoa_s(e->ObtenerNroExcursion(), strNum, 10);
	return numExc.DarFormato(strNum);
}

bool CasoDePrueba::SonIguales(const pCliente& obtenido, const pCliente& esperado) const
{
	return obtenido->ObtenerCiCliente() == esperado->ObtenerCiCliente() && obtenido->ObtenerNombreCliente() == esperado->ObtenerNombreCliente() && obtenido->ObtenerFechaRegCliente() == esperado->ObtenerFechaRegCliente();
}

Cadena CasoDePrueba::ObtenerTexto(const pCliente& c) const
{
	return c->ObtenerNombreCliente();
}

bool CasoDePrueba::SonIguales(const pRecorrido& obtenido, const pRecorrido& esperado) const
{
	return obtenido->ObtenerNombreCiudadOrigen() == esperado->ObtenerNombreCiudadOrigen() && obtenido->ObtenerCostoTotalTraslados() == esperado->ObtenerCostoTotalTraslados() && obtenido->ObtenerTiempoTotalTraslados() == esperado->ObtenerTiempoTotalTraslados();
}

Cadena CasoDePrueba::ObtenerTexto(const pRecorrido& r) const
{
	return r->ObtenerNombreCiudadOrigen();
}

bool CasoDePrueba::SonIguales(const Tupla<Cadena, nat>& obtenido, const Tupla<Cadena, nat>& esperado) const
{
	return obtenido.Dato1 == esperado.Dato1 && obtenido.Dato2 == esperado.Dato2;
}

Cadena CasoDePrueba::ObtenerTexto(const Tupla<Cadena, nat>& t) const
{
	return t.Dato1;
}

bool CasoDePrueba::SonIguales(const Tupla<TipoTransporte, Cadena>& obtenido, const Tupla<TipoTransporte, Cadena>& esperado) const
{
	return obtenido.Dato1 == esperado.Dato1 && obtenido.Dato2 == esperado.Dato2;
}

Cadena CasoDePrueba::ObtenerTexto(const Tupla<TipoTransporte, Cadena>& t) const
{
	return t.Dato2;
}

Cadena CasoDePrueba::ObtenerTexto(const TipoTransporte& t) const
{
	switch (t)
	{
	case OMNIBUS:
		return "OMNIBUS";
	case AVION:
		return "AVION";
	case AMBOS:
		return "AMBOS";
	default:
		assert(false);
		return "INDEFINIDO";
	}
}

void CasoDePrueba::PruebaOKIngresoCiudad()
{
	IniciarSeccion("Ingreso Ciudad");
	Puntero<ISistema> interfaz = InicializarSistema(30,30,30, 30, 10, 30, 30);

	Verificar(interfaz->IngresoCiudad("Mercedes",200), OK, "Se ingresa la ciudad Mercedes.");
	Verificar(interfaz->IngresoCiudad("Las Piedras", 250), OK, "Se ingresa la ciudad Las Piedras.");
	Verificar(interfaz->IngresoCiudad("Montevideo", 400), OK, "Se ingresa la ciudad Montevideo.");
	Verificar(interfaz->IngresoCiudad("Maldonado", 400), OK, "Se ingresa la ciudad Maldonado.");
	Verificar(interfaz->IngresoCiudad("Punta del Este", 800), OK, "Se ingresa la ciudad Punta del Este.");
	Verificar(interfaz->IngresoCiudad("Artigas", 150), OK, "Se ingresa la ciudad Artigas.");
	Verificar(interfaz->IngresoCiudad("Fray Bentos", 100), OK, "Se ingresa la ciudad Fray Bentos.");
	Verificar(interfaz->IngresoCiudad("Paysandú", 200), OK, "Se ingresa la ciudad Paysandú.");
	Verificar(interfaz->IngresoCiudad("Colonia", 350), OK, "Se ingresa la ciudad Colonia.");
	Verificar(interfaz->IngresoCiudad("Carmelo", 230), OK, "Se ingresa la ciudad Carmelo.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKIngExcItinerario()
{
	IniciarSeccion("Ing Exc Itinerario");

	Puntero<ISistema> interfaz = InicializarSistema();
	InicializarCiudad(interfaz);
	Array<Tupla<Cadena, nat>> it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Montevideo", 5);
	it[1] = Tupla<Cadena, nat>("Mercedes", 2);
	it[2] = Tupla<Cadena, nat>("Las Piedras", 3);
	Iterador<Tupla<Cadena, nat>> itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(1,20150331,itinerario), OK, "Se inserta la excursión Montevideo-Mercedes-Las Piedras");
	it = Array<Tupla<Cadena, nat>>(6);
	it[0] = Tupla<Cadena, nat>("Río de Janeiro", 5);
	it[1] = Tupla<Cadena, nat>("Montevideo", 2);
	it[2] = Tupla<Cadena, nat>("Santiago de Chile", 3);
	it[3] = Tupla<Cadena, nat>("Cuzco", 3);
	it[4] = Tupla<Cadena, nat>("Asunción", 8);
	it[5] = Tupla<Cadena, nat>("Río de Janeiro", 2);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(2, 20150421, itinerario), OK, "Se inserta la excursión Río de Janeiro-Montevideo-Santiago de Chile-Cuzco-Asunción-Río de Janeiro");

	
	it = Array<Tupla<Cadena, nat>>(1);
	it[0] = Tupla<Cadena, nat>("Montevideo", 0);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(3, 20150331, itinerario), OK, "Se inserta la excursión Montevideo");

	interfaz = InicializarSistema(90, 500, 20, 150, 50, 9, 50);
	InicializarCiudad(interfaz);
	InicializarExcursion(interfaz);
	it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Fray Bentos", 5);
	it[1] = Tupla<Cadena, nat>("Mercedes", 2);
	it[2] = Tupla<Cadena, nat>("Colonia", 3);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(9, 20150331, itinerario), OK, "Se inserta la excursión Fray Bentos-Mercedes-Colonia.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKIngresoCliente()
{
	IniciarSeccion("Ingreso Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();
	Verificar(interfaz->IngresoCliente(88888888, "Juan", 20150519), OK, "Se ingresa el cliente Juan");
	Verificar(interfaz->IngresoCliente(33333333, "Jose", 20150520), OK, "Se ingresa el cliente José");
	Verificar(interfaz->IngresoCliente(99999999, "Martín", 20150521), OK, "Se ingresa el cliente Martín");
	Verificar(interfaz->IngresoCliente(10101010, "Lucía", 20150523), OK, "Se ingresa el cliente Lucía");

	interfaz = InicializarSistema(90, 500, 200, 500, 50, 50, 13);
	InicializarCliente(interfaz);
	Verificar(interfaz->IngresoCliente(66669999, "Juan Andrés", 20150402), OK, "Se ingresa el cliente Juan Andrés");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKCompraExcursion()
{
	IniciarSeccion("Compra Excursion");
	Puntero<ISistema> interfaz = InicializarSistema();
	Array<pCliente> clientes = InicializarCliente(interfaz);
	InicializarCiudad(interfaz);
	Array<pExcursion> excursiones = InicializarExcursion(interfaz);	

	
	for (nat i = 0; i < excursiones.Largo; i++)
	{
		pCliente cli = clientes[i];
		pExcursion exc = excursiones[i];

		Cadena itinerario = CadenaCiudadesItinerario(exc);
		Cadena comentario = Cadena("El cliente {0} compró la excursión: {1}").DarFormato(cli->ObtenerNombreCliente(),itinerario);

		Verificar(interfaz->CompraExcursion(cli->ObtenerCiCliente(), exc->ObtenerNroExcursion()), OK, comentario);
	}
	
	//hago algunas pruebas más con un cliente que no se probó...

	pCliente cli = clientes[9];
	pExcursion exc = excursiones[4];
	Cadena itinerario = CadenaCiudadesItinerario(exc);

	Cadena comentario = Cadena("El cliente {0} compró la excursión: {1}").DarFormato(cli->ObtenerNombreCliente(), itinerario);
	Verificar(interfaz->CompraExcursion(cli->ObtenerCiCliente(), exc->ObtenerNroExcursion()), OK, comentario);

	exc = excursiones[6];
	itinerario = CadenaCiudadesItinerario(exc);
	comentario = Cadena("El cliente {0} compró la excursión: {1}").DarFormato(cli->ObtenerNombreCliente(), itinerario);
	Verificar(interfaz->CompraExcursion(cli->ObtenerCiCliente(), exc->ObtenerNroExcursion()), OK, comentario);

	exc = excursiones[2];
	itinerario = CadenaCiudadesItinerario(exc);
	comentario = Cadena("El cliente {0} compró la excursión: {1}").DarFormato(cli->ObtenerNombreCliente(), itinerario);
	Verificar(interfaz->CompraExcursion(cli->ObtenerCiCliente(), exc->ObtenerNroExcursion()), OK, comentario);
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKListadoCiudades()
{
	IniciarSeccion("Listado Ciudades");
	Puntero<ISistema> interfaz = InicializarSistema();
	Array<pCiudad> ciudades = InicializarCiudad(interfaz);

	Tupla<TipoRetorno, Iterador<pCiudad>> esperado;
	Tupla<TipoRetorno, Iterador<pCiudad>> obtenido;

	
	obtenido = interfaz->ListadoCiudades();
	esperado = Tupla <TipoRetorno, Iterador<pCiudad>>(OK, ciudades.ObtenerIterador());

	VerificarListadoCiudades(obtenido, esperado, "");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKListadoClientes()
{
	IniciarSeccion("Listado Clientes");
	Puntero<ISistema> interfaz = InicializarSistema();
	Array<pCliente> clientes = InicializarCliente(interfaz);

	Tupla<TipoRetorno, Iterador<pCliente>> esperado;
	Tupla<TipoRetorno, Iterador<pCliente>> obtenido;
	
	obtenido = interfaz->ListadoClientes();
	esperado = Tupla<TipoRetorno, Iterador<pCliente>>(OK, clientes.ObtenerIterador());

	VerificarListadoClientes(obtenido, esperado, "");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKListadoExcursiones()
{
	IniciarSeccion("Listado Excursiones");
	Puntero<ISistema> interfaz = InicializarSistema();
	InicializarCiudad(interfaz);
	Array<pExcursion> excursiones = InicializarExcursion(interfaz);


	Tupla<TipoRetorno, Iterador<pExcursion>> esperado;
	Tupla<TipoRetorno, Iterador<pExcursion>> obtenido;

	obtenido = interfaz->ListadoExcursiones();
	esperado = Tupla<TipoRetorno,Iterador<pExcursion>>(OK,excursiones.ObtenerIterador());

	VerificarListadoExcursiones(obtenido, esperado, "");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKConsultaExcursion()
{
	IniciarSeccion("Consulta Excursion");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pExcursion> esperado;
	Tupla<TipoRetorno, pExcursion> obtenido;



	/*
	obtenido = interfaz->ConsultaExcursion();
	esperado = ...

	VerificarConsultaExcursion(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKConsultaCliente()
{
	IniciarSeccion("Consulta Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;

	/*
	obtenido = interfaz->ConsultaCliente();
	esperado = ...

	VerificarConsultaCliente(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKConsultaCiudad()
{
	IniciarSeccion("Consulta Ciudad");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCiudad> esperado;
	Tupla<TipoRetorno, pCiudad> obtenido;

	/*
	obtenido = interfaz->ConsultaCiudad();
	esperado = ...

	VerificarConsultaCiudad(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKMejorCliente()
{
	IniciarSeccion("Mejor Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;

	/*
	obtenido = interfaz->MejorCliente();
	esperado = ...

	VerificarMejorCliente(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKIngresoConexion()
{
	IniciarSeccion("Ingreso Conexion");
	Puntero<ISistema> interfaz = InicializarSistema();

	//Verificar(interfaz->IngresoConexion(), OK, "Comentario");
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKValidarExcursion()
{
	IniciarSeccion("Validar Excursion");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, bool> esperado;
	Tupla<TipoRetorno, bool> obtenido;

	/*
	obtenido = interfaz->ValidarExcursion();
	esperado = ...

	VerificarValidarExcursion(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKExcursionMenorCosto()
{
	IniciarSeccion("Excursion Menor Costo");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	/*
	obtenido = interfaz->ExcursionMenorCosto();
	esperado = ...

	VerificarExcursionMenorCosto(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKExcursionMenorTiempo()
{
	IniciarSeccion("Excursion Menor Tiempo");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	/*
	obtenido = interfaz->ExcursionMenorTiempo();
	esperado = ...

	VerificarExcursionMenorTiempo(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKBajaCliente()
{
	IniciarSeccion("Baja Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();

	//Verificar(interfaz->BajaCliente(), OK, "Comentario");
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKViajarEntreCiudades()
{
	IniciarSeccion("Viajar Entre Ciudades");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, bool> esperado;
	Tupla<TipoRetorno, bool> obtenido;

	/*
	obtenido = interfaz->ViajarEntreCiudades();
	esperado = ...

	VerificarViajarEntreCiudades(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoCiudad()
{
	IniciarSeccion("Ingreso Ciudad", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema(30, 30, 30, 30, 10, 30, 30);

	interfaz->IngresoCiudad("Mercedes", 200);
	interfaz->IngresoCiudad("Las Piedras", 250);
	Verificar(interfaz->IngresoCiudad("Mercedes", 400), ERROR, "ERROR: Ya existe la ciudad de nombre Mercedes.");
	Verificar(interfaz->IngresoCiudad("Las Piedras", 400), ERROR, "ERROR: Ya existe la ciudad de nombre Las Piedras.");
	interfaz->IngresoCiudad("Punta del Este", 800);
	interfaz->IngresoCiudad("Artigas", 150);
	interfaz->IngresoCiudad("Fray Bentos", 100);
	interfaz->IngresoCiudad("Paysandú", 200);
	interfaz->IngresoCiudad("Colonia", 350);
	interfaz->IngresoCiudad("Carmelo", 230);
	interfaz->IngresoCiudad("Zaragoza", 230);
	interfaz->IngresoCiudad("Brasilia", 230);
	Verificar(interfaz->IngresoCiudad("New Jersey", 230), ERROR, "ERROR: Se sobrepasa la cantidad máxima de ciudades.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngExcItinerario()
{
	IniciarSeccion("Ing Exc Itinerario", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema(30, 30, 30, 30, 10, 5, 30);
	InicializarCiudad(interfaz);

	Array<Tupla<Cadena, nat>> it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Montevideo", 5);
	it[1] = Tupla<Cadena, nat>("Mercedes", 2);
	it[2] = Tupla<Cadena, nat>("Las Piedras", 3);
	Iterador<Tupla<Cadena, nat>> itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(1, 20150331, itinerario);

	it = Array<Tupla<Cadena, nat>>(6);
	it[0] = Tupla<Cadena, nat>("Río de Janeiro", 5);
	it[1] = Tupla<Cadena, nat>("Montevideo", 2);
	it[2] = Tupla<Cadena, nat>("Santiago de Chile", 3);
	it[3] = Tupla<Cadena, nat>("Cuzco", 3);
	it[4] = Tupla<Cadena, nat>("Asunción", 8);
	it[5] = Tupla<Cadena, nat>("Río de Janeiro", 2);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(1, 20150421, itinerario), ERROR, "ERROR: Ya existe una excursión con ese número.");

	it = Array<Tupla<Cadena, nat>>(1);
	it[0] = Tupla<Cadena, nat>("Montevideo", 0);
	itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(2, 20150331, itinerario);

	it = Array<Tupla<Cadena, nat>>(1);
	it[0] = Tupla<Cadena, nat>("Miami", 0);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(3, 20150331, itinerario), ERROR, "ERROR: No existe la ciudad Miami del itinerario.");

	it = Array<Tupla<Cadena, nat>>(5);
	it[0] = Tupla<Cadena, nat>("Las Piedras", 1);
	it[1] = Tupla<Cadena, nat>("Montevideo", 1);
	it[2] = Tupla<Cadena, nat>("Colonia", 1);
	it[3] = Tupla<Cadena, nat>("Buenos Aires", 1);
	it[4] = Tupla<Cadena, nat>("Cordoba", 6);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(3, 20150331, itinerario), ERROR, "ERROR: No existe la ciudad Cordoba del itinerario.");

	it = Array<Tupla<Cadena, nat>>(4);
	it[0] = Tupla<Cadena, nat>("Las Paz", 1);
	it[1] = Tupla<Cadena, nat>("Buenos Aires", 1);
	it[2] = Tupla<Cadena, nat>("Medellín", 1);
	it[3] = Tupla<Cadena, nat>("Río de Janeiro", 1);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(3, 20150331, itinerario), ERROR, "ERROR: No existe la ciudad Medellín del itinerario.");

	it = Array<Tupla<Cadena, nat>>(4);
	it[0] = Tupla<Cadena, nat>("Las Paz", 3);
	it[1] = Tupla<Cadena, nat>("Buenos Aires", 5);
	it[2] = Tupla<Cadena, nat>("Cuzco", 6);
	it[3] = Tupla<Cadena, nat>("Río de Janeiro", 13);
	itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(4, 20150331, itinerario);

	it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Auckland", 10);
	it[1] = Tupla<Cadena, nat>("New York", 21);
	it[2] = Tupla<Cadena, nat>("Oslo", 6);
	itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(5, 20150331, itinerario);

	it = Array<Tupla<Cadena, nat>>(2);
	it[0] = Tupla<Cadena, nat>("Artigas", 10);
	it[1] = Tupla<Cadena, nat>("Salto", 21);
	itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(6, 20150331, itinerario);

	it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Artigas", 2);
	it[1] = Tupla<Cadena, nat>("Salto", 1);
	it[2] = Tupla<Cadena, nat>("Paysandú", 21);
	itinerario = it.ObtenerIterador();
	Verificar(interfaz->IngExcItinerario(15, 20150331, itinerario), ERROR, "ERROR: Se sobrepasa la cantidad MAX_EXCURSIONES.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoCliente()
{
	IniciarSeccion("Ingreso Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema(90, 500, 200, 500, 50, 50, 7);
	interfaz->IngresoCliente(88888888, "Pedro", 20150519);
	interfaz->IngresoCliente(33333333, "Jose", 20150520);
	interfaz->IngresoCliente(99999999, "Martín", 20150521);
	interfaz->IngresoCliente(10101010, "Lucía", 20150523);
	interfaz->IngresoCliente(19541234, "Emilsas", 20150523);
	Verificar(interfaz->IngresoCliente(19541234, "Jesús", 20150523), ERROR, "ERROR:Ya existe un cliente con cédula de identidad 19541234.");
	Verificar(interfaz->IngresoCliente(88888888, "Marta", 20150403), ERROR, "ERROR: Ya existe un cliente con cédula de identidad 88888888.");
	Verificar(interfaz->IngresoCliente(66666666-33333333, "Francisco", 20150403), ERROR, "ERROR: Ya existe un cliente con cédula de identidad 33333333.");
	interfaz->IngresoCliente(11111111, "Francisco", 20150402);
	interfaz->IngresoCliente(12344321, "Patricia", 20150523);
	Verificar(interfaz->IngresoCliente(12344320, "Anselmo", 20150523), ERROR, "ERROR: Se sobrepasa la cantidad MAX_CLIENTES.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORCompraExcursion()
{
	IniciarSeccion("Compra Excursion", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	interfaz->IngresoCliente(88888888, "Pedro", 20150519);
	interfaz->IngresoCliente(33333333, "Jose", 20150520);
	interfaz->IngresoCliente(99999999, "Martín", 20150521);
	Array<Tupla<Cadena, nat>> it = Array<Tupla<Cadena, nat>>(3);
	it[0] = Tupla<Cadena, nat>("Montevideo", 5);
	it[1] = Tupla<Cadena, nat>("Mercedes", 2);
	it[2] = Tupla<Cadena, nat>("Las Piedras", 3);
	Iterador<Tupla<Cadena, nat>> itinerario = it.ObtenerIterador();
	interfaz->IngExcItinerario(1, 20150331, itinerario);

	Verificar(interfaz->CompraExcursion(12322,1), ERROR, "ERROR: No existe el Cliente.");
	Verificar(interfaz->CompraExcursion(0, 1), ERROR, "ERROR: No existe el Cliente.");
	Verificar(interfaz->CompraExcursion(99999999, 2), ERROR, "ERROR: No existe la Excursión.");
	Verificar(interfaz->CompraExcursion(33333333, 5), ERROR, "ERROR: No existe la Excursión.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORListadoCiudades()
{
	IniciarSeccion("Listado Ciudades", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, Iterador<pCiudad>> esperado;
	Tupla<TipoRetorno, Iterador<pCiudad>> obtenido;

	obtenido = interfaz->ListadoCiudades();
	esperado = Tupla <TipoRetorno, Iterador<pCiudad>>(ERROR, Iterador<pCiudad>());

	VerificarListadoCiudades(obtenido, esperado, "");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORListadoClientes()
{
	IniciarSeccion("Listado Clientes", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, Iterador<pCliente>> esperado;
	Tupla<TipoRetorno, Iterador<pCliente>> obtenido;

	obtenido = interfaz->ListadoClientes();
	esperado = Tupla <TipoRetorno, Iterador<pCliente>>(ERROR, Iterador<pCliente>());

	VerificarListadoClientes(obtenido, esperado, "");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORListadoExcursiones()
{
	IniciarSeccion("Listado Excursiones", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, Iterador<pExcursion>> esperado;
	Tupla<TipoRetorno, Iterador<pExcursion>> obtenido;

	obtenido = interfaz->ListadoExcursiones();
	esperado = Tupla <TipoRetorno, Iterador<pExcursion>>(ERROR, Iterador<pExcursion>());

	VerificarListadoExcursiones(obtenido, esperado, "");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORConsultaExcursion()
{
	IniciarSeccion("Consulta Excursion", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pExcursion> esperado;
	Tupla<TipoRetorno, pExcursion> obtenido;

	/*
	obtenido = interfaz->ConsultaExcursion();
	esperado = ...

	VerificarConsultaExcursion(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORConsultaCliente()
{
	IniciarSeccion("Consulta Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;

	/*
	obtenido = interfaz->ConsultaCliente();
	esperado = ...

	VerificarConsultaCliente(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORConsultaCiudad()
{
	IniciarSeccion("Consulta Ciudad", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCiudad> esperado;
	Tupla<TipoRetorno, pCiudad> obtenido;

	/*
	obtenido = interfaz->ConsultaCiudad();
	esperado = ...

	VerificarConsultaCiudad(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORMejorCliente()
{
	IniciarSeccion("Mejor Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;

	/*
	obtenido = interfaz->MejorCliente();
	esperado = ...

	VerificarMejorCliente(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoConexion()
{
	IniciarSeccion("Ingreso Conexion", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	//Verificar(interfaz->IngresoConexion(), ERROR, "Comentario");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORValidarExcursion()
{
	IniciarSeccion("Validar Excursion", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, bool> esperado;
	Tupla<TipoRetorno, bool> obtenido;

	/*
	obtenido = interfaz->ValidarExcursion();
	esperado = ...

	VerificarValidarExcursion(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORExcursionMenorCosto()
{
	IniciarSeccion("Excursion Menor Costo", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	/*
	obtenido = interfaz->ExcursionMenorCosto();
	esperado = ...

	VerificarExcursionMenorCosto(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORExcursionMenorTiempo()
{
	IniciarSeccion("Excursion Menor Tiempo", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	/*
	obtenido = interfaz->ExcursionMenorTiempo();
	esperado = ...

	VerificarExcursionMenorTiempo(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORBajaCliente()
{
	IniciarSeccion("Baja Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	//Verificar(interfaz->BajaCliente(), ERROR, "Comentario");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORViajarEntreCiudades()
{
	IniciarSeccion("Viajar Entre Ciudades", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, bool> esperado;
	Tupla<TipoRetorno, bool> obtenido;

	/*
	obtenido = interfaz->ViajarEntreCiudades();
	esperado = ...

	VerificarViajarEntreCiudades(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

Cadena CasoDePrueba::CadenaCiudadesItinerario(pExcursion exc)
{
	Cadena itinerario = "";
	Cadena separador = "-";
	Iterador<Tupla<Cadena, nat>> it = exc->ObtenerItinerario();
	
	it.Reiniciar();
	while (it.HayElemento())
	{
		itinerario += it.ElementoActual().ObtenerDato1() + separador;
		it.Avanzar();
	}
	itinerario = itinerario.SubCadena(0, itinerario.ObtenerLargo() - 1); //para sacar el último guión
	return itinerario;
}
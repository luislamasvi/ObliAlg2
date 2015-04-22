#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"

Puntero<ISistema> Inicializar(nat VELOCIDAD_OMNIBUS, nat VELOCIDAD_AVION, nat COSTO_OMNIBUS, nat COSTO_AVION, nat MAX_CIUDADES, nat MAX_EXCURSIONES, nat MAX_CLIENTES)
{
	return new Sistema(VELOCIDAD_OMNIBUS, VELOCIDAD_AVION, COSTO_OMNIBUS, COSTO_AVION, MAX_CIUDADES, MAX_EXCURSIONES, MAX_CLIENTES);
}

void main()
{
	Puntero<ConductorPrueba> cp = new ConductorPrueba();
	Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	pruebas[0] = new PruebaMemoria();
	pruebas[1] = new CasoDePrueba(Inicializar);
	pruebas[2] = pruebas[0];
	cp->CorrerPruebas(pruebas.ObtenerIterador());
	system("pause");
}

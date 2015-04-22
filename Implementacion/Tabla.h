#ifndef TABLA_H
#define TABLA_H

#include "Puntero.h"
#include "Iterable.h"
#include "Tupla.h"

typedef unsigned int nat;

template <class C, class V>
class Tabla abstract : public Iterable<Tupla<C,V>>
{
public:
	virtual ~Tabla() {}

	// Constructoras

	//pos: Borra todos los elementos de la tabla
	virtual void BorrarTodo() abstract;

	//pos: Agrega la pareja clave, valor a la tabla si la clave no existe,
	//     o actualiza el valor en caso contrario
	virtual void Agregar(const C& clave, const V& valor) abstract;
	
	//pos: Borra la pareja clave, valor con la clave indicada
	virtual void Borrar(const C& clave) abstract;
	
	// Predicados

	virtual bool Pertenece(const C& clave) const abstract;
	virtual bool EsVacio() const abstract;
	virtual bool EstaLleno() const abstract;
	
	// Selectoras

	//pre: Debe existir un elemento con clave indicada
	//pos: Devuelve el valor asociado a la clave indicada
	virtual V& Recuperar(const C& clave) const abstract;

	//pos: Retorna true sii existe un elemento con clave indicada
	//     En dicho caso, actualiza el valor con el encontrado
	virtual bool IntentarRecuperar(const C& clave, V& valor) const abstract;

	virtual nat Largo() const abstract;

	virtual Puntero<Iterador<C>> Claves() const abstract;
	virtual Puntero<Iterador<V>> Valores() const abstract;
};


#endif
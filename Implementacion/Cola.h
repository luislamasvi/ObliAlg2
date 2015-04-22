#ifndef COLA_H
#define COLA_H

template<class T>
class Cola{
public:
	//PRE: -
	//POS: Destructor
	virtual ~Cola() {}

	//PRE: La cola no esta vacia.
	//POS: Retorna el elemento que se encuentra en el comienzo de la cola.
	virtual T PrimElemento() const abstract;

	//PRE: La cola no esta vacia.
	//POS: Borra el primre elemento de la cola.
	virtual void BorrarPrim() abstract;

	//PRE: -
	//POS: Ingresa un elemento a lo ultimo de la cola.
	virtual void Insertar(const T &) abstract;

	//PRE: -
	//POS: Retorna true si la cola esta vacia
	virtual bool EsVacio() const abstract;

	//PRE: -
	//POS: Retorna true si la cola esta llena
	virtual bool EstaLLena() const abstract;

	//PRE: -
	//POS: Vacia la cola.
	virtual void Vaciar() abstract;

};

#endif
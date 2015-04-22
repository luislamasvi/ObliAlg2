#ifndef AVL_H
#define AVL_H

#include "Iterable.h"
#include "Cadena.h"

template <class T>
class AVL : public Iterable<T>{
public:
	//PRE: -
	//POS: Destructor
	virtual ~AVL(){ }

	//PRE: -
	//POS: Vacia el AVL.
	virtual void Vaciar() = 0;

	//PRE: -
	//POS: inserta el elemento e en el AVL en la posición correcta.	
	virtual bool Insertar(const T &e) = 0;
         
	//PRE: -
 	//POS: borra el elemento e del AVL.Si no lo encuentra no hace nada.
        //Utiliza el operador == del elemento e para encontrar uno igual.
	virtual void Borrar (const T &e) = 0;

	//PRE: -
	//POS: retorna true si el elemento está en el AVL, de lo contrario retorna false.
	//Utiliza el operador == del elemento e para encontrar uno igual.
	virtual bool Existe(const T &e) const = 0;

	//PRE: -
	//POS: retorna la cantidad de elementos del AVL.
	virtual nat CantNodos() const = 0;

	//PRE: existe el elemento a recuperar
	//POS: Retorna el primer elemento que sea igual a e. */
	//Utiliza el operador == del elemento e para encontrar uno igual
    virtual const T& Recuperar(const T &e) const = 0;

	


};
#endif
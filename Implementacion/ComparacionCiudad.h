#ifndef COMPARACIONCIUDAD_H
#define COMPARACIONCIUDAD_H

#include "Comparacion.h"
#include "Tupla.h"
#include "Ciudad.h"

class ComparacionCiudad: public Comparacion<Puntero<Ciudad>>{
public:
	
	~ComparacionCiudad() {}
	CompRetorno Comparar(const Puntero<Ciudad>& C1, const Puntero<Ciudad>& C2) const{
	if(C1->ObtenerNombreCiudad()==C2->ObtenerNombreCiudad()) 
			return IGUALES;
		else if(C1->ObtenerNombreCiudad()<C2->ObtenerNombreCiudad()) 
			return MENOR;
		else 
			return MAYOR;
	}
};


#endif
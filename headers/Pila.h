#ifndef PILA_H
#define PILA_h

#include "./TipoElemento.h"

#include <stdbool.h>


struct PilaRep;
typedef struct PilaRep *Pila;


Pila p_crear();

bool p_apilar(Pila p, TipoElemento te);

TipoElemento p_desapilar(Pila p);

TipoElemento p_tope(Pila p);

bool p_es_vacia(Pila p);

bool p_es_llena(Pila p);

void p_mostrar(Pila p);



#endif 
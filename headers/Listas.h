#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include "./TipoElemento.h"

struct ListaRep;
typedef struct ListaRep *Lista;

struct IteradorRep;
typedef struct IteradorRep *Iterador;


Lista l_crear();

int longitud(Lista lista);


bool l_es_vacia(Lista lista);

bool l_es_llena(Lista lista);

bool l_agregar(Lista lista, TipoElemento n);


bool l_borrar(Lista lista, int clave);

TipoElemento l_buscar(Lista lista, int clave);

bool l_insertar(Lista lista, TipoElemento n, int pos);

bool l_eliminar(Lista lista, int clave);

TipoElemento l_recuperar(Lista lista, int clave);

void l_mostrar(Lista lista);

Iterador iterador(Lista lista);

bool hay_siguiente(Iterador iterador);

TipoElemento siguiente(Iterador iterador);



#endif
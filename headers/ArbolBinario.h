#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "./Nodo.h"
#include "./TipoElemento.h"
#include <stdbool.h>

struct ArbolBinarioRep;

typedef struct ArbolBinarioRep *ArbolBinario;


ArbolBinario a_crear();

bool a_es_vacio(ArbolBinario a);

bool a_es_lleno(ArbolBinario a);

int a_cantidad_elementos(ArbolBinario a);

bool a_es_rama_nula(NodoArbol pa);

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te);

NodoArbol a_raiz(ArbolBinario a);

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te);

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te);

#endif
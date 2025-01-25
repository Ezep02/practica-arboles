#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

#include "../headers/TipoElemento.h"

struct NodoArbolRep {
    TipoElemento datos;
    struct NodoArbolRep *hd;
    struct NodoArbolRep *hi;
};

typedef struct NodoArbolRep *NodoArbol;

// crea un nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// retorna el hijo izquierdo
NodoArbol n_hi(NodoArbol nodo);

// retorna el hijo derecho 
NodoArbol n_hd(NodoArbol nodo);

// retorna el tipo elemento de un nodo
TipoElemento n_recuperar(NodoArbol nodo);

#endif 
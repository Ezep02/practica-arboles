#include "../headers/Nodo.h"
#include "../headers/TipoElemento.h"

#include <stdlib.h>

NodoArbol n_crear(TipoElemento te)
{

    NodoArbol nodo = (NodoArbol)malloc(sizeof(struct NodoArbolRep));

    nodo->datos = te;
    nodo->hd = NULL;
    nodo->hi = NULL;

    return nodo;
}

NodoArbol n_hi(NodoArbol nodo)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    else
    {
        return nodo->hi;
    }
}

NodoArbol n_hd(NodoArbol nodo)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    else
    {
        return nodo->hd;
    }
}

// retorna el TipoElemento de un nodo o devuelve null
TipoElemento n_recuperar(NodoArbol nodo){
    
    if(nodo == NULL){
        return NULL;
    }
    else {
        
        return nodo -> datos;
    }
}
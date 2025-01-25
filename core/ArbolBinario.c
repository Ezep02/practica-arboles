#include "../headers/ArbolBinario.h"
#include "../headers/TipoElemento.h"
#include "../headers/Nodo.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static const int MAX_CANT_ABB = 100;

struct ArbolBinarioRep
{
    /* data */
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinario a_crear()
{

    ArbolBinario nuevo_arbol = (ArbolBinario)malloc(sizeof(struct ArbolBinarioRep));

    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;

    return nuevo_arbol;
}

bool a_es_vacio(ArbolBinario a)
{
    return a->raiz == NULL;
}

bool a_es_lleno(ArbolBinario a)
{
    return a->cantidad_elementos == MAX_CANT_ABB;
}

int a_cantidad_elementos(ArbolBinario a)
{
    return a->cantidad_elementos;
}

bool a_es_rama_nula(NodoArbol pa)
{
    return pa == NULL;
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te)
{

    if (a->raiz != NULL)
    {
        printf("[ATENCION] Ya existe una raiz\n");
        return a->raiz;
    }

    NodoArbol nuevo_nodo = n_crear(te);

    a->raiz = nuevo_nodo;
    a->cantidad_elementos++;
    printf("[OK] Raiz establecida correctamente\n");
    return nuevo_nodo;
}

NodoArbol a_raiz(ArbolBinario a)
{
    return a->raiz;
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te)
{

    if (pa == NULL)
    {
        printf("[ERROR] Nodo no puede ser NULL\n");
        return NULL;
    }

    if (pa->hi != NULL)
    {
        printf("[ATENCION] Ya existe un hijo izquierdo establecido\n");
        return pa->hi;
    }

    NodoArbol nuevo_nodo = n_crear(te);
    // si todo va bien, proceder
    pa->hi = nuevo_nodo;
    a->cantidad_elementos++;
    return nuevo_nodo;
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te)
{

    if (pa == NULL)
    {
        printf("[ERROR] Nodo no puede ser NULL\n");
        return NULL;
    }

    if (pa->hd != NULL)
    {
        printf("[ATENCION] Ya existe un hijo derecho establecido\n");
        return pa->hd;
    }

    NodoArbol nuevo_nodo = n_crear(te);

    pa->hd = nuevo_nodo;
    a->cantidad_elementos++;
    return nuevo_nodo;
}
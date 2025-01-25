#include "../headers/Pila.h"
#include "../headers/TipoElemento.h"
#include <stdio.h>
#include <stdlib.h>

static const int MAX_PILA_CANT = 100;

struct NodoPila
{
    TipoElemento datos;
    struct NodoPila *siguiente;
};

struct PilaRep
{
    struct NodoPila *tope;
};

Pila p_crear()
{

    Pila pila_nueva = (Pila)malloc(sizeof(struct PilaRep));

    pila_nueva->tope = NULL;

    return pila_nueva;
}

bool p_apilar(Pila p, TipoElemento te)
{

    if (p_es_llena(p))
    {
        printf("[ATENCION] La pila se encuentra llena\n");
        return false;
    }

    struct NodoPila *nuevo_nodo = malloc(sizeof(struct NodoPila));

    nuevo_nodo->datos = te;
    nuevo_nodo->siguiente = p->tope;
    p->tope = nuevo_nodo;

    return true;
}

TipoElemento p_desapilar(Pila p)
{
    if (p_es_vacia(p))
    {
        printf("[ATENCION] No se puede desapilar, pila vacia\n");
        return NULL;
    }

    struct NodoPila *nodo_tope = p ->tope;
    TipoElemento te = nodo_tope->datos;

    p -> tope = nodo_tope ->siguiente;
    free(nodo_tope);
    return te;
}

TipoElemento p_tope(Pila p)
{
    if (p_es_vacia(p))
    {
        printf("[ATENCION] Pila vacia\n");
        return NULL;
    }

    struct NodoPila *nodo = p->tope;

    return nodo->datos;
}

bool p_es_vacia(Pila p)
{
    return p->tope == NULL;
}

int calcular_logintud_pila(Pila p)
{

    int i = 0;
    struct NodoPila *N = p->tope;

    while (N != NULL)
    {
        i++;
        N = N->siguiente;
    }
    return i;
}

bool p_es_llena(Pila p)
{
    return (calcular_logintud_pila(p)) == MAX_PILA_CANT;
}

void p_mostrar(Pila p)
{
    if(p_es_vacia(p)){
        printf("[ATENCION] La pila esta vacia, no hay elementos para mostrar\n");
        return;
    }   

    // creo una pila auxiliar
    Pila p_aux = p_crear();
    printf("[VALORES DE LA PILA]: ");
    while(!p_es_vacia(p)){
        TipoElemento x1 = p_desapilar(p);
        p_apilar(p_aux, x1);
        printf("%d,", x1 ->key);
    }

    // devuelvo los elementos a la pila original
    while(!p_es_vacia(p_aux)){
        p_apilar(p, p_desapilar(p_aux));
    }
}

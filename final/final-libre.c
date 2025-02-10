#include "../headers/Nodo.h"
#include "../headers/TipoElemento.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    1. Definir la declariacion de tipos para implementar un arbol binario mediante cursores (solo declarar la const y la type)
 */

static const int ARBOL_CURSOR_MAX = 100;
static const int NULO = -1;

struct NodoArbolCursor {
    TipoElemento datos;
    int hd;
    int hi;
    int siguiente;
};


struct ArbolCursorRep { 
    struct NodoArbolCursor *nodoCursor;
    int raiz;
    int libre;
    int cantidad_elementos;
};

typedef struct ArbolCursorRep *ArbolCursor;
typedef struct NodoArbolCursor *NodoCursor;
// rutinas

// crear
ArbolCursor CrearArbolCursor(){

    // asigno memoria
    ArbolCursor nuevo_arbol = (ArbolCursor)malloc(sizeof(struct ArbolCursorRep));

    // asigno memoria para el arreglo de nodos
    nuevo_arbol->nodoCursor = calloc(ARBOL_CURSOR_MAX, sizeof( struct NodoArbolCursor));


    for(int i = 0; i <= (ARBOL_CURSOR_MAX-2); i++){
        nuevo_arbol -> nodoCursor[i].siguiente = i+1;
    }

    nuevo_arbol -> raiz = NULO;  
    nuevo_arbol -> nodoCursor[ARBOL_CURSOR_MAX - 1].siguiente = NULO;
    nuevo_arbol -> cantidad_elementos = 0;
    nuevo_arbol -> libre = 0;

    return nuevo_arbol;
}

    // buscar la posicion donde alojar el nodo
    // asignarlo a el nodo correspondiente
    // alojar el nuevo nodo asignado a un espacio en el array libre

// es vacio
bool ArbolEsVacio(ArbolCursor arbol){
    return arbol->cantidad_elementos == 0;
}

// es lleno
bool ArbolEsLleno(ArbolCursor arbol){
    return arbol->cantidad_elementos == ARBOL_CURSOR_MAX;
}

bool ArbolCursorInsertarRaiz(ArbolCursor arbol, TipoElemento elemento){
    
    int p;

    if(arbol -> raiz == NULO){
        p = arbol -> libre;
        arbol ->libre = arbol ->nodoCursor[p].siguiente;

        arbol -> nodoCursor[p].datos = elemento;
        arbol ->nodoCursor[p].hd = NULO;
        arbol ->nodoCursor[p].hi = NULO;    
        arbol ->cantidad_elementos++;
        arbol ->raiz = p;
        return true;
    }

    printf("[error] Raiz previamente establecida");

    return false;
}

void CargarArbolCursor(ArbolCursor arbol, int indx, int clave){
    
    if(indx == NULO) return;

    int p;

    if(clave < arbol->nodoCursor[indx].datos->key){
        // buscar en el subarbol izquierdo
        printf("Clave sub izquierdo %d\n", arbol->nodoCursor[indx].datos->key);
        if(arbol->nodoCursor[indx].hi == NULO){
            p = arbol->libre;
            arbol ->libre = arbol ->nodoCursor[p].siguiente;

            // cargar el nuevo nodo con datos
            arbol -> nodoCursor[p].datos = te_crear(clave);
            arbol -> nodoCursor[p].hd = NULO;
            arbol -> nodoCursor[p].hi = NULO;

            // enlazar el nodo 
            arbol -> nodoCursor[indx].hi = p;
            arbol -> cantidad_elementos++;
            printf("index %d\n", indx);
            printf("Clave establecida sub izquierdo %d\n", arbol->nodoCursor[indx].hi);
        } 
        else {
            CargarArbolCursor(arbol, arbol -> nodoCursor[indx].hi, clave);
        }
    } 
    else {
        // buscar en el subarbol derecho
        printf("Clave sub derecho %d\n", arbol->nodoCursor[indx].datos->key);
        if(arbol -> nodoCursor[indx].hd == NULO){
            p = arbol -> libre;
            arbol -> libre = arbol -> nodoCursor[p].siguiente;
            
            // cargar el nuevo nodo con datos
            arbol -> nodoCursor[p].datos = te_crear(clave);
            arbol -> nodoCursor[p].hd = NULO;
            arbol -> nodoCursor[p].hi = NULO;
            
            // enlazar el nodo 
            arbol -> nodoCursor[indx].hd = p;
            arbol -> cantidad_elementos++;
            printf("index %d\n", indx);
            printf("Clave establecida sub derecho %d\n", arbol->nodoCursor[indx].hd);
        }
        else {
            CargarArbolCursor(arbol, arbol->nodoCursor[indx].hd, clave);
        }
    }
}


void IniciarFinalLibre(){

    ArbolCursor arbol = CrearArbolCursor();

    int x;
    printf("Ingrese una clave, ( 0 para salir ): ");
    scanf("%d", &x);
    
    while (x != 0){
        if(arbol->raiz == NULO){
            ArbolCursorInsertarRaiz(arbol, te_crear(x));
        } else {
            CargarArbolCursor(arbol, arbol->raiz, x);
        }

        printf("Ingrese una clave, ( 0 para salir ): ");
        scanf("%d", &x);
    }
    
}
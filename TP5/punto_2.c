#include "../core/Listas_punteros.c"
#include "../core/ArbolBinario.c"
#include "../core/Nodo.c"
#include "../core/TipoElemento.c"
#include "../core/PilaPunteros.c"

#include "../headers/tp5.h"

#include <stdio.h>

void NodosHojas(Lista lista, NodoArbol raiz);
NodoArbol CargarArbol(NodoArbol nodo, int clave);
void EncontrarNodosInteros(Lista lista, NodoArbol n_derecho, NodoArbol n_izquierdo);
Lista NodoInteriores(ArbolBinario th);
void BuscarOcurrencias(Lista lista, int clave, int *contador, NodoArbol n);
void MostrarArbol(NodoArbol nodo);

void Iniciar2A()
{

    ArbolBinario th = a_crear();

    // solicitar datos
    int x;
    printf("Cargar un elemento a el arbol: ");
    scanf("%d", &x);

    while (x != 0)
    {

        if (a_raiz(th) == NULL)
        {
            a_establecer_raiz(th, te_crear(x));
        }
        else
        {
            CargarArbol(a_raiz(th), x);
        }

        printf("Cargar un elemento a el arbol: ");
        scanf("%d", &x);
    }

    // una vez se carga, buscar los nodos hojas
    Lista nueva_lista = l_crear();

    NodosHojas(nueva_lista, a_raiz(th));

    l_mostrar(nueva_lista);
}


void Iniciar2B(){
    
    ArbolBinario th = a_crear();

    // solicitar datos
    int x;
    printf("Cargar un elemento a el arbol: ");
    scanf("%d", &x);

    while (x != 0){

        if (a_raiz(th) == NULL){
            a_establecer_raiz(th, te_crear(x));
        }
        else {
            CargarArbol(a_raiz(th), x);
        }

        printf("Cargar un elemento a el arbol: ");
        scanf("%d", &x);
    }


    Lista lista = NodoInteriores(th);
    l_mostrar(lista);
}

//TODO = Agregar muestra y carga a funciones reutilziables
NodoArbol CargarArbol(NodoArbol nodo, int clave)
{
    
    NodoArbol nuevo_nodo;

    if (nodo == NULL)
    {
        nuevo_nodo = n_crear(te_crear(clave));
    }
    else
    {

        if (clave <= nodo->datos->key)
        {
            nodo->hi = CargarArbol(nodo->hi, clave);
        }
        else if (clave >= nodo->datos->key)
        {
            nodo->hd = CargarArbol(nodo->hd, clave);
        }
    }
    return nuevo_nodo;
}

void MostrarArbol(NodoArbol nodo){

    if(nodo != NULL){
        MostrarArbol(nodo->hi);
        printf("%d ", nodo->datos->key);
        MostrarArbol(nodo->hd);
    }
}


// 2A
// Retornar una lista con todos los nodos terminales u hojas
void NodosHojas(Lista lista, NodoArbol raiz)
{

    if (raiz != NULL)
    {

        if (raiz->hi == NULL && raiz->hd == NULL)
        {
            TipoElemento x3 = n_recuperar(raiz);
            l_agregar(lista, x3);
        }

        NodosHojas(lista, raiz->hd);
        NodosHojas(lista, raiz->hi);
    }
}

// 2B
// Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
Lista NodoInteriores(ArbolBinario th)
{

    Lista lista = l_crear();

    EncontrarNodosInteros(lista, n_hd(a_raiz(th)), n_hi(a_raiz(th)));

    return lista;
}

void EncontrarNodosInteros(Lista lista, NodoArbol n_derecho, NodoArbol n_izquierdo)
{
    // solo contempla aquellos nodos que se encuentran entre la raiz y un nodo hoja

    if(n_derecho != NULL || n_izquierdo != NULL){

        if ( n_hd( n_izquierdo) != NULL){
            TipoElemento  x1 = n_recuperar(n_izquierdo);
            l_agregar(lista, x1);
        }
        else if (n_hi(n_derecho) != NULL){
            TipoElemento x2 = n_recuperar(n_derecho);
            l_agregar(lista, x2);
        }

        EncontrarNodosInteros(lista, n_derecho ->hd, n_izquierdo->hi);
        EncontrarNodosInteros(lista, n_izquierdo->hi, n_derecho ->hd);
    }
};



// 2c Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
void Iniciar2C(){

    ArbolBinario th = a_crear();

    int x, contador = 0;

    printf("Cargar un elemento a el arbol: ");
    scanf("%d", &x);

    while (x != 0){

        if (a_raiz(th) == NULL){
            a_establecer_raiz(th, te_crear(x));
        }
        else {
            CargarArbol(a_raiz(th), x);
        }

        printf("Cargar un elemento a el arbol: ");
        scanf("%d", &x);
    }   

    printf("arbol\n");
    MostrarArbol(a_raiz(th));

    Lista lista = l_crear();

    int clave_buscar;
    printf("Clave a buscar: ");
    scanf("%d", &clave_buscar);

    BuscarOcurrencias(lista, clave_buscar, &contador, a_raiz(th));

    printf("\n");
    printf("Ocurrencias\n");
    l_mostrar(lista);

}


void BuscarOcurrencias(Lista lista, int clave, int *contador, NodoArbol n){

    if(n == NULL){
        return;
    }

    if(n->datos->key == clave){
        l_agregar(lista, te_crear(*contador));
    }
    
    (*contador)++;

    BuscarOcurrencias(lista, clave, contador, n->hd);
    BuscarOcurrencias(lista, clave, contador, n->hi);
}
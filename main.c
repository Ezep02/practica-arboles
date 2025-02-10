#include <stdio.h>

// #include "./TP5/punto_2.c"
#include "./final/punto2.c"
#include "./final/punto3.c"

// NodoArbol InsertarNodo(NodoArbol raiz, int dato);
// void MostrarArbol(NodoArbol nodo);

int main()
{   
    //Iniciar2A();
    //Iniciar2B();

    // Iniciar2C();

    // ejercicios practica para final
    //IniciarPunto2();
    //IniciarPunto3();
    
    return 0;
}

// NodoArbol InsertarNodo(NodoArbol raiz, int dato)
// {

//     if (raiz == NULL)
//     {
//         NodoArbol nuevo = n_crear(te_crear(dato));
//         return nuevo;
//     }
//     else
//     {
//         printf("raiz %d\n", raiz->datos->key);

//         if (dato < raiz->datos->key)
//         {
//             raiz->hi = InsertarNodo(raiz->hi, dato);
//         }
//         else if (dato > raiz->datos->key)
//         {
//             raiz->hd = InsertarNodo(raiz->hd, dato);
//         }
//     }

//     return raiz;
// }

// void MostrarArbol(NodoArbol nodo){

//     if(nodo != NULL){
//         MostrarArbol(nodo->hi);
//         printf("%d ", nodo->datos->key);
//         MostrarArbol(nodo->hd);
//     }
// }>
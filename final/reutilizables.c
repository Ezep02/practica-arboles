#include "../core/TipoElemento.c"
#include "../core/Listas_punteros.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../headers/PracticaFinal.h"
#include "../headers/Nodo.h"

#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// funcion para cargar lista con valores STRINGS
Lista CargarStringLista(int max_cant) {
    int i;
    int char_set_len = sizeof(CHAR_SET) - 1; 
    Lista l1 = l_crear();  
    
    for (i = 0; i < max_cant; i++) {
        
       
        l_agregar(l1, te_crear_con_valor(i, (void *)&CHAR_SET[rand() % char_set_len]));   
    }

    return l1;
}

// funcion para eliminar valor de una lista
bool EliminarClaveAlfabeticaLista(Lista l1, char clave){

    if(l_es_vacia(l1)){
        printf("La lista no puede ser vacia\n");
        return false;
    }

    bool borre;

    struct Nodo *actual = l1->inicio;
    
    // preguntar si la clave se encuentra en el principio
    // (char *) --> apunta a la direccion de memoria, ex: 0x1001
    // *(char *) --> apunta a lo que se encuentra almacenado dentro de 0x1001, ex: 'H'
    // operador de desreferencia
    while (actual != NULL && *((char *)actual->datos->value) == clave){
        /* code */
        l1->inicio = actual->siguiente;
        free(actual);
        l1->cantidad--;
        actual = l1->inicio;
        borre = true;
    }
    
    // borrar en el resto de las claves 
    while(actual != NULL && actual->siguiente != NULL){

        if(*((char *)actual->siguiente->datos->value) == clave ){
           struct Nodo *temp = actual->siguiente;
           actual->siguiente = temp->siguiente;
           free(temp); 
           l1->cantidad--;
           borre=true;

        } else {
            actual = actual->siguiente;
        }
    }
    return borre;
}



#include "../headers/PracticaFinal.h"
#include "../headers/Listas.h"
#include "../headers/TipoElemento.h"

#include "./reutilizables.c"

#include <stdio.h>

/**
 2.
    Dada una lista generada al azar con valores cadena en el campo “DS”, borrar todas
    las ocurrencias de un elemento dado. El proceso será recursivo y deberá funcionar
    para cualquiera de las implementaciones vistas. NO se puede usar una lista aux
    para resolverlo.
    
    Ejemplo: si la lista contiene (A, Z, B, H, K, R, A, H, Z) y se pide eliminar “H”,
    resultado esperado: (A, Z, B, K, R, A, Z)
*/



void IniciarPunto2(){

    Lista l1 = CargarStringLista(17);
   
    Iterador ite = iterador(l1);
    TipoElemento x1;
    
    while(hay_siguiente(ite)){
        x1 = siguiente(ite);
        // elementos de la lista
        printf("%c", *(char *)x1->value);
    }   
   
    char caracter_a_borrar;
    printf("\nIngrese clave a borrar en la lista: ");
    scanf("%c", &caracter_a_borrar);

    // luego de la eliminacion
    printf("Comenzando proceso de eliminacion..\n");
    
    EliminarClaveAlfabeticaLista(l1, caracter_a_borrar);
    
    // luego de la eliminacion
    printf("Lista luego de eliminar la/s clave/s\n");
    Iterador ite2 = iterador(l1);
    while(hay_siguiente(ite2)){
        x1 = siguiente(ite2);
        printf("%c\n", *(char *)x1->value);
    }   
}  


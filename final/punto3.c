#include "../headers/Listas.h"
#include "../headers/TipoElemento.h"

#include "../headers/PracticaFinal.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  3
    dada una lista que contiene registros con nombre de ciudad (DS) y cantidad de
    habitantes (DI), se pide realizar un programa que muestre el nombre de la ciudad o
    ciudades con mayor cantidad de habitantes. Las ciudades que difieran en más o en
    menos un 10% de habitantes, se consideran iguales. Indicar complejidad algorítmica

    Por ejemplo:
     dadas 3 ciudades: A=9100 h, B=10000 h, C=11000 h → salida
     sería B y C, son las ciudades con mayor cantidad de habitantes, pues la
     cantidad de habitantes de A difieren en un 20% con respecto a C
*/

typedef struct Habitantes_ciudadRep {
    char ciudad[50];
    int cant_habitantes;
} Habitantes_ciudadRep;

typedef Habitantes_ciudadRep *Habitantes_ciudad;


Habitantes_ciudad CrearRegistro(int cant_habitantes){
    
    Habitantes_ciudad nuevo_registro = (Habitantes_ciudad) malloc(sizeof(Habitantes_ciudadRep));

    nuevo_registro->cant_habitantes = cant_habitantes;

    printf("Nombre de la ciudad: ");
    scanf("%s", nuevo_registro->ciudad);
    return nuevo_registro;
}

void IniciarPunto3(){
    Lista l1 = l_crear();
    
    int x;
    printf("Numero de ciudades: ");
    scanf("%d", &x);

    int i = 0;
    while (i < x) {
        // Crear el registro, luego cargarlo a la lista
        Habitantes_ciudad registro = CrearRegistro(rand() % 50000);
        
        l_agregar(l1, te_crear_con_valor(i, (void *)registro));
        i++;
    }
    
    Iterador ite = iterador(l1);
    TipoElemento x1;
    char ciudad_mas_h[50];
    int ciudad_mas_cant_h = 0;

    //iteramos en busqueda de la ciudad con mayor cantidad de habitantes
    while (hay_siguiente(ite)){
       
        x1 = siguiente(ite);
        Habitantes_ciudad ciudad = (void*)x1->value;
        printf("ciudad mas cant %d, ciudad %s\n", ciudad->cant_habitantes, ciudad->ciudad);

        if(ciudad->cant_habitantes >= ciudad_mas_cant_h){
            ciudad_mas_cant_h = ciudad->cant_habitantes;
            strcpy((char *)ciudad_mas_h, ciudad->ciudad);
        }
    }
    
  
    //una vez obtenido la ciudad y los habitantes, calcular porcenaje de habitantes valido
    int porcentaje_val = (ciudad_mas_cant_h * 10) / 100 ;
    printf("proc %d",porcentaje_val );
    // obtenido el porcentaje valido, recorrer la lista otra vez en busqueda de las ciudades validas
    Iterador ite2 = iterador(l1);
    TipoElemento x2;

    struct Habitantes_ciudadRep ciudades_mas_habitantes[100];
    int total_cargadas = 0;

    while (hay_siguiente(ite2)){
        
        x2 = siguiente(ite2);
        Habitantes_ciudad ciudad = (void*)x2->value;

        if(ciudad->cant_habitantes > (ciudad_mas_cant_h - porcentaje_val) && ciudad ->cant_habitantes < (ciudad_mas_cant_h + porcentaje_val)){
            // si esto ocurre, entonces la ciudad esta en el rango valido
            ciudades_mas_habitantes[total_cargadas].cant_habitantes = ciudad->cant_habitantes;
            strcpy(ciudades_mas_habitantes[total_cargadas].ciudad, ciudad->ciudad);

            total_cargadas++;
        }   
    }
    printf("Total cargados %d\n", total_cargadas);
    for(int j = 0; j < total_cargadas; j++){
        printf("ciudad: %s, cantidad de poblacion: %d\n", ciudades_mas_habitantes[j].ciudad, ciudades_mas_habitantes[j].cant_habitantes);
    }
}


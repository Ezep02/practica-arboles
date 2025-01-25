#include <stdlib.h>
#include "../headers/TipoElemento.h"


TipoElemento te_crear(int key){

  TipoElemento te = (TipoElemento)malloc(sizeof( struct TipoElementoRep));
  
  te -> key = key;
  te -> value = NULL;
  return te;
}

TipoElemento te_crear_con_valor(int key, void *value){

  TipoElemento te = (TipoElemento)malloc(sizeof(struct TipoElementoRep));

  te -> key = key;
  te -> value = value;

  return te;
}
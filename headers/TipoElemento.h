#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H

struct TipoElementoRep
{
    int key;
    void *value;
};

typedef struct TipoElementoRep *TipoElemento;

/**
 * @brief Crea un tipo elemento dada una clave
 * 
 * @param key
 * @return TipoElemento
*/

TipoElemento te_crear(int key);


/**
 * @brief Crea un tipo elemento dada una clave
 * 
 * @param key
 * @param value
 * @return TipoElemento
*/
TipoElemento te_crear_con_valor(int key, void *value);


#endif
#ifndef TP_TablaHash_H
#define TP_TablaHash_H
#include"./tabla_hash.h"
#include"./arbol-avl.h"
#include "./Listas.h"
#include <stdbool.h>
//Validaciones
bool es_flotante(char val[]);
void es_dia(int *valor);
void es_mes(int *valor);
void es_anio(int *valor);
int validacion_fecha();
void validacion_dni(int *valor);
void ingreso_nombre_y_apellido(char *palabra);
void validacion_flag(int *valor);
void validacion_cargas(int *valor);
bool es_max(int *min,int *max);
void validar_cant(int *valor);
void validar_rango_buscar(int *min,int *max,int rango_min,int rango_max);
void validar_rango(int *min, int *max);
bool sepuede(int *clave,int max,int min);
void validar_nro_claves(int *clave, int max,int min);
bool esta_en_el_rango(int *valor,int min, int max);
void validar_clave_a_buscar(int *valor,int min,int max);
void validar_ingreso(int *valor);
void l_mostrar_con_valor(Lista l);
bool esPrimo(int num);
int encontrarPrimoMayor(int clave);
int hashFunctionNroPrimo(int a);
bool existeEnLista(Lista lista, int clave);
void ingresoEntero_legajo(int *valor);
void ingresoEntero_tel(char *tel);
void validar_domicilio(int *valor);
void validacion_flag_2(int *valor);
void validacion_opcion(int *valor);
//estructura
typedef struct 
{
    bool Estado;
    int Legajo;
    char Nombre [30];
    char Apellido[30];
    int domicilio;
    char Telefono[15];
} Alumnos;
typedef struct 
{
    int dni;
    char Nombre[30];
    char Apellido[30];

} T_Vacunados;
//funciones
//punto6
T_Vacunados *crearVacunado(int dni, const char* nombre, const char* apellido);
void mostrarVacunado(const T_Vacunados* vacunado);
int FUN_hash (int pp);
void Carga_tabla(TablaHash Tabla);
//punto5
Lista generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo);
Lista generarlistaclaves_buscar(int cantidadclavesagenerar, int valorminimo, int valormaximo);
void Busqueda_hash(TablaHash Tabla);
void cargarAVL(ArbolAVL AVL, Iterador it_lis);
ArbolAVL crearAVL(Lista L);
TablaHash crear_tabla(Lista lis, int cant);
double tiempoAVL(Iterador it,ArbolAVL AVL);
double tiempoTH(Iterador it, TablaHash TH);
Lista N_comparaciones(int veces);
//punto4
int Crear_Archivo_binario();
int Ultimo_ingreso();
void Altas(int* Lugar_de_carga);
void Mostrar(int Lugar_mostrar);
void Bajas(int Lugar_mostrar);
void Modificaciones(int Lugar_de_carga);
void Mostrar_carga();
TablaHash Inicializar();
int Devolver_Posi(TablaHash Tabla, int Legajo);
#endif // TP_TablaHash_H

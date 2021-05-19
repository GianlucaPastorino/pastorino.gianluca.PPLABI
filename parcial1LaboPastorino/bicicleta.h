#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int rodado;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int menu();
void inicializarBicicletas(eBicicleta bicicletas[], int tam);
int buscarLibre(eBicicleta bicis[], int tam);
int altaBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int* pId);
void mostrarBicicleta(eBicicleta unaBici, eTipo tipos[], eColor colores[], int tamT, int tamC);
void mostrarBicicletas(eBicicleta bicis[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamC);
int buscarBicicleta(eBicicleta bicis[], int tam, int id);
int menuModificar();
int modificarBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC);
int bajaBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC);

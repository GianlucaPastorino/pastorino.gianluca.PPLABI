#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicis[], int tamB, eServicio servicios[], int tamS, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, int* pNextId);
int buscarLibreTrabajos(eTrabajo trabajos[], int tam);
void inicializarTrabajos(eTrabajo trabajos[], int tam);

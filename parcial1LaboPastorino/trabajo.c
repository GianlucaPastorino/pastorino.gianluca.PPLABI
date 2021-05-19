#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "color.h"
#include "fecha.h"
#include "tipo.h"
#include "servicio.h"
#include "bicicleta.h"
#include "inputs.h"

int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicis[], int tamB, eServicio servicios[], int tamS, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int id;
    int idServicio;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && bicis != NULL && servicios != NULL && tipos!= NULL && colores != NULL && pNextId != NULL && tamB> 0 && tamColores >0 && tamS >0 && tamTipo>0 && tamTra>0)
    {
        printf("     Alta trabajos\n");
        indice= buscarLibreTrabajos(trabajos, tamTra);
        if(indice==-1)
        {
            printf("No hay lugar para mas trabajos\n\n");
        }
        else
        {
            mostrarBicicletas(bicis, tamB, tipos, colores, tamTipo, tamColores);
            printf("Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &id);

            while(buscarBicicleta(bicis, tamB, id))
            {
                printf("No existe una bicicleta con ese ID. Reingrese ID: ");
                fflush(stdin);
                scanf("%d", &id);
            }
            nuevoTrabajo.idBicicleta=id;

            mostrarServicios(servicios, tamS);
            getNumero(&idServicio, "Ingrese ID servicio: ", "Error. ", 20000, 20003);

            nuevoTrabajo.idServicio= idServicio;

            printf("Ingrese fecha dd/mm/aaaa:");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);

            nuevoTrabajo.id = *pNextId;
            (*pNextId)++;
            nuevoTrabajo.isEmpty=0;
            trabajos[indice]= nuevoTrabajo;
            todoOk=1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajos(eTrabajo trabajos[], int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(trabajos[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        trabajos[i].isEmpty=1;
    }
}



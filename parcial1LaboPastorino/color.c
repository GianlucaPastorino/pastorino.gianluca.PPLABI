#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

void mostrarColores(eColor colores[], int tam)
{
    printf("    Lista de Colores\n");
    printf("   ID   Descripcion\n");

    for(int i = 0; i<tam; i++)
    {
        mostrarColor(colores[i]);
    }
}
void mostrarColor(eColor color)
{
    printf("   %d    %10s\n", color.id, color.nombreColor);
}

int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>=5000 && id<=5004 && colores != NULL && tam>0 && desc != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(desc, colores[i].nombreColor);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}


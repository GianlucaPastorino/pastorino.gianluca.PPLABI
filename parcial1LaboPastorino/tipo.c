#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

void mostrarTipos(eTipo tipos[], int tam)
{
    printf("    Lista de tipos\n");
    printf("   ID   Descripcion\n");

    for(int i = 0; i<tam; i++)
    {
        mostrarTipo(tipos[i]);
    }
}
void mostrarTipo(eTipo tipo)
{
    printf("   %d    %10s\n", tipo.id, tipo.descripcion);
}

int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>=1000 && id<=1003 && tipos != NULL && tam>0 && desc != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}

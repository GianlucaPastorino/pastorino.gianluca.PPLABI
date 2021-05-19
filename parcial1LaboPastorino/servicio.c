#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicios(eServicio servicios[], int tamS)
{
    printf("    Lista de Servicios\n");
    printf(" ID   Descripcion   Precio\n");

    for(int i = 0; i<tamS; i++)
    {
        mostrarServicio(servicios[i]);
    }
}

void mostrarServicio(eServicio servicio)
{
    printf("   %d    %10s   %f\n", servicio.id, servicio.descripcion, servicio.precio);
}

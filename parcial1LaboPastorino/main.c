#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "inputs.h"

#define TAMB 10
#define TAMTRABAJO 10
#define TAMTIPO 4
#define TAMCOLORES 5
#define TAMSER 4

int main()
{
    int nextIdBicicleta=100;
    int nextIdTrabajo=300;

    eTipo tipos[TAMTIPO]={{1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"}, {1003, "BMX"},};
    eColor colores[TAMCOLORES]={{5000, "Gris"}, {5001, "Negro"}, {5002, "Blanco"}, {5003, "Azul"},{5004, "Rojo"}};
    eServicio servicios[TAMSER]={{20000, "Limpieza", 250}, {20001, "Parche", 300}, {20002, "Centrado", 400}, {20003, "Cadena", 350},};
    eBicicleta bicicletas[TAMB];
    eTrabajo trabajos[TAMTRABAJO];
    inicializarBicicletas(bicicletas, TAMB);
    inicializarTrabajos(trabajos, TAMTRABAJO);

    char salir = 'n';
    do
    {
        switch(menu())
        {
        case 'a':
            if(altaBicicleta(bicicletas, TAMB, tipos, colores, TAMTIPO, TAMCOLORES, &nextIdBicicleta))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;
        case 'b':
            if(modificarBicicleta(bicicletas, TAMB, tipos, TAMTIPO, colores, TAMCOLORES))
            {
                printf("Modificacion exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar la modificacion.\n\n");
            }
            break;
        case 'c':
            if(bajaBicicleta(bicicletas, TAMB, tipos, TAMTIPO, colores, TAMCOLORES))
            {
                printf("Baja exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar la baja.\n\n");
            }
            break;
        case 'd':
            system("cls");
            mostrarBicicletas(bicicletas, TAMB, tipos, colores, TAMTIPO, TAMCOLORES);
            break;
        case 'e':
            system("cls");
            mostrarTipos(tipos, TAMTIPO);
            break;
        case 'f':
            system("cls");
            mostrarColores(colores, TAMCOLORES);
            break;
        case 'g':
            system("cls");
            mostrarServicios(servicios, TAMSER);
            break;
        case 'h':
            system("cls");
            altaTrabajo(trabajos, TAMTRABAJO, bicicletas, TAMB, servicios, TAMSER, tipos, TAMTIPO, colores, TAMCOLORES, &nextIdTrabajo);
            break;
        case 'i':
            // No me dio el tiempo.
            break;
        case 'j':
            salir = confirmar();
            break;
        default:
            printf("Opcion invalida!\n");
            break;
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

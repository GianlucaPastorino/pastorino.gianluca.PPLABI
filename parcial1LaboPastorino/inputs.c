#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int num;

    printf("%s", mensaje);
    while(scanf("%d",&num)!=1 || num<minimo || num>maximo)
    {
        fflush(stdin);
        printf("%s", mensajeError);
        printf("%s", mensaje);
    }
    *pResultado = num;
}

int arrayLetras(char cadena[])
{
    int ret=1;
    for(int i = 0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            ret = 0;
        }
    }
    return ret;
}

void validarCadenaCaracteres(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo)
{
    char auxCad[200];

    printf(mensaje);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=maximo || arrayLetras(auxCad)==0)
    {
        printf(mensajeError);
        printf(mensaje);
        fflush(stdin);
        gets(auxCad);
    }

    strcpy(cadena, auxCad);
}

char confirmar()
{
    char respuesta;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}

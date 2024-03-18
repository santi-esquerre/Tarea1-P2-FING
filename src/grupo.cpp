#include "../include/grupo.h"
#include "../include/persona.h"
#include "../include/fecha.h"
#include <iostream>
#include <cmath>
using namespace std;

struct rep_grupo
{
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */

    TPersona personas[MAX_PERSONAS];
    int tope;

    /****** Fin de parte Parte 5.1 *****/
};

TGrupo crearTGrupo()
{
    TGrupo grupo = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    grupo = new rep_grupo;
    grupo->tope = 0;

    /****** Fin de parte Parte 5.2 *****/
    return grupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor) (más viejo a más joven)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo &grupo, TPersona persona)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    if (grupo->tope == MAX_PERSONAS)
        return;

    int i = 0;

    while (i < grupo->tope && esMasJoven(persona, grupo->personas[i]))
    {
        i++;
    }

    for (int j = i; j < grupo->tope; j++)
    {
        grupo->personas[j + 1] = grupo->personas[j];
    }

    grupo->personas[i] = persona;
    grupo->tope++;

    /****** Fin de parte Parte 5.2 *****/
}

// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (grupo->tope == 0)
        return;

    for (int i = 0; i < grupo->tope; i++)
    {
        imprimirTPersona(grupo->personas[i]);
    }

    /****** Fin de parte Parte 5.2 *****/
}

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo &grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    for (int i = 0; i < grupo->tope; i++)
    {
        liberarTPersona(grupo->personas[i]);
    }
    delete grupo;
    grupo = nullptr;

    /****** Fin de parte Parte 5.2 *****/
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula)
{
    bool esta = false;
    /************ Parte 5.3 ************/
    /*Escriba el código a continuación */

    for (int i = 0; i < grupo->tope; i++)
    {
        if (cedulaTPersona(grupo->personas[i]) == cedula)
        {
            esta = true;
            break;
        }
    }

    /****** Fin de parte Parte 5.3 *****/
    return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula)
{
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */

    int i = 0;
    while (i <= grupo->tope && cedulaTPersona(grupo->personas[i]) != cedula)
    {
        i++;
    }

    if (i > grupo->tope)
        return;

    liberarTPersona(grupo->personas[i]);

    for (int j = i; j < grupo->tope - 1; j++)
    {
        grupo->personas[j] = grupo->personas[j + 1];
    }

    grupo->tope--;

    /****** Fin de parte Parte 5.4 *****/
}

// Función para encontrar la persona con la fecha de nacimiento fecha, retorna la posición de la persona en el arreglo, si no existe retorna -1
int buscarPersonaFecha(TGrupo grupo, TFecha fecha)
{
    int pos = -1;
    if (grupo->tope == 0)
        return -1;

    int inicio = 0;
    int fin = grupo->tope - 1;

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;

        if (compararTFechas(fecha, fechaNacimientoTPersona(grupo->personas[medio])) == 0)
        {
            pos = medio;
            break;
        }
        else if (compararTFechas(fecha, fechaNacimientoTPersona(grupo->personas[medio])) == 1)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    return pos;
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha)
{
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    hay = buscarPersonaFecha(grupo, fecha) != -1;

    /****** Fin de parte Parte 5.5 *****/
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha"
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha)
{
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    /*
    int pos = buscarPersonaFecha(grupo, fecha);

    if (pos == -1)
        return;

    imprimirTPersona(grupo->personas[pos]);
    */

    int i = 0;
    while (i < grupo->tope)
    {
        if (compararTFechas(fechaNacimientoTPersona(grupo->personas[i]), fecha) == 0)
        {
            imprimirTPersona(grupo->personas[i]);
        }
        i++;
    }

    /****** Fin de parte Parte 5.5 *****/
}

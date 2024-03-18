#include "../include/fecha.h"
#include <iostream>
using namespace std;

struct rep_fecha
{
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;

    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */

    nuevaFecha = new rep_fecha; // Reservamos memoria para la estructura

    // Asignamos los valores a los campos de la estructura
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;

    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */

    delete fecha;    // Liberamos la memoria reservada para la estructura
    fecha = nullptr; // Asignamos NULL al puntero

    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha)
{
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */

    // Imprimimos los campos de la estructura
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);

    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/

bool esBisiesto(nat anio)
{
    if (anio % 4 == 0)
    {
        if (anio % 100 == 0)
        {
            if (anio % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

nat diasMes(nat mes, nat anio)
{
    nat dias = 0;
    if (mes == 2) // Febrero
    {
        if (esBisiesto(anio))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) // Abril, Junio, Septiembre, Noviembre
    {
        dias = 30;
    }
    else
    {
        dias = 31;
    }
    return dias;
}

void aumentarTFecha(TFecha &fecha, nat dias)
{
    nat diasMesActual = diasMes(fecha->mes, fecha->anio);
    fecha->dia += dias;
    while (fecha->dia > diasMesActual)
    {
        fecha->dia -= diasMesActual;
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
        diasMesActual = diasMes(fecha->mes, fecha->anio);
    }
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */

    if (fecha1->anio > fecha2->anio)
    {
        res = 1;
    }
    else if (fecha1->anio < fecha2->anio)
    {
        res = -1;
    }
    else
    {
        if (fecha1->mes > fecha2->mes)
        {
            res = 1;
        }
        else if (fecha1->mes < fecha2->mes)
        {
            res = -1;
        }
        else
        {
            if (fecha1->dia > fecha2->dia)
            {
                res = 1;
            }
            else if (fecha1->dia < fecha2->dia)
            {
                res = -1;
            }
        }
    }

    /****** Fin de parte Parte 3.10 *****/
    return res;
}

/********************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 14 de noviembre de 2018
 * Resumen: Algunas funciones de recorrido de todos los elementos de un vector o
 *          tabla.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include "persona.h"
using namespace std;


/*
 * Pre:  n ≥ 0 y «T» tiene al menos «n» componentes.
 * Post: Presenta por pantalla un listado de la información de las personas de
 *       las primeras «n» componentes del vector «T», a razón de una persona
 *       por línea y añade una línea adicional en blanco.
 */
void mostrar(const Persona T[], const int n) {
    for (int i = 0; i < n; i++) {
        // Se han mostrado las personas de las primeras i-1 componentes de «T»
        mostrar(T[i]);
        cout << endl;
        // Se han mostrado las personas de las primeras «i» componentes de «T»
    }
}


/*
 * Pre:  n ≥ 0 y «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el número de solteros de las primeras «n» componentes del
 *       vector «T»
 */
int numSolteros(const Persona T[], const int n) {
   /* Aún no se ha identificado ningún soltero. */
   int cuenta = 0;
   for (int i = 0; i < n; i++) {
      /* cuenta == nº de solteros de las primeras «i» - 1 componentes de «T» */
      if (!T[i].estaCasado) {
            cuenta = cuenta + 1;
        }
      /* cuenta == nº de solteros de las primeras «i» componentes de «T» */
    }
    /* cuenta == nº de solteros de las primeras «n» componentes de «T» */
    return cuenta;
}


/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Ha devuelto la persona de más edad de entre las primeras «n»
 *       componentes del vector «T».
 */
Persona masEdad(const Persona T[], const int n) {
    // indMayor == índice de la persona de más edad;
    // incialmente: primera componente del vector «T»
    int indMayor = 0;
    for (int i = 1; i < n; i++) {
        // indMayor == índice de la persona de más edad de entre las primeras
        // «i» - 1 componentes del vector «T»
        if (esMayorQue(T[i], T[indMayor])) {
            indMayor = i;
        }
        // indMayor == índice de la persona de más edad de entre las primeras
        // «i» componentes del vector «T»
    }
    // indMayor == índice de la persona de más dedad en las primeras «n»
    // componentes de «T»
    return T[indMayor];
}

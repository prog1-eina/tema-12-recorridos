/************************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 15 de noviembre de 2022
 * Resumen: Algunas funciones de recorrido de todos los elementos de un vector.
\************************************************************************************/

#include <iostream>
#include "persona.hpp"
using namespace std;


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Escribe en la pantalla un listado de la información de las personas de las
 *       primeras «n» componentes del vector «T», a razón de una persona por línea.
 */
void mostrar(const Persona T[], const unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        // Se han mostrado las personas de las primeras i-1 componentes de «T»
        mostrar(T[i]);
        cout << endl;
        // Se han mostrado las personas de las primeras «i» componentes de «T»
    }
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Devuelve el número de casados de las primeras «n» componentes del vector «T».
 */
unsigned numCasados(const Persona T[], const unsigned n) {
   /* Aún no se ha identificado ningún soltero. */
   unsigned cuenta = 0;
   for (unsigned i = 0; i < n; i++) {
      /* cuenta == nº de casados de las primeras «i» - 1 componentes de «T» */
      if (!T[i].estaCasada) {
            cuenta = cuenta + 1;
        }
      /* cuenta == nº de casados de las primeras «i» componentes de «T» */
    }
    /* cuenta == nº de casados de las primeras «n» componentes de «T» */
    return cuenta;
}


/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Devuelve la persona de más edad de entre las primeras «n» componentes del
 *       vector «T».
 */
Persona masEdad(const Persona T[], const unsigned n) {
    // indMayor == índice de la persona de más edad;
    // inicialmente: primera componente del vector «T»
    unsigned indMayor = 0;
    for (unsigned i = 1; i < n; i++) {
        // indMayor == índice de la persona de más edad de entre las primeras
        // «i» - 1 componentes del vector «T»
        if (esMayorQue(T[i], T[indMayor])) {
            indMayor = i;
        }
        // indMayor == índice de la persona de más edad de entre las primeras
        // «i» componentes del vector «T»
    }
    // indMayor == índice de la persona de más edad en las primeras «n»
    // componentes de «T»
    return T[indMayor];
}

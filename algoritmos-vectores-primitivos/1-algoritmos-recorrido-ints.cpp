/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020
 * Resumen: Algunas funciones de recorrido de todos los elementos de un vector.
\******************************************************************************/

#include <iostream>
using namespace std;


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Presenta por pantalla un listado con los elementos de las primeras «n» 
 *       componentes del vector «T», a razón de un elemento por línea.
 */
void mostrar(const int T[], const unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        // Se han mostrado los enteros de las primeras i-1 componentes de «T»
        cout << T[i] << endl;
        // Se han mostrado los enteros de las primeras «i» componentes de «T»
    }
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el número de datos negativos de las primeras «n»
 *       componentes del vector «T».
 */
unsigned int numNegativos(const int T[], const unsigned int n) {
   /* Aún no se ha identificado ningún negativo. */
   int cuenta = 0;
   for (unsigned int i = 0; i < n; i++) {
      /* cuenta == nº de negativos de las primeras «i» - 1 componentes de «T» */
      if (T[i] < 0) {
            cuenta++;
        }
      /* cuenta == nº de negativos de las primeras «i» componentes de «T» */
    }
    /* cuenta == nº de negativos de las primeras «n» componentes de «T» */
    return cuenta;
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el máximo valor de entre los de las primeras «n»
 *       componentes del vector «T».
 */
int maximo(const int T[], const unsigned int n) {
    // indMayor == índice del dato de mayor valor;
    // inicialmente: primera componente del vector «T»
    unsigned int indMayor = 0;
    for (unsigned int i = 1; i < n; i++) {
        // indMayor == índice del dato de mayor valor de entre las primeras
        // «i» - 1 componentes del vector «T»
        if (T[i] > T[indMayor]) {
            indMayor = i;
        }
        // indMayor == índice del dato de mayor valor de entre las primeras
        // «i» componentes del vector «T»
    }
    // indMayor == índice del dato de mayor valor en las primeras «n»
    // componentes de «T»
    return T[indMayor];
}

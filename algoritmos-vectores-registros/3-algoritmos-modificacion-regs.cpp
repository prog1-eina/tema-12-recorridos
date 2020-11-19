/********************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 18 de noviembre de 2019
 * Resumen: Algunas funciones que modifican el contenido de vectores o tablas.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "persona.hpp"

/*
 * Pre:  una = A y otra = B
 * Post: una = B y otra = A
 */
void permutar (Persona &una, Persona &otra) {
    Persona aux = una;
    una = otra;
    otra = aux;
}

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Las primeras «n» componentes del vector «T» es una permutación de los
 *       datos iniciales de «T» en la que todos las personas solteras tienen un
 *       índice en la tabla menor que cualquier persona casada.
 */

void distribuir(Persona T[], const int n) {
    int inf = 0;
    int sup = n - 1;
    // Los elementos de «T» con índices en el intervalo [inf, sup], es decir,
    // [0, n-1] (o sea, todos), han de ser distribuidos
    while (inf < sup) {
        // Los ciudadadanos de «T» en los índices en [0, inf-1] son todos solteros
        // y los que están en los índices [sup + 1, n - 1] son todos casados.
        // Falta por distribuir los elementos en el intervalo [inf, sup].
        if (!T[inf].estaCasado) {
            // T[inf] está soltero; por lo tanto está bien situado,
            // al principio de la tabla.
            inf = inf + 1;
        }
        else if (T[sup].estaCasado) {
            // T[sup] está casado; por lo tanto está bien situado al final.
            sup = sup - 1;
        }
        else {
            // T[inf] está casado y T[sup] está soltero; por ello van a ser
            // permutados, para ser colocados en la parte de la tabla que les
            // corresponde.
            permutar(T[inf], T[sup]);
            inf = inf + 1;
            sup = sup - 1;
        }
        // Los ciudadadanos de «T» en los índices en [0, inf-1] son todos solteros
        // y los que están en los índices [sup + 1, n - 1] son todos casados.
        // Falta por distribuir los elementos en el intervalo [inf, sup].
    }
    // inf >= sup --> Los ciudadadanos de «T» en las componentes de índices en
    // en el intervalo [0, inf-1] son todos solteros y los que están en los
    // índices [inf, n - 1] son todos casados. Por lo tanto, todos los elementos
    // de las primeras «n» componentes del vector «T» han sido distribuidos.
}


/*
 * Pre:  n > 0 y «T» tiene al menos «n»
 *       componentes.
 * Post: El contenido de las primeras «n»
 *       componentes del vector «T» es una
 *       permutación del contenido iniciales de
 *       «T» en la que todos ellos están
 *       ordenados de forma que tienen valores
 *       del DNI crecientes.
 */
void ordenarPorDNI(Persona T[], const int n) {
    // Ordenación de una tabla por el método de selección
    for (int i = 0; i < n - 1; i++) {
        /* Las personas de las primeras i-1 componentes de «T» son las de menor
         * valor de DNI y ya están ordenadas */

        // Selección de la persona con menor valor de DNI de T[i..n-1]
        int iMenor = i;
        for (int j = i + 1; j < n; j++) {
            // T[iMenor] es el de menor DNI de T[i..j-1]
            if (T[j].nif.dni < T[iMenor].nif.dni) {
                iMenor = j;
            }
            // T[iMenor] es el de menor DNI de T[i..j]
        }
        // T[iMenor] es el de menor DNI de T[i..n-1]. Permuta T[i] y T[iMenor]
        permutar(T[i], T[iMenor]);
        /* Las personas de las primeras i-1 componentes del vector «T» son las
         * de menor valor de DNI y ya están ordenadas */
    }
}


/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: El contenido de las primeras «n» componentes del vector «T» es una
 *       permutación del contenido inicial de «T» en la que todas ellas están
 *       ordenadas de forma que cada una ha nacido en una fecha igual o anterior
 *       a la siguiente en la tabla «T».
 */
void ordenarPorEdad(Persona T[], const int n) {
    // Se ha programado un algoritmo de ordenación de una tabla por el método
    // de selección.

    // En cada iteración se permuta el elemento T[i] con el menor de los elementos
    // de T[i..n-1].
    for (int i = 0; i < n - 1; ++i) {
        // Las personas de T[0..i-1] son las de más edad y ya están ordenadas
        // según edades decrecientes.
        // Selecciona la persona de más edad de T[i..n-1].
        int iMayor = i;
        for (int j = i + 1; j < n; ++j) {
            // T[iMayor] es la persona de más edad de T[i..j-1].
            if (esMayorQue(T[j],T[iMayor])) {
                iMayor = j;
            }
            // T[iMayor] es la persona de más edad de T[i..j].
        }
        // T[iMayor] es la persona de más edad de T[i..n-1] y, por ello,
        // permuta T[i] y T[iMayor].
        permutar(T[i], T[iMayor]);
        // Las personas de T[0..i] son las de más edad y ya están ordenadas.
    }
    // Las personas de T[0..n-1] ya están ordenadas.
}


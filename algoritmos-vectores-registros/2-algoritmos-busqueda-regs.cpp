﻿/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 15 de noviembre de 2022
 * Resumen: Algunas funciones de búsqueda de información en vectores
\******************************************************************************/

#include "persona.hpp"


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo DNI es igual a «dniBuscado», devuelve 
 *       devuelto el índice de dicho elemento en el vector; si no la hay,
 *       devuelve un valor negativo.
 */
int buscar(const Persona T[], const unsigned n, const unsigned dniBuscado) {
    unsigned i = 0;
    bool encontrado = false;

    /* Búsqueda */
    while (!encontrado && i < n) {
        if (T[i].nif.dni == dniBuscado) {
            encontrado = true;
        } else {
            i = i + 1;
        }
    } // encontrado || i ≥ n

    /* Discriminación del éxito */
    if (encontrado) {
        return i;
    } else {
        return -1;
    }
}


/*
 * Pre:  «T» tiene al menos «n» componentes y los elementos de las
 *       primeras «n» componentes del vector «T» ESTÁN ORDENADOS POR VALORES DEL 
 *       DNI CRECIENTES.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo DNI es igual a «dniBuscado», entonces 
 *       devuelve el índice de dicho elemento en el vector; si no la hay, 
 *       devuelve un valor negativo.
 */
int buscarDicotomico(const Persona T[], const unsigned n, 
                     const unsigned dniBuscado) {
    if (n == 0) {
        // Si hay 0 componentes, el dato no está
        return false;
    } else {
        // Espacio de búsqueda: establecimiento en T[0..n-1]
        unsigned inf = 0;
        unsigned sup = n - 1;

        /* Búsqueda */
        // Espacio de búsqueda: T[0..n-1]
        while (inf < sup) {
            // Espacio de búsqueda: T[inf..sup]
            unsigned medio = (inf + sup) / 2;
            if (dniBuscado > T[medio].nif.dni) {
                // Espacio de búsqueda: T[medio+1..sup]
                inf = medio + 1;
            } else {
                // Espacio de búsqueda: T[inf..medio]
                sup = medio;
            }
            // Espacio de búsqueda: T[inf..sup]
        }
        // inf >= sup
        // Espacio de búsqueda: T[inf]

        /* Discriminación del éxito */
        if (T[inf].nif.dni == dniBuscado) {
            return inf;
        } else {
            return -1;
        }
    }
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una nacida en el año «agno», entonces devuelve el
 *       índice de dicho elemento en el vector; si no la hay, devuelve un valor
 *       negativo.
 */
int nacidoEn(const Persona T[], const unsigned n, const unsigned agno) {
    // Se ha programado un algoritmo de búsqueda secuencial comenzando
    // por el elemento T[0]

    // Establece el espacio inicial de búsqueda T[i..n-1], es decir, T[0..n-1]
    unsigned i = 0;
    // Por el momento no se ha encontrado lo que se busca
    bool encontrado = false;

    while (!encontrado && i < n) {
        // No ha habido éxito tras buscar en T[0..i-1]. Analiza el elemento T[i]
        if (agno == T[i].nacimiento.agno) {
            // La búsqueda debe concluir ya que T[i] es el elemento buscado
            encontrado = true;
        } else {
            // La búsqueda continúa en el espacio de búsqueda T[i+1..n-1]
            i = i + 1;
        }
    }

    // Discrimina si la búsqueda ha concluido con o sin éxito
    if (encontrado) {
        // La búsqueda ha concluido con éxito
        return i;
    } else {
        // La búsqueda ha concluido sin éxito
        return -1;
    }
}
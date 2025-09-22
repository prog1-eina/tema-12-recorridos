/******************************************************************************
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 15 de noviembre de 2022
 * Resumen: Cabeceras de las funciones de recorrido, búsqueda y modificación de
 *          vectores del tema 12.
 *****************************************************************************/

#include "persona.hpp"

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Presenta por pantalla un listado de la información de las personas de
 *       las primeras «n» componentes del vector «T», a razón de una persona
 *       por línea y añade una línea adicional en blanco.
 */
void mostrar(const Persona T[], const unsigned n);

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Devuelve el número de casados de las primeras «n» componentes del
 *       vector «T».
 */
unsigned numCasados(const Persona T[], const unsigned n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Devuelve la persona de más edad de entre las primeras «n»
 *       componentes del vector «T».
 */
Persona masEdad(const Persona T[], const unsigned n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo DNI es igual a «dniBuscado», entonces devuelve
 *       el índice de dicho elemento en el vector; si no lo hay, devuelve un
 *       dato negativo.
 */
int buscar(const Persona T[], const unsigned n, const unsigned dniBuscado);

/*
 * Pre:  n > 0, «T» tiene al menos «n» componentes y los elementos de las
 *       primeras «n» componentes del vector «T» están ordenados por valores
 *       del DNI crecientes.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo DNI es igual a «dniBuscado», entonces devuelve
 *       el índice de dicho elemento en el vector; si no lo hay, devuelve un
 *       valor negativo.
 */
int buscarDicotomico(const Persona T[], const unsigned n,
                     const unsigned dniBuscado);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenados en las primeras «n» componentes del
 *       vector «T» hay una nacida en el año «agno», entonces devuelve el
 *       índice de dicho elemento en el vector; si no la hay, devuelve un valor
 *       negativo.
 */
int nacidoEn(const Persona T[], const unsigned n, const unsigned agno);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Las primeras «n» componentes del vector «T» es una permutación de los
 *       datos iniciales de «T» en la que todos los Personas solteros tienen un
 *       índice en el vector menor que cualquier Persona casado.
 */
void distribuir(Persona T[], const unsigned n);

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
void ordenarPorDNI(Persona T[], const unsigned n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: El contenido de las primeras «n» componentes del vector «T» es una
 *       permutación del contenido inicial de «T» en la que todas ellas están
 *       ordenadas de forma que cada una ha nacido en una fecha igual o
 *       anterior a la siguiente en el vector «T».
 */
void ordenarPorEdad(Persona T[], const unsigned n);
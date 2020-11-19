/********************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 14 de noviembre de 2018
 * Resumen: Cabeceras de las funciones de recorrido, búsqueda y modificación de
 *          vectores del tema 12.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include "persona.h"

/*
 * Pre:  n ≥ 0 y «T» tiene al menos «n» componentes.
 * Post: Presenta por pantalla un listado de la información de las personas de
 *       las primeras «n» componentes del vector «T», a razón de una persona
 *       por línea y añade una línea adicional en blanco.
 */
void mostrar(const Persona T[], const int n);

/*
 * Pre:  n ≥ 0 y «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el número de solteros de las primeras «n» componentes del
 *       vector «T»
 */
int numSolteros(const Persona T[], const int n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Ha devuelto la persona de más edad de entre las primeras «n»
 *       componentes del vector «T».
 */
Persona masEdad(const Persona T[], const int n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo DNI es igual a «dniBuscado», entonces ha devuelto
 *       el índice de dicho elemento en la tabla; si no lo hay, ha devuelto un
 *       dato negativo.
 */
int buscar(const Persona T[], const int n, const int dniBuscado);

/*
 * Pre:  n > 0, «T» tiene al menos «n» componentes y los elementos de las primeras
 *       «n» componentes del vector «T» están ordenados por valores del DNI
 *       crecientes.
 * Post: Si entre las personas almacenados en las primeras «n» componentes del
 *       vector «T» hay una cuyo DNI es igual a «dniBuscado», entonces ha devuelto
 *       el índice de dicho elemento en la tabla; si no lo hay, ha devuelto un
 *       valor negativo.
 */
int buscarDicotomico(const Persona T[], const int n, const int dniBuscado);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Si entre las personas almacenados en las primeras «n» componentes del
 *       vector «T» hay una nacida en el año «agno», entonces ha devuelto el
 *       índice de dicho elemento en la tabla; si no la hay, ha devuelto un valor
 *       negativo.
 */
int nacidoEn(const Persona T[], const int n, const int agno);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: Las primeras «n» componentes del vector «T» es una permutación de los
 *       datos iniciales de «T» en la que todos los Personas solteros tienen un
 *       índice en la tabla menor que cualquier Persona casado.
 */
void distribuir(Persona T[], const int n);

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
void ordenarPorDNI(Persona T[], const int n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: El contenido de las primeras «n» componentes del vector «T» es una
 *       permutación del contenido inicial de «T» en la que todas ellas están
 *       ordenadas de forma que cada una ha nacido en una fecha igual o anterior
 *       a la siguiente en la tabla «T».
 */
void ordenarPorEdad(Persona T[], const int n);
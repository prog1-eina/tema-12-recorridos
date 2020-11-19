/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020

 * Resumen: Cabeceras de las funciones de recorrido, búsqueda y modificación de
 *          vectores del tema 12.
\******************************************************************************/

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Presenta por pantalla un listado con los elementos de las primeras «n» 
 *       componentes del vector «T», a razón de un elemento por línea.
 */
void mostrar(const int T[], const unsigned int n);

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el número de datos negativos de las primeras «n»
 *       componentes del vector «T».
 */
unsigned int numNegativos(const int T[], const unsigned int n);

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Ha devuelto el máximo valor de entre los de las primeras «n»
 *       componentes del vector «T».
 */
int maximo(const int T[], const unsigned int n);

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre los datos almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en la tabla; si no lo hay, ha
 *       devuelto un dato negativo.
 */
int buscar(const int T[], const unsigned int n, const int datoBuscado);

/*
 * Pre:  «T» tiene al menos «n» componentes y los elementos de las primeras
 *       «n» componentes del vector «T» están ordenados por valores crecientes.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en la tabla; si no lo hay, ha
 *       devuelto un valor negativo.
 */
int buscarDicotomico(const int T[], const unsigned int n, const int datoBuscado);

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Las primeras «n» componentes del vector «T» son una permutación de los
 *       datos iniciales de «T» en la que todos los datos pares tienen un
 *       índice en la tabla menor que cualquiera de los impares.
 */

void distribuir(int T[], const unsigned int n);

/*
 * Pre:  n > 0 y «T» tiene al menos «n» componentes.
 * Post: El contenido de las primeras «n» componentes del vector «T» es una
 *       permutación del contenido inicial de «T» en la que todos ellos están
 *       ordenados de forma que tienen valores del DNI crecientes.
 */
void ordenar(int T[], const unsigned int n);

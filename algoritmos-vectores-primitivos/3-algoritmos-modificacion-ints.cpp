/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020
 * Resumen: Algunas funciones que modifican el contenido de vectores.
\******************************************************************************/

/*
 * Pre:  dato1 = A y dato2 = B
 * Post: dato1 = B y dato2 = A
 */
void permutar (int& dato1, int& dato2) {
    int aux = dato1;
    dato1 = dato2;
    dato2 = aux;
}

/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Las primeras «n» componentes del vector «T» son una permutación de los
 *       datos iniciales de «T» en la que todos los datos pares tienen un
 *       índice en el vector menor que cualquiera de los impares.
 */
void distribuir(int T[], const unsigned int n) {
    int inf = 0;
    int sup = n - 1;
    // Los elementos de «T» con índices en el intervalo [inf, sup], es decir,
    // [0, n-1] (o sea, todos), han de ser distribuidos
    while (inf < sup) {
        // Los datos de «T» en los índices en [0, inf-1] son todos pares
        // y los que están en los índices [sup + 1, n - 1] son todos impares.
        // Faltan por distribuir los elementos en el intervalo [inf, sup].
        if (T[inf] % 2 == 0) {
            // T[inf] es par; por lo tanto está bien situado, al principio.
            inf = inf + 1;
        }
        else if (T[sup] % 2 != 0) {
            // T[sup] es impar; por lo tanto está bien situado al final.
            sup = sup - 1;
        }
        else {
            // T[inf] es impar y T[sup] es par; por ello van a ser permutados, 
            // para ser colocados en la parte del vector que les corresponde.
            permutar(T[inf], T[sup]);
            inf = inf + 1;
            sup = sup - 1;
        }
        // Los datos de «T» en los índices en [0, inf-1] son todos pares
        // y los que están en los índices [sup + 1, n - 1] son todas impares.
        // Faltan por distribuir los elementos en el intervalo [inf, sup].
    }
    // inf >= sup --> Los datos de «T» en las componentes de índices en
    // en el intervalo [0, inf-1] son todos pares y los que están en las
    // índices [inf, n - 1] son todos impares. Por lo tanto, todos los elementos
    // de las primeras «n» componentes del vector «T» han sido distribuidos.
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: El contenido de las primeras «n» componentes del vector «T» es una
 *       permutación del contenido inicial de «T» en la que todos ellos están
 *       ordenados de forma que tienen valores del DNI crecientes.
 */
void ordenar(int T[], const unsigned int n) {
    if (n != 0) {
        // Ordenación de un vector por el método de selección
        for (unsigned int i = 0; i < n - 1; i++) {
            /* Los datos de las primeras i-1 componentes de «T» son los de menor
            * valor y ya están ordenados. */

            // Selección del dato de menor valor de T[i..n-1]
            unsigned int iMenor = i;
            for (unsigned int j = i + 1; j < n; j++) {
                // T[iMenor] es el de menor valor de T[i..j-1]
                if (T[j] < T[iMenor]) {
                    iMenor = j;
                }
                // T[iMenor] es el de menor valor de T[i..j]
            }
            // T[iMenor] es el de menor valor de T[i..n-1]. Permuta T[i] y T[iMenor]
            permutar(T[i], T[iMenor]);
            /* Los datos de las primeras i-1 componentes del vector «T» son los
            * de menor valor y ya están ordenadas */
        }
    }
}



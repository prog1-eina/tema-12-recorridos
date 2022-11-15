/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 15 de noviembre de 2022
 * Resumen: Algunas funciones de búsqueda de información en vectores.
\******************************************************************************/


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre los datos almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en el vector; si no lo hay, ha
 *       devuelto un dato negativo.
 */
int buscar(const int T[], const unsigned n, const int datoBuscado) {
    unsigned i = 0;
    bool encontrado = false;

    /* Búsqueda */
    while (!encontrado && i < n) {
        if (T[i] == datoBuscado) {
            encontrado = true;
        }
        else {
            i = i + 1;
        }
    } // encontrado || i ≥ n

    /* Discriminación del éxito */
    if (encontrado) {
        return i;
    }
    else {
        return -1;
    }
}


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre los datos almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en el vector; si no lo hay, ha
 *       devuelto un dato negativo.
 */
int buscar2(const int T[], const unsigned n, const int datoBuscado) {
    unsigned i = 0;

    /* Búsqueda */
    while (i < n && T[i] != datoBuscado) {
            i++;
    } // i ≥ n || T[i] == datoBuscado

    /* Discriminación del éxito */
    if (i < n) {
        return i;
    }
    else {
        return -1;
    }
}

/*
 * Pre:  «T» tiene al menos «n» componentes y EN AL MENOS UNA DE ELLAS SE
         ENCUENTRA «datoBuscado».
 * Post: Devuelve el índice de una componente cuyo valor es igual a
 *       «datoBuscado».
 */
unsigned buscarGarantizado(const int T[], const int datoBuscado) {
    unsigned i = 0;

    /* Búsqueda */
    while (T[i] != datoBuscado) {
            i++;
    } // T[i] == datoBuscado

    return i;
}


/*
 * Pre:  «T» tiene al menos «n» componentes y los elementos de las 
 *       primeras «n» componentes del vector «T» ESTÁN ORDENADOS POR VALORES 
 *       CRECIENTES.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en el vector; si no lo hay, ha
 *       devuelto un valor negativo.
 */
int buscarDicotomico(const int T[], const unsigned n, 
                     const int datoBuscado) {
    if (n == 0) {
        // Si hay 0 componentes, el dato no está
        return -1;
    }
    else {
        // Espacio de búsqueda: establecimiento en T[0..n-1]
        unsigned inf = 0;
        unsigned sup = n - 1;

        /* Búsqueda */
        // Espacio de búsqueda: T[0..n-1]
        while (inf < sup) {
            // Espacio de búsqueda: T[inf..sup]
            unsigned medio = (inf + sup) / 2;
            if (datoBuscado > T[medio]) {
                // Espacio de búsqueda: T[medio+1..sup]
                inf = medio + 1;
            }
            else {
                // Espacio de búsqueda: T[inf..medio]
                sup = medio;
            }
            // Espacio de búsqueda: T[inf..sup]
        }
        // inf >= sup
        // Espacio de búsqueda: T[inf]

        /* Discriminación del éxito */
        if (T[inf] == datoBuscado) {
            return inf;
        }
        else {
            return -1;
        }
    }
}

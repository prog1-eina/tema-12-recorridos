/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos con vectores)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020
 * Resumen: Algunas funciones de búsqueda de información en vectores.
\******************************************************************************/


/*
 * Pre:  «T» tiene al menos «n» componentes.
 * Post: Si entre los datos almacenados en las primeras «n» componentes del
 *       vector «T» hay uno cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en el vector; si no lo hay, ha
 *       devuelto un dato negativo.
 */
int buscar(const int T[], const unsigned int n, const int datoBuscado) {
    unsigned int i = 0;
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
int buscar2(const int T[], const unsigned int n, const int datoBuscado) {
    unsigned int i = 0;

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
 * Pre:  «T» tiene al menos «n» componentes y en al
 *       menos una de ellas se encuentra «datoBuscado».
 * Post: Si entre los datos almacenados en las
 *       primeras «n» componentes del vector
 *       «T» hay uno cuyo valor es igual a
 *       «datoBuscado», entonces ha devuelto el
 *       índice de dicho elemento en el vector; si no
 *       lo hay, ha devuelto un dato negativo.
 */
unsigned int buscarGarantizado(const int T[], const int datoBuscado) {
    unsigned int i = 0;

    /* Búsqueda */
    while (T[i] != datoBuscado) {
            i++;
    } // T[i] == datoBuscado

    return i;
}


/*
 * Pre:  «T» tiene al menos «n» componentes, n > 0 y los elementos de las 
 *       primeras «n» componentes del vector «T» están ordenados por valores 
 *       crecientes.
 * Post: Si entre las personas almacenadas en las primeras «n» componentes del
 *       vector «T» hay una cuyo valor es igual a «datoBuscado», entonces ha
 *       devuelto el índice de dicho elemento en el vector; si no lo hay, ha
 *       devuelto un valor negativo.
 */
int buscarDicotomico(const int T[], const unsigned int n, 
                     const int datoBuscado) {
    // Espacio de búsqueda: establecimiento en T[0..n-1]
    unsigned int inf = 0;
    unsigned int sup = n - 1;

    /* Búsqueda */
    // Espacio de búsqueda: T[0..n-1]
    while (inf < sup) {
        // Espacio de búsqueda: T[inf..sup]
        unsigned int medio = (inf + sup) / 2;
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

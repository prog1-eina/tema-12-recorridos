/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos básicos con vectores)
 * Autores: Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020
 * Resumen: Programa de prueba de las funciones de recorrido de vectores
 *          programadas en este directorio.
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make ejemplo-vectores-enteros
 *       o, en Windows,
 *           mingw32-make ejemplo-vectores-enteros
 *       o ejecutar la tarea "Compilar «ejemplo-vectores-enteros»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/ejemplo-vectores-enteros
 *       o, en Windows,
 *           bin\ejemplo-vectores-enteros.exe
 *       o ejecutar la tarea "Ejecutar «ejemplo-vectores-enteros»" de VSC.
\******************************************************************************/
#include <iostream>
#include "algoritmos-vectores-enteros.hpp"
using namespace std;


/*
 * Programa de prueba de las funciones de recorrido de vectores programadas en
 * este proyecto.
 */
int main() {
    const unsigned NUM_DATOS = 0/*9*/;
    int vector[/*NUM_DATOS*/] = {3, 0, 5, -1, 2, -6, -4, 8, -9};

    cout << "DATOS DEL VECTOR" << endl;
    cout << "================" << endl;    
    mostrar(vector, NUM_DATOS);
    cout << endl;
    
    cout << "NÚMERO DE DATOS NEGATIVOS: ";
    cout << numNegativos(vector, NUM_DATOS) << endl;    
    cout << endl;

    cout << "MÁXIMO" << endl;
    cout << "===================" << endl;    
    cout << maximo(vector, NUM_DATOS) << endl;

    cout << "BÚSQUEDAS" << endl;
    cout << "=========" << endl;
    int indice = buscar(vector, NUM_DATOS, -4);
    if (indice >= 0) {
        cout << "El dato " << -4 << " está en el índice: " << indice << endl;
    }
    else {
        cout << "Parece que la función «buscar» no funciona bien." << endl;
    }
    cout << endl;

    indice = buscar(vector, NUM_DATOS, 7);
    if (indice < 0) {
        cout << "El dato " << 7 << " no está en el vector" << endl;
    }
    else {
        cout << "Parece que la función «buscar» no funciona bien." << endl;
    }
    cout << endl;

    cout << "ORDENACIÓN Y BÚSQUEDA DICOTÓMICA" << endl;
    cout << "================================" << endl;
    ordenar(vector, NUM_DATOS);
    cout << "DATOS DEL VECTOR ORDENADO" << endl;
    mostrar(vector, NUM_DATOS);
    cout << endl;
    
    indice = buscarDicotomico(vector, NUM_DATOS, -4);
    if (indice >= 0) {
        cout << "El dato " << -4 << " está en el índice: " << indice << endl;
    }
    else {
        cout << "Parece que la función «buscarDicotomico» no funciona bien." << endl;
    }
    cout << endl;

    indice = buscarDicotomico(vector, NUM_DATOS, 7);
    if (indice < 0) {
        cout << "El dato " << 7 << " no está en el vector" << endl;
    }
    else {
        cout << "Parece que la función «buscarDicotomico» no funciona bien." << endl;
    }
    cout << endl;
    
    cout << "DISTRIBUCIÓN" << endl;
    cout << "============" << endl;
    distribuir(vector, NUM_DATOS);
    cout << "DATOS DEL VECTOR DISTRIBUIDO" << endl;
    mostrar(vector, NUM_DATOS);
    cout << endl;

    return 0;
}

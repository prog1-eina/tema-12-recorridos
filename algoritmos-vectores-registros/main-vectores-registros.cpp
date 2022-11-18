/******************************************************************************\
 * Curso de Programación 1. Tema 12 (Algoritmos básicos con vectores)
 * Autores: Miguel Ángel Latre
 * Última revisión: 19 de noviembre de 2020
 * Resumen: Programa de prueba de las funciones de recorrido de vectores
 *          programadas en este proyecto.
 * Dependencias: módulos «nif», «fecha» y «persona», ubicado en el directorio
 *               del repositorio del tema 11 (registros).
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make ejemplo-vectores-registros
 *       o, en Windows,
 *           mingw32-make ejemplo-vectores-registros
 *       o ejecutar la tarea "Compilar «ejemplo-vectores-registros»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/ejemplo-vectores-registros
 *       o, en Windows,
 *           bin\ejemplo-vectores-registros.exe
 *       o ejecutar la tarea "Ejecutar «ejemplo-vectores-registros»" de VSC.
\******************************************************************************/
#include <iostream>
#include "persona.hpp"
#include "algoritmos-vectores-registros.hpp"
using namespace std;


/*
 * Programa de prueba de las funciones de recorrido de vectores programadas en
 * este proyecto.
 */
int main() {
    const unsigned NUM_DATOS = 9;
    Persona ganadoresPremioCervantes[NUM_DATOS] = {
            {"Joan",        "Margarit i Consarnau", {3297388, 'Q'}, {11,  5, 1938}, false}, 
            {"Eduardo",     "Mendoza Garriga",      { 195326, 'X'}, {11,  1, 1943}, false}, 
            {"Juan",        "Goytisolo",            {3678970, 'M'}, { 5,  1, 1931}, false}, 
            {"Ana María",   "Matute Ausejo",        { 824677, 'N'}, {26,  7, 1925}, true}, 
            {"Juan",        "Marsé Carbó",          {1041468, 'M'}, { 8,  1, 1933}, false}, 
            {"Camilo José", "Cela y Trulock",       {2758574, 'T'}, {11,  5, 1916}, false}, 
            {"Mario",       "Vargas Llosa",         {4677522, 'N'}, {28,  3, 1936}, false}, 
            {"Miguel",      "Delibes Setién",       { 801649, 'F'}, {17, 10, 1920}, false}, 
            {"María",       "Zambrano Alarcón",     {4662531, 'V'}, {22,  4, 1904}, true}
    };
    // NIF y estado civil no reales, resto de datos obtenidos de Wikipedia (https://es.wikipedia.org/)

    cout << "DATOS DEL VECTOR" << endl;
    cout << "================" << endl;    
    mostrar(ganadoresPremioCervantes, NUM_DATOS);
    cout << endl;
    
    cout << "NÚMERO DE PERSONAS CASADAS: ";
    cout << numCasados(ganadoresPremioCervantes, NUM_DATOS) << endl;    
    cout << endl;

    cout << "PERSONA DE MÁS EDAD" << endl;
    cout << "===================" << endl;    
    mostrar(masEdad(ganadoresPremioCervantes, NUM_DATOS));
    cout << endl;

    cout << "BÚSQUEDAS" << endl;
    cout << "=========" << endl;
    int indice = buscar(ganadoresPremioCervantes, NUM_DATOS, 824677);
    if (indice >= 0) {
        cout << "La persona con DNI " << 824677 << " es:" << endl;
        mostrar(ganadoresPremioCervantes[indice]);
    }
    else {
        cout << "Parece que la función «buscar» no funciona bien." << endl;
    }
    cout << endl;

    indice = buscar(ganadoresPremioCervantes, NUM_DATOS, 12345678);
    if (indice < 0) {
        cout << "No hay ninguna persona con DNI " << 12345678 << '.' << endl;
    }
    else {
        cout << "Parece que la función «buscar» no funciona bien." << endl;
    }
    cout << endl;

    indice = nacidoEn(ganadoresPremioCervantes, NUM_DATOS, 1933);
    if (indice >= 0) {
        cout << "Una persona nacida en " << 1933 << " es:" << endl;
        mostrar(ganadoresPremioCervantes[indice]);
    }
    else {
        cout << "Parece que la función «nacidoEn» no funciona bien." << endl;
    }
    cout << endl;

    cout << "ORDENACIÓN POR DNI Y BÚSQUEDA DICOTÓMICA" << endl;
    cout << "========================================" << endl;
    ordenarPorDNI(ganadoresPremioCervantes, NUM_DATOS);
    cout << "DATOS DEL VECTOR ORDENADO POR DNI" << endl;
    mostrar(ganadoresPremioCervantes, NUM_DATOS);
    cout << endl;
    
    indice = buscarDicotomico(ganadoresPremioCervantes, NUM_DATOS, 801649);
    if (indice >= 0) {
        cout << "La persona con DNI " << 801649 << " es:" << endl;
        mostrar(ganadoresPremioCervantes[indice]);
    }
    else {
        cout << "Parece que la función «buscarDicotomico» no funciona bien." << endl;
    }
    cout << endl;

    indice = buscarDicotomico(ganadoresPremioCervantes, NUM_DATOS, 87654321);
    if (indice < 0) {
        cout << "No hay ninguna persona con DNI " << 87654321 << '.' << endl;
    }
    else {
        cout << "Parece que la función «buscarDicotomico» no funciona bien." << endl;
    }
    cout << endl;
    
    cout << "ORDENACIÓN POR EDAD" << endl;
    cout << "===================" << endl;
    ordenarPorEdad(ganadoresPremioCervantes, NUM_DATOS);
    cout << "DATOS DEL VECTOR ORDENADO POR EDAD" << endl;
    mostrar(ganadoresPremioCervantes, NUM_DATOS);
    cout << endl;
    
    cout << "ACCESO DIRECTO A LAS PERSONAS DE MAYOR Y MENOR EDAD:" << endl;
    cout << "La persona de más edad es:" << endl;
    mostrar(ganadoresPremioCervantes[0]);
    cout << endl;
    
    cout << "La persona de menos edad es:" << endl;
    mostrar(ganadoresPremioCervantes[NUM_DATOS - 1]);

    return 0;
}

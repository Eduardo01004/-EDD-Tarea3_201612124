#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

class NodoABB
{
    public:
        NodoABB();
        string nombre;
        NodoABB(string);
        NodoABB *izquierdo;
        NodoABB *derecho;
};

#endif // NODOABB_H

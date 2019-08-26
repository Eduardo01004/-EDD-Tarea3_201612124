#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <iostream>
#include <string.h>
#include "NodoABB.h"

class ArbolABB
{
    public:
        ArbolABB();
        NodoABB *raiz;
        void Crear(string);
        NodoABB* Insertar(NodoABB *,NodoABB *);
        void GraficarInOrden();
        void HacerInorden(NodoABB * raiz,FILE* stream);
        int vacio(NodoABB*);
        NodoABB *borrar(NodoABB*, string);
        void borrar1(string);
};

#endif // ARBOLABB_H

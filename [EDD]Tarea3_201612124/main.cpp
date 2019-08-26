#include <iostream>
#include "ArbolABB.h"
using namespace std;
ArbolABB *arbol=new ArbolABB();

int main()
{
    arbol->Crear("luigi");
    arbol->Crear("hammer");
    arbol->Crear("mario");
    arbol->Crear("fermin");
    arbol->Crear("shy_guy");
    arbol->Crear("edd");
    arbol->Crear("Boo");
    arbol->Crear("Kamek");
    arbol->Crear("star");
    arbol->Crear("whomp");
    arbol->borrar1("shy_guy");
    arbol->borrar1("mario");
    arbol->GraficarInOrden();

    return 0;
}

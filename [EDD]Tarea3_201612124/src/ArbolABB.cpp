#include "ArbolABB.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>

ArbolABB::ArbolABB()
{
    raiz=NULL;
}

void ArbolABB::Crear(string nombre){
    NodoABB* nuevo = new NodoABB(nombre);
	raiz=Insertar(raiz,nuevo);
}

NodoABB* ArbolABB::Insertar(NodoABB *p,NodoABB *q){
	if(p==NULL) p=q;
	else{
		if(q->nombre.compare(p->nombre) < 0)
		p->izquierdo=Insertar(p->izquierdo,q);
		else
		p->derecho=Insertar(p->derecho,q);
	}
	return p;
}

void ArbolABB::GraficarInOrden()
{
    FILE *archivo;
    archivo=fopen("Arbol.dot","w");
    fprintf(archivo, "digraph ArbolABB {\n rankdir=TB;\n");
    fprintf(archivo," graph [splines=ortho, nodesep=0.5];\n");
    fprintf(archivo,"node [shape = record, style=filled, fillcolor=seashell2,width=0.7,height=0.2];\n");
    HacerInorden(raiz,archivo);
    fprintf(archivo, "}\n");
    fclose(archivo);
    system("dot -Tjpg Arbol.dot -o Arbol.jpg");
    system(" Arbol.jpg");
}

void ArbolABB::HacerInorden(NodoABB * raiz,FILE* stream){

    if(raiz != NULL){
        HacerInorden(raiz->izquierdo,stream);
        fprintf(stream,"%s[ label=\"<C0>|Nombre:%s|<C1>\"];\n",raiz->nombre.c_str(),raiz->nombre.c_str());
        if (raiz->derecho != NULL){

            fprintf(stream, "%s -> %s;\n ",raiz->nombre.c_str(),raiz->derecho->nombre.c_str());
        }
        if (raiz->izquierdo != NULL){
            fprintf(stream, "%s -> %s;\n ",raiz->nombre.c_str(),raiz->izquierdo->nombre.c_str());
        }
        HacerInorden(raiz->derecho,stream);
    }

}
int ArbolABB::vacio( NodoABB *h )
{

	int r=0;
	if( !h ) r=1;;
	return r;
}
void ArbolABB::borrar1(std::string q){
	raiz=borrar(raiz,q);
}

NodoABB* ArbolABB::borrar( NodoABB *q, std::string num )
{

	if(q->nombre == num )
	{
		NodoABB *p, *p2;

		if( vacio(q) )
		{
			free( q);
			q= NULL;
			return q;
		}
		else if(q->izquierdo==NULL )
		{
			p= q->derecho;
			free( q );
			return p;
		}
		else if( q->derecho==NULL )
		{
			p= q->izquierdo;
			free( q);
			return p;
		}
		else
		{
			p= q->derecho;
			p2= q->derecho;
			while( p->izquierdo) p= p->izquierdo;
			p->izquierdo= q->izquierdo;
			free( q );
			return p2;
		}
	}
	else if( num.compare(q->nombre) < 0 )
	q->izquierdo= borrar( q->izquierdo, num );
	else
	q->derecho= borrar(  q->derecho ,num );
	return q;
}

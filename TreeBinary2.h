/*
  Name: TreeBinaryV2.h
  Copyright: (C) Marzo  de 2013
  Author:  Jose Ferdel Dorantes Lara
  Date: 30/05/13 09:03
  Description: ----

Copyright (C) 2013  Jose Ferdel Dorantes Lara

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


  Para usar esta libreria es nesario usar un limite en los TypeTrees
 TreeBinary <Tipo de dato,numero entero> a;
*/
#include <iostream>
using namespace std;
 /*Definir el tipo de dato en la libreria es obligatorio

Para poder crear nuevas funciones externas se usa
TypeTree <T> *arbol //cambiando el tipo de dato al que se usa en el arbol
 Definir el tipo de dato en la libreria es obligatorio
 Nombre:
  TypeTree ->Nodo
  Type -> Arbol
  tree ->arbol por default
  Funciones:
  get :recupera el valor de nodo
  add :agrega al arbol
  remove:elimina nodo

 */
 template <class T>struct TypeTree{ //Nombre del nodo
   	T dato;
    struct TypeTree *der,*izq;
};
template <class T,int n1>
class TreeBinary{
char resp;
public:
    typedef struct TypeTree <T> *Type; //type crea el nodo
    Type tree;
TreeBinary(){
       tree = NULL;
       }
int size(){
int x=0;
size(tree,x);
return x;
}
void size(Type arbol,int &x){
   if(arbol!=NULL){
   x++;
   size(arbol->izq,x);
    size(arbol->der,x);
   }
}
T get(Type arbol){
    return arbol->dato;
   }
int find(T x){
    int x1=-1;
     find(tree,x,x1);
     return x1;
   }
int find(Type arbol,T x,int &x1){
     if(arbol!=NULL){
         if(x<arbol->dato){find(arbol->izq,x,x1);}
         if(x>arbol->dato) {find(arbol->der,x,x1);}
        if(arbol->dato==x){x1=1;return 1;};
     }
}
void Create(Type &arbol,T x){
     Type Nodo = new struct TypeTree<T>;
     Nodo->dato = x;
     Nodo->izq = NULL;
     Nodo->der = NULL;
     arbol=Nodo;
   }
void add(Type &arbol,T x){
      if(arbol==NULL){
           Create(arbol,x);
     }
     else if(x < arbol->dato)
          add(arbol->izq, x);
     else if(x > arbol->dato)
          add(arbol->der, x);
          }
void add(T x){
      add(tree,x);
     }
void preOrden(Type arbol,T cap[],int &x){
     if(arbol!=NULL){
          cap[x]=arbol->dato;x++;
          preOrden(arbol->izq,cap,x);
          preOrden(arbol->der,cap,x);
     }
}
void preOrden(T cap[]){
    int x=0;
preOrden(tree,cap,x);
}
void inOrden(Type arbol,T cap[],int &x){
     if(arbol!=NULL){
          inOrden(arbol->izq,cap,x);
          cap[x]=arbol->dato;x++;
          inOrden(arbol->der,cap,x);
     }
}
void inOrden(T cap[]){
    int x=0;
      inOrden(tree,cap,x);
}
void postOrden(Type arbol,T cap[],int &x){
     if(arbol!=NULL){
          postOrden(arbol->izq,cap,x);
          postOrden(arbol->der,cap,x);
          cap[x]=arbol->dato;x++;
     }
}
void postOrden(T cap[]){
         int x=0;
      postOrden(tree,cap,x);
     }
void remove(T x){
       int elem2=size();
       T *array;
       array = new T [elem2];
       preOrden(array);
       tree=NULL;
       for(int cont=0;cont<elem2;cont++){
           if(array[cont]!=x){add(array[cont]);}
       }
       delete[] array;
}
void swing(){
    int ta=size(),t=size();
    T *array;
    array = new T [ta];
    inOrden(array);
    if(ta%2==0){ta=(ta/2)-1;}
    else{ta=((ta-1)/2);}
    tree=NULL;
    add(array[ta]);
     for(ta=0;ta<t;ta++){
        add(array[ta]);
       }
    delete[] array;
}
void show(Type arbol){
     if(arbol!=NULL){
          show(arbol->izq);
          cout<<arbol->dato<<"  ";
          show(arbol->der);
     }
}
void show(){
      show(tree);
}
~TreeBinary(){
    delete tree;
   }
};


/*
  Name: Pila.h
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
  */
/*
 Pila <Tipo de dato> a;
*/
#include <iostream>
using namespace std;
template <class T>
class Pila
{
struct nodo{T nropila;nodo *sgtepila;};
int lim;
public:
typedef  nodo *TPila;
TPila pila;
Pila(){pila = NULL;lim=0;}
unsigned short size()
{
    return lim;
}
void push(T valor)
{
    TPila t, q = new(struct nodo);
	lim++;
    q->nropila  = valor;
    q->sgtepila = NULL;
	if(pila==NULL)
    {pila = q;}
    else
    {
    t = pila;
        while(t->sgtepila!=NULL){t = t->sgtepila;}
    t->sgtepila = q;
    }
}
void showall()
{
TPila q = pila;
     unsigned short i = 0;
     while(q != NULL)
     {
          cout <<"\n["<<i<<","<<q->nropila<<"]";
          q = q->sgtepila;
          i++;
     }
}
T show(unsigned short pos)
{
TPila q = pila;
   unsigned short i =0;
     while(q != NULL)
     {
          if(i==pos){return q->nropila;}
          q = q->sgtepila;
          i++;
     }

}
signed short search(T valor)
{
   TPila q = pila;
   unsigned short i = 0;
while(q!=NULL)
    {if(q->nropila==valor)
        {return i;}
        q = q->sgtepila;i++;}
    return -1;
}
T pop()
{
    if(size()==0){cout<<"Pila Vacia";}
    else{
   TPila q = pila;
    T d;
	lim--;
 while(q!=NULL){d=q->nropila;q = q->sgtepila;}
    popaux(d);
    return d;}
}
void popaux(T valor)// x q 2 pops? @.@
{
    TPila p, ant;
    p = pila;
    unsigned short i=0;
    if(pila!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nropila==valor&&i==lim)
            {
                if(p==pila){pila = pila->sgtepila;}
                else{ant->sgtepila = p->sgtepila;}
                delete(p);
                return;
            }
            i++;
            ant = p;
            p = p->sgtepila;
        }
    }
    else
        {cout<<" Pila vacia..!";}

}
~Pila()
	{
	delete pila;
	}
};
template <class T>
void push(T p[],T elemento,int &tope){
if(tope>=0)p[tope++]=elemento;
}
template <class T>
T pop(T p[],int &tope){
if(tope>=0){tope--;
return p[tope];}
}
template <class T>
void show(T p[],int tope){
for(int x=0;x<tope;x++){
cout<<p[x]<<endl;
	}
}

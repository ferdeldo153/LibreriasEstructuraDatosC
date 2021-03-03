/*
  Name: Cola.h
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
 Cola <Tipo de dato> a;
*/
#include <iostream>
using namespace std;
template <class T>
class Cola
{
struct nodo{T nrocola;nodo *sgtecola;};
int lim;
public:
typedef nodo *TCola;
TCola cola;
Cola(){
  cola = NULL;
  lim=0;
}
int size()
{
 return lim;
}
void push(T valor)
{
    TCola t, q = new(nodo);
	lim++;
    q->nrocola  = valor;
    q->sgtecola = NULL;
	if(cola==NULL)
    {cola = q;}
    else
    {
    t = cola;
        while(t->sgtecola!=NULL){t = t->sgtecola;}
    t->sgtecola = q;
    }
}
void showall()
{
TCola q = cola;
    unsigned short i = 0;
     while(q != NULL)
     {
          cout <<"\n["<<i<<","<<q->nrocola<<"]";
          q = q->sgtecola;
          i++;
     }
}
T show(unsigned short pos)
{
TCola q = cola;
     unsigned short i=0;
     while(q != NULL)
     {
          if(i==pos){return q->nrocola;}
          q = q->sgtecola;
          i++;
     }
}
signed short search(T valor)
{
   TCola q = cola;
   unsigned short i=0;
while(q!=NULL)
    {if(q->nrocola==valor)
        {return i;}
        q = q->sgtecola;i++;}
return -1;
}
T pop()
{
   if(size()==0){cout<<"Cola Vacia";}
   else {
   TCola q = cola;
    T d;
	lim--;
d=q->nrocola;
    popaux(d);
    return d;
   }
}
void popaux(T valor)
{
    TCola p, ant;
    p = cola;
    unsigned short i=0;
    if(cola!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nrocola==valor&&i==0)
            {
                if(p==cola){cola = cola->sgtecola;}
                else{ant->sgtecola = p->sgtecola;}
                delete(p);
                return;
            }
            i++;
            ant = p;
            p = p->sgtecola;
        }
    }
    else
    {cout<<" Cola vacia..!";}
   }
   ~Cola()
   {
   delete cola;
   }
};
template <class T>
void cpush(T p[],T elemento,int &tope){if(tope>=0)p[tope++]=elemento;}
template <class T>
T cpop(T c[],T &tope){int y=c[0];for(int x=0;x<tope-1;x++){c[x]=c[x+1];}tope--;return y;}
